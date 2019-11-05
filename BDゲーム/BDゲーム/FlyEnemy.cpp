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
	
	
	//位置の変更
	m_px += m_vx;
	if (m_py > 50)
	{
		
		m_py += -1.0f;
	}
	if (m_py < 50)
	{
		m_py = 50;
	}
	CObjBlock*block = (CObjBlock*)Objs::GetObj(OBJ_BLOCK);
	//HitBoxの内容を更新
	CHitBox*hit = Hits::GetHitBox(this);
	hit->SetPos(m_px + block->GetScroll(), m_py);
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