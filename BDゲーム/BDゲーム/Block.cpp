//�g�p����w�b�_�[�t�@�C��
#include "GameL\DrawTexture.h"
#include "GameL\WinInputs.h"
#include "GameL\SceneManager.h"
#include"GameL\SceneObjManager.h"

#include "GameHead.h"
#include "Block.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

CObjBlock::CObjBlock(int map[11][157])
{
	//�}�b�v�f�[�^���R�s�[
	memcpy(m_map, map, sizeof(int)*(11* 157));
}
//�C�j�V�����C�Y
void CObjBlock::Init()
{
	m_scroll = 0.0f;
}
//�A�N�V����
void CObjBlock::Action()
{
	//��l���̈ʒu���擾
	CObjHero*hero = (CObjHero*)Objs::GetObj(OBJ_HERO);
	float hx = hero->GetX();
	float hy = hero->GetY();

	//����X�N���[�����C��
	if (hx < 80)
	{
		hero->SetX(80);//��l���̓��C���𒴂��Ȃ��悤�ɂ���
		m_scroll -= hero->GetVX();//��l�����{�������ׂ����̒l��m_scroll�ɉ�����
	}

	//�O���X�N���[�����C��
	if (hx > 300)
	{
		hero->SetX(300);
		m_scroll -= hero->GetVX();
	}

	hero->SetUp(false);
	hero->SetDown(false);
	hero->SetLeft(false);
	hero->SetRight(false);

	for (int i = 0; i < 11; i++)
	{
		for (int j = 0; j < 157; j++)
		{
			//m_map�̑S�v�f�ɃA�N�Z�X
			if (m_map[i][j] > 0)
			{
				//�v�f�ԍ������W�ɕύX
				float x = j * 64.0f;
				float y = i * 64.0f-64.0f;

				//��l���ƃu���b�N�̓����蔻��
				if ((hx+(-m_scroll)+64.0f>x) && (hx+(-m_scroll)<x+64.0f) && (hy+64.0f>y) && (hy<y+64.0f))
				{
					//�㉺���E����

					//vector�̍쐬
					float vx =(hx+(-m_scroll)) - x;
					float vy = hy - y;

					//���������߂�
					float len = sqrt(vx * vx + vy * vy);

					//�p�x�����߂�
					float r = atan2(vy, vx);
					r = r * 180.0f / 3.14f;

					if (r <= 0.0f)
						r = abs(r);
					else
						r = 360.0f - abs(r);
				//len��������̒������Z���ꍇ����ɓ���
					if (len < 88.0f)
					{
						//�p�x�ŏ㉺���E�𔻒�
					//�E
						if ((r < 45 && r > 0) || r > 315)
						{
							hero->SetRight(true);
							hero->SetX(x + 64.0f+(m_scroll));
							hero->SetVX(-hero->GetVX()*0.1f);
						}

						//��
						if (r > 45 && r < 135)
						{
							hero->SetDown(true);
							hero->SetY(y - 64.0f);
							hero->SetVY(0.0f);
						}

						//��
						if (r > 135 & r < 225)
						{
							hero->SetLeft(true);
							hero->SetX(x - 64.0f+(m_scroll));
							hero->SetVX(-hero->GetVX()*0.1f);
						}

						//��
						if (r > 225 && r < 315)
						{
							hero->SetUp(true);
							hero->SetY(y + 64.0f);
							if (hero->GetVY() < 0)
							{
								hero->SetVY(0.0f);
							}
						}
				    }
					
					
				}
			}
		}
	}

	
}
//�h���[
void CObjBlock::Draw()
{
	//�`��J���[���
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src; //�`�挳�؂���ʒu
	RECT_F dst; //�`���\���ʒu

	//�w�i�\��
	

	//�}�b�v�`�b�v�ɂ��block�ݒu
	//�؂���ʒu�̐ݒ�
	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = src.m_left + 64.0f;
	src.m_bottom = 64.0f;


	for (int i = 0; i <11 ; i++)
	{
		for (int j = 0; j < 157; j++)
		{
			if (m_map[i][j] > 0)
			{
				//�\���ʒu�̐ݒ�
				dst.m_top = i *64.0f-64.0f;
				dst.m_left = j *64.0f+m_scroll;
				dst.m_right = dst.m_left + 64.0f;
				dst.m_bottom = dst.m_top + 64.0f;

				//�`��
				Draw::Draw(0, &src, &dst, c, 0.0f);
			}
		}
	}
	
}