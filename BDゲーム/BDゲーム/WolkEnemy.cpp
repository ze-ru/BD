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
	m_ex = 720.0f;//
	m_ey = 0.0f;
	m_vx = 0.0f;//
	m_vy = 0.0f;
	m_posture = 0.0f;

	m_ani_time = 0;
	m_ani_frame = 0;

	m_speed_power = 0.5f;
	m_ani_max_time = 2;

	m_move = false;//false=�E�@true=��

	m_hit_up = false;
	m_hit_down = false;
	m_hit_left = false;
	m_hit_right = false;
}

//
void CObjWolkEnemy::Action()
{
	//����
	if (m_ey > 1000.0f)
	{
		;
	}

	//�ʏ푬�x
	m_speed_power = 0.5f;
	m_ani_max_time = 2;


	/*CObjHero*hero = (CObjHero*)Objs::GetObj(OBJ_HERO);
	//��l���̈ʒu�Ō����ύX
	/if (m_move == true && m_ex < m_px)
	{
		m_move = false;
	}

	if (m_move == false && m_ex > m_px)
	{
		m_move = true;
	}*/

	//����
	if (m_move==true)
	{
		m_vx += m_speed_power;
		m_posture = 1.0f;
		m_ani_time += 1;
		
	}
	else if (m_move==false)
	{
		m_vx -= m_speed_power;
		m_posture = 0.0f;
		m_ani_time += 1;
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

	//���C
	m_vx += -(m_vx*0.098);

	//���R����
	m_vy += 9.8 / (16.0f);

	//�u���b�N�Ƃ̓����蔻����s
	CObjBlock*pb = (CObjBlock*)Objs::GetObj(OBJ_BLOCK);
	pb->BlockHit(&m_ex, &m_ey, true,
		&m_hit_up, &m_hit_down, &m_hit_left, &m_hit_right,
		&m_vx, &m_vy);

	//�ʒu�̍X�V
	m_ex += m_vx;
	m_ey += m_vy;
	
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


	//�u���b�N���������Ă���
	CObjBlock*block = (CObjBlock*)Objs::GetObj(OBJ_BLOCK);
	
	//
	dst.m_top = 0.0f + m_ey;
	dst.m_left = (64.0f*m_posture) + m_ex + block->GetScroll();
	dst.m_right = (64 - 64.0f*m_posture) + m_ex + block->GetScroll() ;
	dst.m_bottom = 64.0f + m_ey;

	//
	Draw::Draw(3, &src, &dst, c, 0.0f);
}