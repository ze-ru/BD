#include"GameL\DrawTexture.h"
#include"GameL\WinInputs.h"
#include"GameL\SceneManager.h"
#include"GameL\HitBoxManager.h"

#include"GameHead.h"
#include"LockEnemy.h"

using namespace GameL;

CObjLockEnemy::CObjLockEnemy(float x, float y)
{
	m_ex = x;
	m_ey = y;
}
void CObjLockEnemy::Init()
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
	Hits::SetHitBox(this, m_ex, m_ey, 64, 64, ELEMENT_ENEMY, OBJ_LOCKENEMY, 1);
}

void CObjLockEnemy::Action()
{
	
	m_ani_time++;

	if (m_ani_time > 60 && m_ani_time < 100)
	{
		attack_time=0.0f;
	}
	if (m_ani_time > 120)
	{
		m_ani_time = 0;

		CObjNormalBullet*objNB = (CObjNormalBullet*)Objs::GetObj(OBJ_NORMAL_BULLET);
			CObjNormalBullet*objbullet = new CObjNormalBullet(m_ex,m_ey);
			Objs::InsertObj(objbullet, OBJ_NORMAL_BULLET, 10);
			attack_time = 1.0f;
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
		}
		if (hit->CheckElementHit(ELEMENT_HERONORMALBULLET) == true && hit_flag == false)
		{
			m_hp -= 20;
			hit_flag = true;
			CObjDamege*dm = new CObjDamege(20, m_ex, m_ey);
			Objs::InsertObj(dm, OBJ_DAMEGE, 20);
		}
		if (hit->CheckElementHit(ELEMENT_ATTACK) == true&&hit_flag == false)
		{
			m_hp -= 15;
			hit_flag = true;
			CObjDamege*dm = new CObjDamege(15, m_ex, m_ey);
			Objs::InsertObj(dm, OBJ_DAMEGE, 20);
		}
	if (hit_flag == true)
	{
		m_time++;
		if (m_time > 10)
		{
			hit_flag = false;
			m_time = 0;
		}

	}
	if (m_hp <= 0)
	{
		CObjStage1Clear*s1c = (CObjStage1Clear*)Objs::GetObj(OBJ_STAGE1CLEAR);
		
		s1c->SetScore();
		CObjStageUi*su = (CObjStageUi*)Objs::GetObj(OBJ_STAGEUI);
		
		su->GetScore(score);
		this->SetStatus(false);//���g�ɍ폜���߂��o��
		Hits::DeleteHitBox(this);//�ۗL����HitBox�ɍ폜����
	}
	if (Input::GetVKey('S') == true)
	{
		this->SetStatus(false);//���g�ɍ폜���߂��o��
		Hits::DeleteHitBox(this);//�ۗL����HitBox�ɍ폜����
	}
}
void CObjLockEnemy::Draw()
{
	float c[4] = { 1.0f,1.0f,attack_time,1.0f };

	RECT_F src;
	RECT_F dst;


	//�u���b�N���������Ă���
	

	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 64.0f;
	src.m_bottom = 64.0f;

	CObjBlock*pb = (CObjBlock*)Objs::GetObj(OBJ_BLOCK);
	
	if (hit_flag == false)
	{
		dst.m_top = 0.0f + m_ey;
		dst.m_left = 64 - 64.0f + m_ex + pb->GetScroll();
		dst.m_right = 64.0f + m_ex + pb->GetScroll();
		dst.m_bottom = 64.0f + m_ey;
	}
	

	//
	Draw::Draw(4, &src, &dst, c, 0.0f);
}