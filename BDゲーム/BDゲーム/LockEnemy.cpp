#include"GameL\DrawTexture.h"
#include"GameL\WinInputs.h"
#include"GameL\SceneManager.h"
#include "GameL\HitBoxManager.h"

#include"GameHead.h"
#include"LockEnemy.h"

using namespace GameL;

CObjLockEnemy::CObjLockEnemy(float x, float y)
{
	m_ex = x;
	m_ey = y;
}
void CObjLockEnemy::Init()
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


	Hits::SetHitBox(this, m_ex, m_ey, 64, 64, ELEMENT_ENEMY, OBJ_LOCKENEMY, 1);
}

void CObjLockEnemy::Action()
{
	CObjBlock*block = (CObjBlock*)Objs::GetObj(OBJ_BLOCK);
	m_ani_time++;
	if (m_ani_time > 80)
	{
		m_ani_time = 0;

		CObjNormalBullet*objNB = (CObjNormalBullet*)Objs::GetObj(OBJ_NORMAL_BULLET);
			CObjNormalBullet*objbullet = new CObjNormalBullet(m_ex, m_ey);
			Objs::InsertObj(objbullet, OBJ_NORMAL_BULLET, 10);
		
		
	}
	
	//ブロック情報を持ってくる


	//ブロックとの当たり判定実行
	block->BlockHit(&m_ex, &m_ey, false,
		&m_hit_up, &m_hit_down, &m_hit_left, &m_hit_right,
		&m_vx, &m_vy);

	
	//HitBoxの位置の変更
	CHitBox*hit = Hits::GetHitBox(this);
	hit->SetPos(m_ex + block->GetScroll(), m_ey);

	if (hit->CheckElementHit(ELEMENT_ATTACK) == true)
	{
		m_hp -= 1;
	}

	if (m_hp <= 0)
	{
		this->SetStatus(false);//自身に削除命令を出す
		Hits::DeleteHitBox(this);//保有するHitBoxに削除する
	}
}
void CObjLockEnemy::Draw()
{
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src;
	RECT_F dst;


	//ブロック情報を持ってくる
	CObjBlock*block = (CObjBlock*)Objs::GetObj(OBJ_BLOCK);

	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 64.0f;
	src.m_bottom = 64.0f;

	//
	dst.m_top = 0.0f + m_ey;
	dst.m_left = 64-64.0f+ m_ex + block->GetScroll();
	dst.m_right =  64.0f + m_ex + block->GetScroll();
	dst.m_bottom = 64.0f + m_ey;


	//
	Draw::Draw(4, &src, &dst, c, 0.0f);
}