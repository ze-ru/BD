//�g�p�w�b�_�[�t�@�C��
#include"GameL\DrawTexture.h"
#include"GameL\WinInputs.h"
#include"GameL\SceneManager.h"

#include"GameHead.h"
#include"Hero.h"

//�g�p�l�[���X�y�[�X
using namespace GameL;

//�C�j�V�����C�Y
void CObjHero::Init()
{
	m_px = 0.0f;//�ʒu
	m_py = 0.0f;
	m_vx = 0.0f;//�ړ��x�N�g��
	m_vy = 0.0f;
	m_posture = 0.0f;//�E����0.0f ������1.0f

	m_ani_time = 0;
	m_ani_frame = 1;

	//block�Ƃ̏Փˏ�Ԋm�F�p
	m_hit_up = false;
	m_hit_down = false;
	m_hit_left = false;
	m_hit_right = false;
}

//�A�N�V����
void CObjHero::Action()
{
	//Space�L�[�ŃW�����v
	if (Input::GetVKey(' ') == true)
	{
		if (m_hit_down == true)
		{
			m_vy = -18;
		}
	}

	//�L�[�̓��͕���
	if (Input::GetVKey(VK_RIGHT) == true)//�E
	{
		m_vx =+4.0f;
		m_posture = 0.0f;
		m_ani_time += 1;
	}

	else if (Input::GetVKey(VK_LEFT) == true)//��
	{
		m_vx =-4.0f;
		m_posture = 1.0f;
		m_ani_time += 1;
	}

	else
	{
		m_ani_frame = 0;
		m_ani_time = 0;
	}

	if (m_ani_time > 6)
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

	//���R�����^��
	m_vy += 9.8/(16.0f);

	//�ʒu�̍X�V
	m_px += m_vx;
	m_py += m_vy;
}

//�h���[
void CObjHero::Draw()
{
	int AniDate[4] =
	{
		1,2,3,4,
	};

	//�`��J���[���
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src;//�`�挳�؂���ʒu
	RECT_F dst;//�`���\���ʒu

	//�؂���ʒu�̐ݒ�
	src.m_top = 0.0f;
	src.m_left = 0.0f + AniDate[m_ani_frame] * 64.0f+1.0f;
	src.m_right = src.m_left+64.0f-2.0f;
	src.m_bottom = 64.0f;

	//�\���ʒu�̐ݒ�
	dst.m_top = 0.0f + m_py;
	dst.m_left = (64.0*m_posture) + m_px;
	dst.m_right = (64-64.0f*m_posture) + m_px;
	dst.m_bottom = 64.0f + m_py;

	//�`��
	Draw::Draw(1, &src, &dst, c, 0.0f);

}