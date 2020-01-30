#include"GameL\DrawTexture.h"
#include"GameL\WinInputs.h"
#include"GameL\SceneManager.h"
#include"GameL\HitBoxManager.h"

#include"GameHead.h"
#include"LockEnemy2.h"

#include"GameL\Audio.h"

using namespace GameL;

CObjLockEnemy2::CObjLockEnemy2(float x, float y)
{
	m_ex = x;
	m_ey = y;
}
void CObjLockEnemy2::Init()
{
	m_vy = 0;
	m_vx = 0;
	m_ani_time = 0;
	m_ani_frame = 0;
	m_posture = 0;

	m_hit_up = false;
	m_hit_down = false;
	m_hit_left = false;
	m_hit_right = false;
	hit_flag = false;
	m_hp = 40;
	score = 100;
	m_time = 0;
	attack_time = 1.0f;

	m_eff.m_top = 0;
	m_eff.m_left = 0;
	m_eff.m_right = 0;
	m_eff.m_bottom = 0;

	ani = 0;
	ani_time = 0;
	m_del = false;
	Hits::SetHitBox(this, m_ex, m_ey, 64, 64, ELEMENT_ENEMY, OBJ_LOCKENEMY2, 1);
}

void CObjLockEnemy2::Action()
{
	CObjHero*objh = (CObjHero*)Objs::GetObj(OBJ_HERO);
	m_ani_time++;

	if (m_ani_time > 60 && m_ani_time < 100)
	{
		attack_time = 0.0f;
	}
	if (m_ani_time == 120)
	{
		CObjNormalBullet*objNB = (CObjNormalBullet*)Objs::GetObj(OBJ_NORMAL_BULLET);
		CObjNormalBullet*objbullet = new CObjNormalBullet(m_ex, m_ey);
		Objs::InsertObj(objbullet, OBJ_NORMAL_BULLET, 50);
		attack_time = 1.0f;
	}
	if (m_ani_time > 130)
	{
		m_ani_time = 0;
	}
	//�e�ۏ��ŏ���
	if (m_del == true)
	{
		Audio::Start(11);
		//Resouces�̕`�敨��RECT
		m_eff = GetBulletEffect(&ani, &ani_time, m_del, 2);
		//���e�A�j���[�V�����I���Ŗ{���ɃI�u�W�F�N�g�̔j��
		if (ani == 4)
		{
			CObjStage1Clear*s1c = (CObjStage1Clear*)Objs::GetObj(OBJ_STAGE1CLEAR);

			s1c->SetScore(score);
			CObjStageUi*su = (CObjStageUi*)Objs::GetObj(OBJ_STAGEUI);

			su->GetScore(score);

			this->SetStatus(false);
			Hits::DeleteHitBox(this);
			Audio::Stop(11);
		}
		return;//���ŏ����́A�����ŃA�N�V�������\�b�h���I��������
	}


	//�u���b�N�Ƃ̓����蔻����s
	CObjBlock*pb = (CObjBlock*)Objs::GetObj(OBJ_BLOCK);

	CHitBox*hit = Hits::GetHitBox(this);
	if (pb->Getmap1() == 0)
	{

		pb->BlockHit(&m_ex, &m_ey, false,
			&m_hit_up, &m_hit_down, &m_hit_left, &m_hit_right,
			&m_vx, &m_vy);

	}

	CObjStageUi*ui = (CObjStageUi*)Objs::GetObj(OBJ_STAGEUI);
	hit->SetPos(m_ex + pb->GetScroll(), m_ey);
	if (hit->CheckElementHit(ELEMENT_HEROASSULTBULLET) == true && hit_flag == false)
	{
		m_hp -= 10;
		hit_flag = true;
		CObjDamege*dm = new CObjDamege(10, m_ex, m_ey);
		Objs::InsertObj(dm, OBJ_DAMEGE, 20);
		Audio::Start(12);
	}
	if (hit->CheckElementHit(ELEMENT_HERONORMALBULLET) == true && hit_flag == false)
	{
		m_hp -= 20;
		hit_flag = true;
		CObjDamege*dm = new CObjDamege(20, m_ex, m_ey);
		Objs::InsertObj(dm, OBJ_DAMEGE, 20);
		Audio::Start(12);
	}

	if (hit->CheckElementHit(ELEMENT_ATTACK) == true && hit_flag == false)
	{
		m_hp -= 15;
		hit_flag = true;
		CObjDamege*dm = new CObjDamege(15, m_ex, m_ey);
		Objs::InsertObj(dm, OBJ_DAMEGE, 20);
		Audio::Start(12);
	}
	if (hit->CheckElementHit(ELEMENT_LASERBULLET) == true && hit_flag == false)
	{
		m_hp -= 40;
		hit_flag = true;
		CObjDamege*dm = new CObjDamege(40, m_ex, m_ey);
		Objs::InsertObj(dm, OBJ_DAMEGE, 20);
		Audio::Start(12);
	}

	if (hit_flag == true)
	{
		m_time++;
		Audio::Stop(12);
		if (m_time > 10)
		{
			hit_flag = false;
			m_time = 0;

		}

	}
	if (m_hp <= 0)
	{
		m_del = true;

	}
	if (/*Input::GetVKey('U') == true ||*/ (objh->GetX() - pb->GetScroll()) > 17920)
	{
		this->SetStatus(false);//���g�ɍ폜���߂��o��
		Hits::DeleteHitBox(this);//�ۗL����HitBox�ɍ폜����
	}

	if (m_ex - 700 > objh->GetX() - pb->GetScroll())
	{
		m_ani_time = 0;
	}

	if (m_ex + 700 < objh->GetX() - pb->GetScroll())
	{
		m_ani_time = 0;
	}
}
void CObjLockEnemy2::Draw()
{
	float c[4] = { 1.0f,1.0f,attack_time,1.0f };

	RECT_F src;
	RECT_F dst;


	//�u���b�N���������Ă���
	CObjBlock*pb = (CObjBlock*)Objs::GetObj(OBJ_BLOCK);

	if (hit_flag == false)
	{

	src.m_top = 64.0f;
	src.m_left = 256.0f;
	src.m_right = 320.0f;
	src.m_bottom = 128.0f;

	
		dst.m_top = 0.0f + m_ey;
		dst.m_left = 64 - 64.0f + m_ex + pb->GetScroll();
		dst.m_right = 64.0f + m_ex + pb->GetScroll();
		dst.m_bottom = 64.0f + m_ey;



		//
		Draw::Draw(4, &src, &dst, c, 0.0f);
	}
	dst.m_top = 0.0f + m_ey;
	dst.m_left = 0.0f + m_ex + pb->GetScroll();
	dst.m_right = 64.0f + m_ex + pb->GetScroll();
	dst.m_bottom = 64.0f + m_ey;

	Draw::Draw(23, &m_eff, &dst, c, 0.0f);
}