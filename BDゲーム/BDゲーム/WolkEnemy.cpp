#include "GameL\DrawTexture.h"
#include "GameL\WinInputs.h"
#include "GameL\SceneManager.h"

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

	m_ani_time = 0;
	m_ani_frame = 0;

	m_speed_power = 0.5f;
	m_ani_max_time = 2;

	m_hit_up = false;
	m_hit_down = false;
	m_hit_left = false;
	m_hit_right = false;
}

//
void CObjWolkEnemy::Action()
{
	//落下
	if (m_py > 1000.0f)
	{
		;
	}

	//通常速度
	m_speed_power = 0.5f;
	m_ani_max_time = 2;

	//方向
	if (false)
	{
		m_vx += m_speed_power;
		m_posture = 1.0f;
		m_ani_time += 1;
	}
	else if (false)
	{
		m_vx -= m_speed_power;
		m_posture = 0.0f;
		m_ani_time += 1;
	}
	else
	{
		m_ani_frame = 1;
		m_ani_time = 0;
	}

	if (m_ani_time > m_ani_max_time)
	{
		m_ani_frame += 1;
		m_ani_time = 0;
	}

	if (m_ani_frame == 2)
	{
		m_ani_frame = 0;
	}

	//摩擦
	m_vx += -(m_vx*0.098);

	//自由落下
	m_vy += 9.8 / (16.0f);

	//位置の更新
	m_px += m_vx;
	m_py += m_vy;

	//ブロック情報を持ってくる
	CObjBlock*block = (CObjBlock*)Objs::GetObj(OBJ_BLOCK);

}

//
void CObjWolkEnemy::Draw()
{
	int AniData[2]=
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


	//ブロック情報を持ってくる
	CObjBlock*block = (CObjBlock*)Objs::GetObj(OBJ_BLOCK);
	
	//
	dst.m_top = 0.0f + m_py;
	dst.m_left = (64.0f*m_posture) + m_px + block->GetScroll();
	dst.m_right = (64 - 64.0f*m_posture) + m_px + block->GetScroll() ;
	dst.m_bottom = 64.0f + m_py;

	//
	Draw::Draw(3, &src, &dst, c, 0.0f);
}