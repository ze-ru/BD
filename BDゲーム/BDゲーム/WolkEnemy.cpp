#include "GameL\DrawTexture.h"
#include "GameL\WinInputs.h"
#include "GameL\SceneManager.h"
#include "GameL\HitBoxManager.h"

#include "GameHead.h"
#include "WolkEnemy.h"


//
using namespace GameL;

CObjWolkEnemy::CObjWolkEnemy(float x,float y)
{
	m_ex = x;//
	m_ey = y;
}
//
void CObjWolkEnemy::Init()
{
	m_vx = 0.0f;//
	m_vy = 0.0f;
	m_posture = 0.0f;

	m_ani_time = 0;
	m_ani_frame = 0;

	m_speed_power = 0.1f;
	m_ani_max_time = 4;
	m_time = 0;

	m_move = false;//false=�E�@true=��
	m_hp = 10;
	m_hit_up = false;
	m_hit_down = false;
	m_hit_left = false;
	m_hit_right = false;

	//�����蔻��p��HitBox���쐬
	Hits::SetHitBox(this, m_ex, m_ey, 64, 64, ELEMENT_ENEMY, OBJ_WOLKENEMY, 1);
}

//
void CObjWolkEnemy::Action()
{
	//�ʏ푬�x
	m_speed_power = 0.1f;
	m_ani_max_time = 6;

	CObjHero*objh = (CObjHero*)Objs::GetObj(OBJ_HERO);
	CObjBlock*block = (CObjBlock*)Objs::GetObj(OBJ_BLOCK);
	//��l���̈ʒu�Ō����ύX

	if ( m_ex > objh->GetX() - block->GetScroll())
	{
		m_move = false;
	}

	if ( m_ex < objh->GetX() - block->GetScroll())
	{
		m_move = true;

	}

	//�u���b�N�Փ˂Ō����ύX(��)
	/*if (m_hit_left == true)
	{
		m_move = false;
	}
	if (m_hit_right == true)
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

	if (m_ani_frame == 4)
	{
		m_ani_frame = 0;
	}

	//���C
	m_vx += -(m_vx*0.098);

	//���R����
	m_vy += 9.8 / (16.0f);


	//�ʒu�̍X�V
	m_ex += m_vx;
	m_ey += m_vy;

	//�u���b�N���������Ă���
	

	//�u���b�N�Ƃ̓����蔻����s
	block->BlockHit(&m_ex, &m_ey, false,
		&m_hit_up, &m_hit_down, &m_hit_left, &m_hit_right,
		&m_vx, &m_vy);


	//HitBox�̈ʒu�̕ύX
	CHitBox*hit = Hits::GetHitBox(this);
	hit->SetPos(m_ex+ block->GetScroll(), m_ey);

	if (hit->CheckElementHit(ELEMENT_ATTACK) == true)
	{
		m_hp -= 5;
	}

	if (m_hp <= 0)
	{
		this->SetStatus(false);//���g�ɍ폜���߂��o��
		Hits::DeleteHitBox(this);//�ۗL����HitBox�ɍ폜����
	}
	
}

//
void CObjWolkEnemy::Draw()
{
	int AniData[4]=
	{
		0,1,0,1,
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
	dst.m_left = (64.0f*m_posture) + m_ex +block->GetScroll();
	dst.m_right = (64 - 64.0f*m_posture) + m_ex +block->GetScroll();
	dst.m_bottom = 64.0f + m_ey ;

	//
	Draw::Draw(3, &src, &dst, c, 0.0f);
}