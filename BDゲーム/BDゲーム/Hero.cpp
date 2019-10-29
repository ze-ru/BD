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
	m_py = 550.0f;
	m_vx = 0.0f;//�ړ��x�N�g��
	m_vy = 0.0f;
	m_posture = 0.0f;//�E����0.0f ������1.0f

	m_ani_time = 0;
	m_ani_frame = 1;

	m_hp = 0.0f;
	m_time1 = 0;
	m_time2 = 0;

	flag = false;//false=�E���� true=������

	//block�Ƃ̏Փˏ�Ԋm�F�p
	m_hit_up = false;
	m_hit_down = false;
	m_hit_left = false;
	m_hit_right = false;

	m_attack = false;

	//�����蔻��p��HitBox���쐬
	Hits::SetHitBox(this, m_px, m_py, 48, 64, ELEMENT_PLAYER, OBJ_HERO, 1);
}

//�A�N�V����
void CObjHero::Action()
{
	m_time1++;
	if (m_time1 > 5)
	{
		m_attack = true;
		m_time1 = 0;
	}

	if (m_attack == true)
	{
		if (Input::GetVKey('X'))
		{
			m_time2 += 1;
			CObjAttack*objat = (CObjAttack*)Objs::GetObj(OBJ_ATTACK);
			CObjAttack*obja = new CObjAttack(m_px, m_py);
			Objs::InsertObj(obja, OBJ_ATTACK, 10);
		}
		
		if (m_time2 >=1)
		{
			m_attack = false;
			m_time2 = 0;
		}
	}
	
	//������
	if (m_py > 1000.0f)
	{
		;
	}

	//Space�L�[�ŃW�����v
	if (Input::GetVKey(' ') == true)
	{
		if (m_hit_down == true)
		{
			if(m_vy>=0)
			m_vy = -12;
			
		}
	}
	
	

	//�L�[�̓��͕���
	if (Input::GetVKey(VK_RIGHT) == true)//�E
	{
		m_vx =+4.0f;
		m_posture = 0.0f;
		m_ani_time += 1;

		flag = false;
	}

	else if (Input::GetVKey(VK_LEFT) == true)//��
	{
		m_vx =-4.0f;
		m_posture = 1.0f;
		m_ani_time += 1;

		flag = true;
	}

	

	if (Input::GetVKey(VK_LEFT) == false && Input::GetVKey(VK_RIGHT) == false && m_hit_down == true)
	{
		m_ani_time++;
		if (m_ani_time < 40)
		{
			m_ani_frame = 0;
		}
		if (m_ani_time > 80)
		{
			m_ani_frame = 1;
		}
		if (m_ani_time > 120)
		{
			m_ani_time = 0;
		}
	}
	if (Input::GetVKey(VK_LEFT) == true || Input::GetVKey(VK_RIGHT) == true)
	{
		if (m_ani_time>6)
		{
			m_ani_frame += 1;
			m_ani_time = 0;
		}
		
	}
	
	
	if (m_ani_frame == 5)
	{
		m_ani_frame = 2;
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
		

		for (int i = 0; i < hit->GetCount(); i++)
		{

			//�G�̍��E�ɓ���������
			float r = hit_data[i]->r;
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
				m_px += ((CObjWolkEnemy*)hit_data[i]->o)->GetVx();

				CObjBlock*b = (CObjBlock*)Objs::GetObj(OBJ_BLOCK);

				//����X�N���[�����C��
				if (m_px < 80)
				{
					m_px = 80;//��l���̓��C���𒴂��Ȃ��悤�ɂ���
					b->SetScroll(b->GetScroll() - 5.0);
				}

				//�O���X�N���[�����C��
				if (m_px > 300)
				{
					m_px = 300;
					b->SetScroll(b->GetScroll() - 5.0);
				}

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

		
	}
	if (hit->CheckObjNameHit(OBJ_LOCKENEMY) != nullptr)
	{
		HIT_DATA** hit_data;
		hit_data = hit->SearchObjNameHit(OBJ_LOCKENEMY);
	

		for (int i = 0; i < hit->GetCount(); i++)
		{

			//�G�̍��E�ɓ���������
			float r = hit_data[i]->r;
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
			

				CObjBlock*b = (CObjBlock*)Objs::GetObj(OBJ_BLOCK);

				//����X�N���[�����C��
				if (m_px < 80)
				{
					m_px = 80;//��l���̓��C���𒴂��Ȃ��悤�ɂ���
					b->SetScroll(b->GetScroll() - 5.0);
				}

				//�O���X�N���[�����C��
				if (m_px > 300)
				{
					m_px = 300;
					b->SetScroll(b->GetScroll() - 5.0);
				}

				if (m_vy <= -1.0f)
				{
					;
				}
				else
				{
					m_vy = 0.0f;//�x�N�g����0�ɂ���
					m_hit_down = true;//�n�ʂɓ������Ă��锻��ɂ���
				}
			}
		}
		

		
		
	}
	if (hit->CheckObjNameHit(OBJ_NORMAL_BULLET) != nullptr)
	{

		HIT_DATA** hit_data;
		hit_data = hit->SearchObjNameHit(OBJ_NORMAL_BULLET);
		m_hp += 5;
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
		m_py += 0.5f;
	}

	if (m_hp == 50)
	{
		this->SetStatus(false);
		Hits::DeleteHitBox(this);

		Scene::SetScene(new CSceneGameOver());
	}
	
}

//�h���[
void CObjHero::Draw()
{
	int AniDate[7] =
	{
		0,1,2,3,4,5,6
	};

	//�`��J���[���
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src;//�`�挳�؂���ʒu
	RECT_F dst;//�`���\���ʒu

	//�؂���ʒu�̐ݒ�
	
	if (m_hit_down == false && m_vy < 0)
	{
		src.m_top = 0.0f;
		src.m_left = 0.0f + 5 * 64.0f + 1.0f;
		src.m_right = 64.0f + 5 *64.0f+ 1.0f;
		src.m_bottom = 64.0f;
	}
	else if (m_hit_down == false && m_vy >=1)
	{
		src.m_top = 0.0f;
		src.m_left = 0.0f + 6 * 64.0f + 1.0f;
		src.m_right = 64.0f + 6 * 64.0f + 1.0f;
		src.m_bottom = 64.0f;
	}
	else
	{
		src.m_top = 0.0f;
		src.m_left = 0.0f + AniDate[m_ani_frame] * 64.0f + 1.0f;
		src.m_right = src.m_left + 64.0f - 2.0f;
		src.m_bottom = 64.0f;
	}


	//�\���ʒu�̐ݒ�
	dst.m_top = 0.0f + m_py;
	dst.m_left = (64.0*m_posture) + m_px;
	dst.m_right = (64-64.0f*m_posture) + m_px;
	dst.m_bottom = 64.0f + m_py;

	//�`��
	Draw::Draw(1, &src, &dst, c, 0.0f);

	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 128.0f;
	src.m_bottom = 24.0f;


	//�\���ʒu�̐ݒ�
	dst.m_top = 0.0f;
	dst.m_left = 0.0f;
	dst.m_right = 256.0f;
	dst.m_bottom = 48.0f;



	//�`��
	Draw::Draw(5, &src, &dst, c, 0.0f);

	src.m_top = 2.0f;
	src.m_left = 128.0f;
	src.m_right = 129.0f;
	src.m_bottom = 22.0f;


	dst.m_top = 4.0f;
	dst.m_left = 4.0f;
	dst.m_right = 256.0f - m_hp*5.0f;
	dst.m_bottom = 44.0f;

	Draw::Draw(5, &src, &dst, c, 0.0f);

}