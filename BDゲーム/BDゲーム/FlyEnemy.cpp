#include"GameL\DrawTexture.h"
#include"GameL\WinInputs.h"
#include"GameL\SceneManager.h"
#include "GameL\HitBoxManager.h"

#include"GameHead.h"
#include"FlyEnemy.h"

using namespace GameL;

CObjFlyEnemy::CObjFlyEnemy(float x, float y)
{
	m_px = x;
	m_py = y;
}

void CObjFlyEnemy::Init()
{
	
	m_ani_time = 0;
	m_ani_frame = 0;
	m_posture = 1;

	m_vx = 0.0f;
	m_vx = 0.0f;
	m_time = 0;
	m_hit_up = false;
	m_hit_down = false;
	m_hit_left = false;
	m_hit_right = false;
	m_time_flat = 0;
	count = 0;
	m_hp = 10;
	Hits::SetHitBox(this, m_px, m_py, 64, 64, ELEMENT_ENEMY, OBJ_FLYENEMY, 1);
}
void CObjFlyEnemy::Action()
{
	m_time++;

	if (m_time < 100)
	{
		m_vx = -1.0f;
	}
	if (m_time > 100)
	{
		m_vx = 1.0f;
	}
	if (m_time > 200)
	{
		m_time = 0;
	}
	if (count < 3)
	{
		m_time_flat++;
		if (m_time_flat > 20)
		{
			CObjAssaultBullet*objAB = (CObjAssaultBullet*)Objs::GetObj(OBJ_ASSAULT_BULLET);
			CObjAssaultBullet*objABullet = new CObjAssaultBullet(m_px, m_py);
			Objs::InsertObj(objABullet, OBJ_ASSAULT_BULLET, 10);
			count++;
			m_time_flat = 0;
		}
	}
	if (count >= 3)
	{
		m_time_flat++;
		if (m_time_flat > 200)
			count = 0;
	}
	//位置の変更
	m_px += m_vx;
	if (m_py > 100)
	{

		m_py += -1.0f;
	}
	if (m_py < 100)
	{
		m_py = 100;
	}
	CObjBlock*block = (CObjBlock*)Objs::GetObj(OBJ_BLOCK);
	//ブロックとの当たり判定実行
	block->BlockHit(&m_px, &m_py, false,
		&m_hit_up, &m_hit_down, &m_hit_left, &m_hit_right,
		&m_vx, &m_vy);


	//HitBoxの内容を更新
	CHitBox*hit = Hits::GetHitBox(this);
	hit->SetPos(m_px + block->GetScroll(), m_py);

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
void CObjFlyEnemy::Draw()
{
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src;
	RECT_F dst;

	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 64.0f;
	src.m_bottom = 64.0f;

	CObjBlock*block = (CObjBlock*)Objs::GetObj(OBJ_BLOCK);
	//
	dst.m_top = m_py;
	dst.m_left = m_px+block->GetScroll();
	dst.m_right = dst.m_left + 64.0f;
	dst.m_bottom = m_py + 64.0f;


	//
	Draw::Draw(6, &src, &dst, c, 0.0f);
}