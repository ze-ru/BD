#include"GameL\DrawTexture.h"
#include"GameL\WinInputs.h"
#include"GameL\SceneManager.h"

#include"GameHead.h"
#include"LockEnemy.h"

using namespace GameL;

void CObjLockEnemy::Init()
{
	m_py = 0;
	m_px = 0;
	m_ani_time = 0;
	m_ani_frame = 0;
}
void CObjLockEnemy::Action()
{

}
void CObjLockEnemy::Draw()
{
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src;
	RECT_F dst;

	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = src.m_right+64.0f;
	src.m_bottom = src.m_top+64.0f;


	//
	dst.m_top = m_py;
	dst.m_left = (80.0f * m_posture)+m_px;
	dst.m_right = (80 - 80.0f * m_posture)+64.0f;
	dst.m_bottom =dst.m_top+64.0f;


	//
	Draw::Draw(3, &src, &dst, c, 0.0f);
}