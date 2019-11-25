//�g�p����w�b�_�[�t�@�C��
#include "GameL\DrawTexture.h"
#include "GameL\WinInputs.h"
#include "GameL\SceneManager.h"
#include"GameL\SceneObjManager.h"
#include"GameL\HitBoxManager.h"

#include "GameHead.h"
#include "Block.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

CObjBlock::CObjBlock(int map[11][157],int mapnum)
{
	//�}�b�v�f�[�^���R�s�[
	memcpy(m_map, map, sizeof(int)*(11* 157));
	map_num = mapnum;
}
//�C�j�V�����C�Y
void CObjBlock::Init()
{
	m_scroll = 0.0f;
	dead_flag = false;
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

		//�G�o�����C��
		//��l���̈ʒu�{500��G�o�����C����
		float line = hx + (-m_scroll) + 515;

		//�G�o�����C����v�f�ԍ���
		int lx = ((int)line) / 64;
		
		//�G�o�����C���̗������
		for (int i = 0; i < 11; i++)
		{
			if (m_map[i][lx] == 5)
			{
				CObjWolkEnemy*objW = new CObjWolkEnemy(lx*64.0f, i*64.0f-64.0f);
				Objs::InsertObj(objW, OBJ_WOLKENEMY, 15);
				
				//�G�o���ꏊ��0�ɂ���
				m_map[i][lx] = 0;
			}
			if (m_map[i][lx] == 7)
			{
				CObjFlyEnemy*objF = new CObjFlyEnemy(lx*64.0f, i*64.0f);
				Objs::InsertObj(objF, OBJ_FLYENEMY, 15);

				//�G�o���ꏊ��0�ɂ���
				m_map[i][lx] = 0;
			}
			if (m_map[i][lx] == 6)
			{
				
				CObjLockEnemy*objeL = new CObjLockEnemy(lx*64.0f, i*64.0f-64.0f);
				Objs::InsertObj(objeL, OBJ_LOCKENEMY, 15);
				m_map[i][lx] = 0;
			}

			//switch�쐬
			if (m_map[i][lx] == 9)
			{
				CObjSwitch*objS = new CObjSwitch(lx*64.0f, i*64.0f - 64.0f);
				Objs::InsertObj(objS, OBJ_SWITCH, 15);
				m_map[i][lx] = 0;
			}

			//BossBlock�쐬
			if (m_map[i][lx] == 14)
			{
				CObjBossBlock*objB = new CObjBossBlock(lx*64.0f, i*64.0f - 64.0f,map_num);
				Objs::InsertObj(objB, OBJ_BOSSBLOCK, 2);
				m_map[i][lx] = 0;
			}

			if (m_map[i][lx] == 20)
			{
				CObjShopOBJ*objshop = new CObjShopOBJ(lx*64.0f, i*64.0f - 64.0f);
				Objs::InsertObj(objshop, OBJ_SHOPOBJ, 2);
				m_map[i][lx] = 0;
			}

			if (m_map[i][lx] == 41)
			{
			 	CObjBoss1*objboss = new CObjBoss1(lx*64.0f, i*64.0f - 64.0f);
				Objs::InsertObj(objboss, OBJ_BOSS1, 15);
				m_map[i][lx] = 0;
			}
			if (m_map[i][lx] == 42)
			{
				CObjBoss2*objboss2 = new CObjBoss2(lx*64.0f, i*64.0f - 64.0f);
				Objs::InsertObj(objboss2, OBJ_BOSS2, 15);
				m_map[i][lx] = 0;
			}
			
			


		}

		for (int i = 0; i < 11; i++)
		{
			for (int j = 0; j < 157; j++)
			{
				if (m_map[i][j] == 13)
				{
					if (dead_flag == true)
					{
						CObjStage1Clear*sb1 = (CObjStage1Clear*)Objs::GetObj(OBJ_STAGE1CLEAR);
						CObjGoalBlock*objg = new CObjGoalBlock(j*64.0f, i*64.0f - 64.0f);
						Objs::InsertObj(objg, OBJ_GOAL_BLOCK, 2);
						
						m_map[i][j] = 0;
						dead_flag = 0;
						sb1->Setdead();
						
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

		for (int i = 0; i < 11; i++)
		{
			for (int j = 0; j < 157; j++)
			{
				if (m_map[i][j] > 0)
				{
					//�v�f�ԍ������W�ɒǉ�
					float bx = i * 64.0f;
					float by = i * 64.0f;
					//�\���ʒu�̐ݒ�
					dst.m_top = i * 64.0f - 64.0f;
					dst.m_left = j * 64.0f + m_scroll;
					dst.m_right = dst.m_left + 64.0f;
					dst.m_bottom = dst.m_top + 64.0f;


					if (m_map[i][j] == 5)//WolkEnemy
					{
						;
					}
					else if (m_map[i][j] == 2)
					{
						BlockDraw(64.0f, 0.0f, &dst, c,map_num);
					}
					else if (m_map[i][j] == 3)
					{
						BlockDraw(128.0f, 0.0f, &dst, c,map_num);
					}
					else if (m_map[i][j] == 9)//Switch
					{
						;
					}
					else if (m_map[i][j] == 14)
					{
						;
					}
					else
					{
						//�`��
						BlockDraw(0.0f, 0.0f, &dst, c,map_num);

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
void CObjBlock::BlockDraw(float x, float y, RECT_F *dst, float c[],int num)
{
	RECT_F src;
	src.m_top = y;
	src.m_left = x;
	src.m_right = src.m_left + 64.0f;
	src.m_bottom = src.m_top + 64.0f;
	//�`��
	Draw::Draw(num, &src, dst, c, 0.0f);
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
			if (m_map[i][j] > 0 && m_map[i][j]!=14)
			{
				//�v�f�ԍ������W�ɕύX
				float bx = j * 64.0f;
				float by = i * 64.0f - 64.0f;
				bool flag = false;
				//�X�N���[���̉e��
				float scroll = scroll_on ? m_scroll : 0;

				//�I�u�W�F�N�g�ƃu���b�N�̓����蔻��
				if ((*x + (-scroll) + 64.0f > bx) && (*x + (-scroll) < bx + 64.0f) && (*y + 64.0f > by) && (*y < by + 64.0f))
				{
					//�㉺���E����

					//vector�̍쐬
					float rvx = (*x  -scroll) - bx;
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
					
						 if ((r < 45 && r > 0) || r > 315 )
						{
							*right = true;
							*x = bx + 64.0f + (scroll);
							*vx = -(*vx)*0.1f;

						}

						else if (r > 135 && r < 225 )
						{
							*left = true;
							*x = bx - 64.0f + (scroll);
							*vx = -(*vx)*0.1f;
								
						}
						
						
						//��
						else if (r > 45 && r < 135)
						{
							*down = true;
							*y = by - 64.0f;
							*vy = 0.0f;
							
							
						}
						
						//��
						else if (r > 225 && r < 315)
						{
						 	*up = true;
							*y = by + 64.0f;
							if (*vy < 0)
							{
								*vy = 0.0f;
							}

							
						}
						if (flag == false)
						{
							flag = true;
						}
					}
				}
			}
		}
	}

}

void CObjBlock::SetBlock(int flag)
{
	for (int i = 0; i < 11; i++)
	{
		for (int j = 0; j < 157; j++)
		{
			if (flag == 1)
			{
				if (m_map[i][j] == 4)
				{
					m_map[i][j] = 0;
				}
			}
		}
	}

}

void CObjBlock::BlockBossHit(float *x, float *y, bool scroll_on, bool *up, bool *down,
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
				float bx = j * 64.0f ;
				float by = i * 64.0f - 192.0f;
				bool flag = false;
				//�X�N���[���̉e��
				float scroll = scroll_on ? m_scroll : 0;

				//�I�u�W�F�N�g�ƃu���b�N�̓����蔻��
				if ((*x + (-scroll) + 256.0f > bx) && (*x + (-scroll) < bx + 256.0f) && (*y + 192.0f > by) && (*y < by + 192.0f))
				{
					//�㉺���E����

					//vector�̍쐬
					float rvx = (*x - scroll) - bx;
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

						if ((r < 45 && r > 0) || r > 315)
						{
							*right = true;
							*x = bx + 256.0f + (scroll);
							*vx = -(*vx)*0.1f;

						}
						else if (r > 135 && r < 225)
						{
							*left = true;
							*x = bx - 256.0f + (scroll);
							*vx = -(*vx)*0.1f;

						}

						//}
						//��
						else if (r > 45 && r < 135)
						{
							*down = true;
							*y = by - 64.0f;


							*vy = 0.0f;
						}

						//��
						else if (r > 225 && r < 315)
						{
							*up = true;
							*y = by + 192.0f;
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

void CObjBlock::BulletHit(float *x, float *y, bool scroll_on, bool *up, bool *down,
	bool *left, bool *right)
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
				bool flag = false;
				//�X�N���[���̉e��
				float scroll = scroll_on ? m_scroll : 0;

				//�I�u�W�F�N�g�ƃu���b�N�̓����蔻��
				if ((*x + (-scroll) + 32.0f > bx) && (*x + (-scroll) < bx + 32.0f) && (*y + 24.0f > by) && (*y < by + 24.0f))
				{
					//�㉺���E����

					//vector�̍쐬
					float rvx = (*x - scroll) - bx;
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

						if ((r < 45 && r > 0) || r > 315)
						{
							*right = true;


						}
						else if (r > 135 && r < 225)
						{
							*left = true;


						}

						//}
						//��
						else if (r > 45 && r < 135)
						{
							*down = true;

						}

						//��
						else if (r > 225 && r < 315)
						{
							*up = true;

						}

					}
				}
			}
		}
	}

}