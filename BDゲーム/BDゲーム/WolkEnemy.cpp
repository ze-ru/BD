#include "GameL/DrawTexture.h"
#include "GameL/WinInputs.h"
#include "GameL/SceneManager.h"

#include "GameHead.h"
#include "WolkEnemy.h"


//
using namespace GameL;

//
void CObjWolkEnemy::Init()
{
	m_px = 720.0f;//
	m_py = 0.0f;
	m_vx = 0.0f;//
	m_vy = 0.0f;
	m_posture = 0.0f;
	m_hit_down = false;
	x = 0.0f;

	m_ani_time = 0;
	m_ani_frame = 0;
}

//
void CObjWolkEnemy::Action()
{
	if (m_hit_down == true)
	{
		m_vx = -1.0f;
		m_ani_time += 1;
	}

	if (m_ani_time > 18)
	{
		m_ani_frame += 1;
		m_ani_time = 0;
	}

	if (m_ani_time== 2)
	{
		m_ani_frame = 0;
	}


	m_vy += 4.0 / (16.0f);

	//
	m_px += m_vx;
	m_py += m_vy;

	if (m_py + 80.0f > 574.0f)
	{
		m_py = 574.0f - 80.0f;
		m_hit_down = true;
		x = 0.0f;
	}
}

//
void CObjWolkEnemy::Draw()
{
	int AniData[2]
	{
		0,1,
	};
	//
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src;
	RECT_F dst;


	src.m_top = 0.0f;
	src.m_left = 0.0f + AniData[m_ani_frame] * 64;
	src.m_right = 64.0f + AniData[m_ani_frame] * 64;
	src.m_bottom = 64.0f;

	//
	dst.m_top = 0.0f + m_py;
	dst.m_left = (64.0f*m_posture) + m_px;
	dst.m_right = (64 - 64.0f*m_posture) + m_px;
	dst.m_bottom = 64.0f + m_py;

	//
	Draw::Draw(3, &src, &dst, c, 0.0f);
}