//�g�p�w�b�_�[�t�@�C��
#include"GameL\DrawTexture.h"
#include"GameL\WinInputs.h"
#include"GameL\SceneManager.h"
#include"GameL\HitBoxManager.h"

#include"GameHead.h"
#include"Hero.h"

//�g�p�l�[���X�y�[�X
using namespace GameL;

CObjHero::CObjHero(int b, int w)
{
	wp = w;
	bullet = b;
}

//�C�j�V�����C�Y
void CObjHero::Init()
{
	m_px = 100.0f;//�ʒu
	m_py = 400.0f;
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
	hit_flag = true;
	m_attack = false;
	m_dead = 0.0f;
	m_y_flag = false;
	m_y_num = 0;
	m_dead_flag = false;
	bullet_count = 0;
	m_time_bullet = 0;
	
	bulletflag = true;
	//�����蔻��p��HitBox���쐬
	Hits::SetHitBox(this, m_px, m_py, 64, 64, ELEMENT_PLAYER, OBJ_HERO, 1);
}

//�A�N�V����
void CObjHero::Action()
{
	if (m_hp < 0)
	{
		m_hp = 0;
	}
	
	//�u���b�N�Ƃ̓����蔻����s
	CObjBlock*pb = (CObjBlock*)Objs::GetObj(OBJ_BLOCK);

	CHitBox* hit = Hits::GetHitBox(this);
	if (m_y_num >= 50&&m_y_flag==false)
	{
		if (hit->CheckObjNameHit(OBJ_WOLKENEMY) != nullptr)
		{
			int enemynum = 1;
			EnemyHit(enemynum);
		}
		if (hit->CheckObjNameHit(OBJ_LOCKENEMY) != nullptr)
		{
			int enemynum = 2;
			EnemyHit(enemynum);
		}
		if (hit->CheckObjNameHit(OBJ_FLYENEMY) != nullptr)
		{
			int enemynum = 3;
			EnemyHit(enemynum);
		}
		//�u���b�N�Ƃ̓����蔻����s
		
			pb->BlockHit(&m_px, &m_py, true,
				&m_hit_up, &m_hit_down, &m_hit_left, &m_hit_right,
				&m_vx, &m_vy);
		
			
			//�G�Ɠ������Ă��邩�m�F
	
		if (m_y_num < 100)
		{
			m_y_num = 50;
		}
		m_vx = 2.0f*m_posture;
		m_y_flag = true;
		
	}
	if (m_dead_flag == true)
	{
		if (m_hp >= 50)
		{
			m_time2++;
			if (m_time2 > 10 && m_time2 < 20)
			{
				m_dead += 1.0f;
			}
			if (m_time2 > 50)
			{
				this->SetStatus(false);
				Hits::DeleteHitBox(this);
				CObjStage1*s1 = (CObjStage1*)Objs::GetObj(OBJ_STAGE1);
				Scene::SetScene(new CSceneGameOver(s1->Getmapflag(),s1->Getmapnum(),wp,bullet));

			}
		}
	}
	if (m_dead_flag == false)
	{
		//�u���b�N�Ƃ̓����蔻����s
		
			pb->BlockHit(&m_px, &m_py, true,
				&m_hit_up, &m_hit_down, &m_hit_left, &m_hit_right,
				&m_vx, &m_vy);
		
		if (m_y_flag==true)
		{
			
			m_y_num--;
			
			//���R�����^��

			m_vy += 5.0 / (20.0f);
			
			
			if (m_y_num >40) {
				if (m_posture == 0.0f)
					m_vx -= 0.2f;
				if (m_posture == 1.0f)
					m_vx += 0.2f;
			}

			m_px += m_vx;
			m_py += m_vy;
			//HitBox�̈ʒu�̕ύX
			hit->SetPos(m_px, m_py);

			
			if (m_y_num < 0)
			{
				m_y_num = 0;
				m_y_flag = false;
			}

		}
		if (m_y_flag == false)
		{

			if (m_attack == true)
			{
				if (Input::GetVKey('X'))
				{
					CObjAttack*obja = new CObjAttack(m_px, m_py);
					Objs::InsertObj(obja, OBJ_ATTACK, 50);
					m_attack = false;
				}
			}
			if (m_attack == false)
			{
				m_time1++;
				if (m_time1 > 30)
				{
					m_time1 = 0;
					m_attack = true;
				}
			}
			if (wp == 1)
			{
				if (Input::GetVKey('C') == true)
				{
					if (bullet > 0)
					{
						m_time_bullet++;
						if (m_time_bullet > 10)
						{
							if (flag == false)
							{
								CObjHeroAssultBullet*objhBullet = new CObjHeroAssultBullet(m_px - pb->GetScroll() + 62.0f, m_py);
								Objs::InsertObj(objhBullet, OBJ_HEROASSULTBULLET, 10);
								bullet--;
							}
							if (flag == true)
							{
								CObjHeroAssultBullet*objhBullet = new CObjHeroAssultBullet(m_px - pb->GetScroll() - 2.0f, m_py);
								Objs::InsertObj(objhBullet, OBJ_HEROASSULTBULLET, 10);
								bullet--;
							}

							m_time_bullet = 0;
						}
						
					}
				}
			}
			if (wp == 2)
			{
				if (Input::GetVKey('C') == true)
				{
					
					if (bullet > 0)
					{
						
						if (flag == false && bulletflag == true)
						{
							CObjHeroNormalBullet*objhnb = new CObjHeroNormalBullet(m_px - pb->GetScroll() + 62.0f, m_py);
							Objs::InsertObj(objhnb, OBJ_HERONORMALBULLET, 10);
							bullet--;
							bulletflag = false;
						}
						if (flag == true && bulletflag == true)
						{
							CObjHeroNormalBullet*objhnb = new CObjHeroNormalBullet(m_px - pb->GetScroll() - 2.0f, m_py);
							Objs::InsertObj(objhnb, OBJ_HERONORMALBULLET, 10);
							bullet--;
							bulletflag = false;
						}
							
						

					}
				}
				if (Input::GetVKey('C') == false)
				{
					if (bulletflag == false)
					{
						bulletflag = true;
					}
				}
			}
			if (wp == 3)
			{
				if (Input::GetVKey('C') == true)
				{

				}
			}
			
			if (m_py > 1000.0f)
			{
				;
			}
			



			//�L�[�̓��͕���
			if (Input::GetVKey(VK_RIGHT) == true)//�E
			{
				m_vx = +5.0f;
				m_posture = 0.0f;
				m_ani_time += 1;
				if (Input::GetVKey('M') == true)
				{
					m_vx = +30;
				}
				flag = false;
			}

			else if (Input::GetVKey(VK_LEFT) == true)//��
			{
				m_vx = -5.0f;
				m_posture = 1.0f;
				m_ani_time += 1;
				if (Input::GetVKey('M') == true)
				{
					m_vx = -30;
				}
				flag = true;
			}

			



			//���C
			m_vx += -(m_vx*0.098);

			//���R�����^��
			m_vy += 5.0 / (20.0f);

		

			//���g��HitBox�������Ă���


			//�G�Ɠ������Ă��邩�m�F
			if (hit->CheckObjNameHit(OBJ_WOLKENEMY) != nullptr)
			{
				int enemynum = 1;
				EnemyHit(enemynum);
			}
			if (hit->CheckObjNameHit(OBJ_LOCKENEMY) != nullptr)
			{
				int enemynum = 2;
				EnemyHit(enemynum);
			}
			if (hit->CheckObjNameHit(OBJ_FLYENEMY) != nullptr)
			{
				int enemynum = 3;
				EnemyHit(enemynum);
			}
			if (hit->CheckObjNameHit(OBJ_BOSS1) != nullptr)
			{
				int enemynum = 4;
				EnemyHit(enemynum);
			}
			
			if (hit->CheckObjNameHit(OBJ_NORMAL_BULLET) != nullptr)
			{
				HIT_DATA** hit_data;
				hit_data = hit->SearchObjNameHit(OBJ_NORMAL_BULLET);
				m_y_num += 30;
			}
			if (hit->CheckObjNameHit(OBJ_ASSAULT_BULLET) != nullptr)
			{
				HIT_DATA** hit_data;
				hit_data = hit->SearchObjNameHit(OBJ_ASSAULT_BULLET);
				m_y_num += 10;
			}
			//Space�L�[�ŃW�����v
			if (Input::GetVKey(' ') == true)
			{
				if (m_hit_down == true)
				{
					if (m_vy >= 0)
						m_vy = -10.5;

				}
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
				if (m_ani_time > 6)
				{
					m_ani_frame += 1;
					m_ani_time = 0;
				}

			}


			if (m_ani_frame == 5)
			{
				m_ani_frame = 2;
			}
			//�ʒu�̍X�V
			m_px += m_vx;
			m_py += m_vy;
			

			//HitBox�̈ʒu�̕ύX
			hit->SetPos(m_px, m_py);


			if (m_py < 0)
			{
				m_py += 0.5f;
			}
			if (m_hp >= 50)
			{
				m_dead_flag = true;
			}

		}
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
	float c2[4] = { 1.0f,0.0f,1.0f,1.0f };

	RECT_F src;//�`�挳�؂���ʒu
	RECT_F dst;//�`���\���ʒu

	//�؂���ʒu�̐ݒ�
	
	if (m_hit_down == false && m_vy < 1)
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
	else if (m_hit_down == true && m_vx == 0)
	{
		src.m_top = 0.0f;
		src.m_left = 0.0f + AniDate[m_ani_frame] * 64.0f + 1.0f;
		src.m_right = src.m_left + 64.0f - 2.0f;
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
	Draw::Draw(2, &src, &dst, c, m_dead);

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
	dst.m_right = 252.0f - m_hp*5.04f;
	dst.m_bottom = 44.0f;

	Draw::Draw(5, &src, &dst, c, 0.0f);

	wchar_t str[50];

	swprintf_s(str, L"�e���F%d", bullet);

	Font::StrDraw(str, 500, 10, 20, c2);

	if (wp == 1)
	{
		src.m_top = 0.0f;
		src.m_left = 192.0f;
		src.m_right = 256.0f;
		src.m_bottom = 64.0f;


		CObjBlock*block = (CObjBlock*)Objs::GetObj(OBJ_BLOCK);
		//
		dst.m_top = 0.0f;
		dst.m_left =270.0f;
		dst.m_right = dst.m_left + 96.0f;
		dst.m_bottom = dst.m_top+64.0f;

		Draw::Draw(19, &src, &dst, c, 0.0f);
	}
	if (wp == 2)
	{
		src.m_top =-10.0f;
		src.m_left = 0.0f;
		src.m_right = 64.0f;
		src.m_bottom = 64.0f;


		CObjBlock*block = (CObjBlock*)Objs::GetObj(OBJ_BLOCK);
		//
		dst.m_top = -10.0f;
		dst.m_left = 270.0f;
		dst.m_right = dst.m_left + 96.0f;
		dst.m_bottom = dst.m_top+64.0f;



		Draw::Draw(19, &src, &dst, c, 0.0f);
	}
}

void CObjHero::EnemyHit(int enemynum)
{
	CHitBox* hit = Hits::GetHitBox(this);
	CObjBlock*pb = (CObjBlock*)Objs::GetObj(OBJ_BLOCK);
	//��l�����G�Ƃǂ̊p�x�œ������Ă邩�m�F
	HIT_DATA** hit_data=NULL;

	if (hit_flag == true)
	{
		if (enemynum == 1)
			hit_data = hit->SearchObjNameHit(OBJ_WOLKENEMY);
		else if (enemynum == 2)
			hit_data = hit->SearchObjNameHit(OBJ_LOCKENEMY);
		else if (enemynum == 3)
			hit_data = hit->SearchObjNameHit(OBJ_FLYENEMY);
		else if (enemynum == 4)
			hit_data = hit->SearchObjNameHit(OBJ_BOSS1);
		else if (enemynum == 5)
			hit_data = hit->SearchObjNameHit(OBJ_BOSS2);

		hit_flag = false;

		for (int i = 0; i < hit->GetCount(); i++)
		{

			//�G�̍��E�ɓ���������
			if (hit_data[i] != NULL)
			{
				float r = hit_data[i]->r;
				if ((r < 45 && r >= 0) || r > 315)
				{
					m_vx = -1.2f;//���Ɉړ�
				}
				if (r > 135 && r < 225)
				{
					m_vx = +1.2f;//�E�Ɉړ�
				}
				if (r >= 225 && r < 315)
				{
					//�G�̈ړ���������l���̈ʒu�ɉ��Z
					if(enemynum==1)
					m_px += ((CObjWolkEnemy*)hit_data[i]->o)->GetVx();
					if (enemynum == 4)
						m_px += ((CObjBoss1*)hit_data[i]->o)->GetVx();
					


					//����X�N���[�����C��
					if (m_px < 80)
					{
						
							pb->SetScroll(pb->GetScroll() - 5.0);
					
					}

					//�O���X�N���[�����C��
					if (m_px > 300)
					{
						m_px = 300;
						
							pb->SetScroll(pb->GetScroll() - 5.0);
						
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
	}
	if (hit_flag == false)
		hit_flag = true;
}