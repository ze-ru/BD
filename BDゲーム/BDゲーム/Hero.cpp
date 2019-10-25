//�g�p�w�b�_�[�t�@�C��
#include"GameL\DrawTexture.h"
#include"GameL\WinInputs.h"
#include"GameL\SceneManager.h"
#include"GameL\HitBoxManager.h"

#include"GameHead.h"
#include"Hero.h"

//�g�p�l�[���X�y�[�X
using namespace GameL;

//�C�j�V�����C�Y
void CObjHero::Init()
{
	m_px = 100.0f;//�ʒu
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

	//�����蔻��p��HitBox���쐬
	Hits::SetHitBox(this, m_px, m_py, 64, 64, ELEMENT_PLAYER, OBJ_HERO, 1);
}

//�A�N�V����
void CObjHero::Action()
{
	//Space�L�[�ŃW�����v
	if (Input::GetVKey(' ') == true)
	{
		if (m_hit_down == true)
		{
			if(m_py>0)
			m_vy = -12;
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
	m_vy += 5.0/(20.0f);

	//�u���b�N�Ƃ̓����蔻����s
	CObjBlock*pb = (CObjBlock*)Objs::GetObj(OBJ_BLOCK);
	pb->BlockHit(&m_px, &m_py, true,
		&m_hit_up, &m_hit_down, &m_hit_left, &m_hit_right,
		&m_vx, &m_vy);

	//���g��HitBox�������Ă���
	CHitBox* hit = Hits::GetHitBox(this);

	//�G�Ɠ������Ă��邩�m�F
	if (hit->CheckObjNameHit(OBJ_WOLKENEMY)!=nullptr)
	{
		//��l�����G�Ƃǂ̊p�x�œ������Ă邩�m�F
		HIT_DATA** hit_data;
		hit_data = hit->SearchObjNameHit(OBJ_WOLKENEMY);

		//�G�̍��E�ɓ���������
		float r = hit_data[0]->r;
		if ((r < 45 && r >= 0) || r > 315)
		{
			m_vx = -5.0f;//���Ɉړ�
		}
		if (r > 135 && r < 225)
		{
			m_vx = +5.0f;//�E�Ɉړ�
		}
		if (r >= 225 && r < 315)
		{
			//�G�̈ړ���������l���̈ʒu�ɉ��Z
			m_px += ((CObjWolkEnemy*)hit_data[0]->o) -> GetVx();

			CObjBlock*b=(CObjBlock*)Objs::GetObj(OBJ_BLOCK);

			if (m_vy <= -1.0f)
			{

			}
			else
			{
				m_vy = 0.0f;//�x�N�g����0�ɂ���
				m_hit_down = true;//�n�ʂɓ������Ă��锻��ɂ���
			}
		}
	}

	//�ʒu�̍X�V
	m_px += m_vx;
	m_py += m_vy;

	//HitBox�̈ʒu�̕ύX
	hit->SetPos(m_px, m_py);

	//�J�n�ʒu���獶�ɍs���Ȃ�����
	if (m_px < 0)
	{
		m_px = 0;
	}

	if (m_py < 0)
	{
		m_vy += 0.5f;
	}
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