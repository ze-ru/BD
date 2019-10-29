//�g�p����w�b�_�[�t�@�C��
#include "GameL\DrawTexture.h"
#include "GameL\WinInputs.h"
#include "GameL\SceneManager.h"
#include"GameL\SceneObjManager.h"
#include"GameL\HitBoxManager.h"

#include "GameHead.h"
#include "Block2.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

CObjBlock2::CObjBlock2(int map[11][157])
{
	//�}�b�v�f�[�^���R�s�[
	memcpy(m_map, map, sizeof(int)*(11 * 157));
}

//�C�j�V�����C�Y
void CObjBlock2::Init()
{

}

//�A�N�V����
void CObjBlock2::Action()
{

}

//�h���[
void CObjBlock2::Draw()
{

}

//BlockDrawMethod�֐�
//����1 float x  :���\�[�X�̐؂���ʒuX
//����2 float y  :���\�[�X�̐؂���ʒuY
//����3 RECT_F* dst  :�`��ʒu
//����4 float c[]  :�J���[���
//�u���b�N��64�~64����`��p�B���\�[�X�؂���ʒu�̂�x,y�Őݒ�ł���
void CObjBlock::BlockDraw(float x, float y, RECT_F *dst, float c[])
{
	RECT_F src;
	src.m_top = y;
	src.m_left = x;
	src.m_right = src.m_left + 64.0f;
	src.m_bottom = src.m_top + 64.0f;
	//�`��
	Draw::Draw(0, &src, dst, c, 0.0f);
}

//BlockHit�֐�
//����1 float*x  :������s��object��X�ʒu
//����2 float*y  :������s��object��Y�ʒu
//����3 bool scroll_on  :������s��object�̓X�N���[���̉e����^���邩�ǂ���(true=�^����@false=�^���Ȃ�)
//����4 bool* up  :�㉺���E����̏㕔���ɂ������Ă��邩�ǂ�����Ԃ�
//����5 bool*�@down  :�㉺���E����̉������ɂ������Ă��邩�ǂ�����Ԃ�
//����6 bool* left  :�㉺���E����̍������ɂ������Ă��邩�ǂ�����Ԃ�
//����7 bool* right  :�㉺���E����̉E�����ɂ������Ă��邩�ǂ�����Ԃ�
//����8 float* vx  :���E���莞�̔����ɂ��ړ������E�͂̒l�ɕς��ĕԂ�
//����9 float* vy  :�㉺���莞�ɂ�鎩�R�����^���̈ړ������E�͂̒l�ɕς��ĕԂ�
//����10 int* bt  :���������莞����ȃu���b�N�̃^�C�v��Ԃ�
//������s��object�ƃu���b�N64�~64����ŁA�����蔻��Ə㉺���E������s��
//���̌��ʂ͈���4�`10�ɕԂ�
void CObjBlock::BlockHit(float *x, float *y, bool scroll_on, bool *up, bool *down,
	bool *left, bool *right, float *vx, float *vy)
{

	*up = false;
	*down = false;
	*left = false;
	*right = false;



	for (int i = 0; i < 11; i++)
	{
		for (int j = 0; j < 157; j++)
		{
			//m_map�̑S�v�f�ɃA�N�Z�X
			if (m_map[i][j] > 0)
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

