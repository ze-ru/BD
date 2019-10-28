#include"GameL\DrawTexture.h"
#include"GameL\WinInputs.h"
#include"GameL\SceneManager.h"
#include "GameL\HitBoxManager.h"

#include"GameHead.h"
#include"LockEnemy.h"

using namespace GameL;

void CObjLockEnemy::Init()
{
	m_py = 0;
	m_px = 0;
	m_ani_time = 0;
	m_ani_frame = 0;
	m_posture = 0;

	Hits::SetHitBox(this, m_px, m_py, 64, 64, ELEMENT_ENEMY, OBJ_LOCKENEMY, 1);
}
void CObjLockEnemy::Action()
{
	//HitBoxの内容を更新
	CHitBox* hit = Hits::GetHitBox(this);
	hit->SetPos(m_px, m_py);
}
void CObjLockEnemy::Draw()
{
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src;
	RECT_F dst;

	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right =32.0f;
	src.m_bottom =32.0f;


	//
	dst.m_top = m_py;
	dst.m_left = m_px;
	dst.m_right =64.0f;
	dst.m_bottom =64.0f;


	//
	Draw::Draw(4, &src, &dst, c, 0.0f);
}