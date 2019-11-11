#include"GameL\DrawTexture.h"
#include"GameL\WinInputs.h"
#include"GameL\SceneManager.h"
#include"GameL\HitBoxManager.h"

#include"GameHead.h"
#include"LockEnemy2.h"

using namespace GameL;

CObjLockEnemy2::CObjLockEnemy2(float x, float y)
{
	m_ex = x;
	m_ey = y;
}
void CObjLockEnemy2::Init()
{
	m_vy = 0;
	m_vx = 0;
	m_ani_time = 0;
	m_ani_frame = 0;
	m_posture = 0;

	m_hit_up = false;
	m_hit_down = false;
	m_hit_left = false;
	m_hit_right = false;

	m_hp = 10;


	Hits::SetHitBox(this, m_ex, m_ey, 64, 64, ELEMENT_ENEMY, OBJ_LOCKENEMY2, 1);
}

void CObjLockEnemy2::Action()
{
	CObjBlock2*block2 = (CObjBlock2*)Objs::GetObj(OBJ_BLOCK2);
	m_ani_time++;
	if (m_ani_time > 120)
	{
		m_ani_time = 0;

		CObjNormalBullet*objNB = (CObjNormalBullet*)Objs::GetObj(OBJ_NORMAL_BULLET);
		CObjNormalBullet*objbullet = new CObjNormalBullet(m_ex, m_ey);
		Objs::InsertObj(objbullet, OBJ_NORMAL_BULLET, 10);
	}

	//ブロック情報を持ってくる


	//ブロックとの当たり判定実行
	block2->BlockHit2(&m_ex, &m_ey, false,
		&m_hit_up, &m_hit_down, &m_hit_left, &m_hit_right,
		&m_vx, &m_vy);


	//HitBoxの位置の変更
	CHitBox*hit = Hits::GetHitBox(this);
	hit->SetPos(m_ex + block2->GetScroll(), m_ey);

	if (hit->CheckElementHit(ELEMENT_ATTACK) == true)
	{
		m_hp -= 5;
	}

	if (m_hp <= 0)
	{
		this->SetStatus(false);//自身に削除命令を出す
		Hits::DeleteHitBox(this);//保有するHitBoxに削除する
	}
}
void CObjLockEnemy2::Draw()
{
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src;
	RECT_F dst;


	//ブロック情報を持ってくる
	CObjBlock2*block2 = (CObjBlock2*)Objs::GetObj(OBJ_BLOCK2);

	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 64.0f;
	src.m_bottom = 64.0f;

	//
	dst.m_top = 0.0f + m_ey;
	dst.m_left = 64 - 64.0f + m_ex + block2->GetScroll();
	dst.m_right = 64.0f + m_ex + block2->GetScroll();
	dst.m_bottom = 64.0f + m_ey;


	//
	Draw::Draw(4, &src, &dst, c, 0.0f);
}