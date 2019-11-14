//�g�p����w�b�_�[�t�@�C��
#include "GameL\DrawTexture.h"
#include "GameL\WinInputs.h"
#include "GameL\SceneManager.h"
#include"GameL\SceneObjManager.h"
#include"GameL\HitBoxManager.h"

#include "GameHead.h"
#include "Block3.h"


//�g�p����l�[���X�y�[�X
using namespace GameL;

CObjBlock3::CObjBlock3(int map3[11][156])
{
	//�}�b�v�f�[�^���R�s�[
	memcpy(m_map3, map3, sizeof(int)*(11 * 156));
}

//�C�j�V�����C�Y
void CObjBlock3::Init()
{
	m_scroll = 0.0f;

}

//�A�N�V����
void CObjBlock3::Action()
{
	if (m_map3[0][0] == 0)
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

		//�G�o�����C��
		//��l���̈ʒu�{500��G�o�����C����
		float line = hx + (-m_scroll) + 500;

		//�G�o�����C����v�f�ԍ���
		int lx = ((int)line) / 64;

		//�G�o�����C���̗������
		for (int i = 0; i < 11; i++)
		{
			if (m_map3[i][lx] == 5)
			{
				CObjWolkEnemy*objW = new CObjWolkEnemy(lx*64.0f, i*63.0f);
				Objs::InsertObj(objW, OBJ_WOLKENEMY, 15);

				//�G�o���ꏊ��0�ɂ���
				m_map3[i][lx] = 0;
			}
		}
	}
}

//�h���[
void CObjBlock3::Draw()
{
	//�`��J���[���
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src; //�`�挳�؂���ʒu
	RECT_F dst; //�`���\���ʒu

	//�}�b�v�`�b�v�ɂ��block�ݒu
	for (int i = 0; i < 11; i++)
	{
		for (int j = 0; j < 156; j++)
		{
			if (m_map3[i][j] > 0 && m_map3[i][j] != 5)
			{
				//�v�f�ԍ������W�ɒǉ�
				float bx = i * 64.0f;
				float by = i * 64.0f;
				//�\���ʒu�̐ݒ�
				dst.m_top = i * 64.0f - 64.0f;
				dst.m_left = j * 64.0f + m_scroll;
				dst.m_right = dst.m_left + 64.0f;
				dst.m_bottom = dst.m_top + 64.0f;

				if (m_map3[i][j] == 2)
				{
					BlockDraw3(64.0f, 0.0f, &dst, c);
				}
				else if (m_map3[i][j] == 3)
				{
					BlockDraw3(128.0f, 0.0f, &dst, c);
				}
				else
				{
					//�`��
					BlockDraw3(0.0f, 0.0f, &dst, c);
				}
			}
		}

	}
}

//BlockDrawMethod�֐�
//����1 float x  :���\�[�X�̐؂���ʒuX
//����2 float y  :���\�[�X�̐؂���ʒuY
//����3 RECT_F* dst  :�`��ʒu
//����4 float c[]  :�J���[���
//�u���b�N��64�~64����`��p�B���\�[�X�؂���ʒu�̂�x,y�Őݒ�ł���
void CObjBlock3::BlockDraw3(float x, float y, RECT_F *dst, float c[])
{
	RECT_F src;
	src.m_top = y;
	src.m_left = x;
	src.m_right = src.m_left + 64.0f;
	src.m_bottom = src.m_top + 64.0f;
	//�`��
	Draw::Draw(9, &src, dst, c, 0.0f);
}



void CObjBlock3::BlockHit3(float *x, float *y, bool scroll_on, bool *up, bool *down,
	bool *left, bool *right, float *vx, float *vy)
{

	*up = false;
	*down = false;
	*left = false;
	*right = false;



	for (int i = 0; i < 11; i++)
	{
		for (int j = 0; j < 156; j++)
		{
			//m_map�̑S�v�f�ɃA�N�Z�X
			if (m_map3[i][j] > 0)
			{
				//�v�f�ԍ������W�ɕύX
				float bx = j * 64.0f;
				float by = i * 64.0f - 64.0f;

				//�X�N���[���̉e��
				float scroll = scroll_on ? m_scroll : 0;

				//�I�u�W�F�N�g�ƃu���b�N�̓����蔻��
				if ((*x + (-scroll) + 64.0f > bx) && (*x + (-scroll) < bx + 64.0f) && (*y + 64.0f > by) && (*y < by + 64.0f))
				{
					//�㉺���E����

					//vector�̍쐬
					float rvx = (*x + (-scroll)) - bx;
					float rvy = *y - by;

					//���������߂�
					float len = sqrt(rvx * rvx + rvy * rvy);

					//�p�x�����߂�
					float r = atan2(rvy, rvx);
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
							*right = true;
							*x = bx + 64.0f + (scroll);
							*vx = -(*vx)*0.1f;
						}

						//��
						if (r > 45 && r < 135)
						{
							*down = true;
							*y = by - 64.0f;


							*vy = 0.0f;
						}

						//��
						if (r > 135 && r < 225)
						{
							*left = true;
							*x = bx - 64.0f + (scroll);
							*vx = -(*vx)*0.1f;
						}

						//��
						if (r > 225 && r < 315)
						{
							*up = true;
							*y = by + 64.0f;
							if (*vy < 0)
							{
								*vy = 0.0f;
							}
						}
					}


				}
			}
		}
	}

}