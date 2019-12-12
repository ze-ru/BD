#include"GameL\DrawTexture.h"
#include"GameL\WinInputs.h"
#include"GameL\SceneManager.h"
#include"GameL\HitBoxManager.h"

#include"GameHead.h"
#include"HeroNormalBullet.h"

using namespace GameL;

CObjShield::CObjShield(float x, float y)
{
	m_ex = x-4.0f;
	m_ey = y;
}
void CObjShield::Init()
{
	CObjHero*h = (CObjHero*)Objs::GetObj(OBJ_HERO);
	m_time = 0;
	
	
	
	m_vx = 0;
	m_vy = 0;
	m_hit_up = false;
	m_hit_down = false;
	m_hit_left = false;
	m_hit_right = false;
	m_posture = 0;
	hit_flag = false;
	dm = 5;
	m_hit = 0;
	m_dead = false;

	m_time_hit = false;

	m_attack = false;

	m_count = 0;
	m_hit_flag = false;
	Hits::SetHitBox(this, m_ex, m_ey, 32, 64, ELEMENT_SHIELD, OBJ_SHIELD, 1);
}
void CObjShield::Action()
{
	
	CObjHero*objh = (CObjHero*)Objs::GetObj(OBJ_HERO);
	CObjBlock*block = (CObjBlock*)Objs::GetObj(OBJ_BLOCK);
	CHitBox*hit = Hits::GetHitBox(this);

	CObjShieldEnemy*se = (CObjShieldEnemy*)Objs::GetObj(OBJ_SHIELDENEMY);
	m_posture = se->GetPos();
	
	if (m_posture == 1.0f)
	{
		m_ex = se->GetX()+38.0f;
	}
	if (m_posture == 0.0f)
	{
		m_ex = se->GetX();
	}
	
		
	

	CObjStageUi*ui = (CObjStageUi*)Objs::GetObj(OBJ_STAGEUI);
	if (hit->CheckElementHit(ELEMENT_HEROASSULTBULLET) == true && hit_flag == false)
	{
		hit_flag = true;
		CObjDamege*dm = new CObjDamege(0, m_ex, m_ey);
		Objs::InsertObj(dm, OBJ_DAMEGE, 20);
	}
	else if (hit->CheckElementHit(ELEMENT_HERONORMALBULLET) == true && hit_flag == false)
	{
		se->SetShield();
		this->SetStatus(false);//自身に削除命令を出す
		Hits::DeleteHitBox(this);//保有するHitBoxに削除する
	}
	if (hit->CheckObjNameHit(OBJ_ASSAULT_BULLET) != nullptr)
	{
		hit_flag = true;
		CObjDamege*dm = new CObjDamege(0, m_ex, m_ey);
		Objs::InsertObj(dm, OBJ_DAMEGE, 20);
	}
	if (hit->CheckObjNameHit(OBJ_NORMAL_BULLET) != nullptr)
	{
		hit_flag = true;
		CObjDamege*dm = new CObjDamege(0, m_ex, m_ey);
		Objs::InsertObj(dm, OBJ_DAMEGE, 20);
	}
	else if (hit->CheckElementHit(ELEMENT_ATTACK) == true && hit_flag == false)
	{
		se->SetShield();
		this->SetStatus(false);//自身に削除命令を出す
		Hits::DeleteHitBox(this);//保有するHitBoxに削除する
	}
	if (hit_flag == true)
	{
		m_time_hit++;
		if (m_time_hit > 10)
		{
			hit_flag = false;
			m_time_hit = 0;
		}

	}
	if (m_dead == true)
	{
		this->SetStatus(false);//自身に削除命令を出す
		Hits::DeleteHitBox(this);//保有するHitBoxに削除する
	}
	if (Input::GetVKey('S') == true || (objh->GetX() - block->GetScroll()) > 17920)
	{
		this->SetStatus(false);//自身に削除命令を出す
		Hits::DeleteHitBox(this);//保有するHitBoxに削除する
	}

	

	
		if (hit->CheckElementHit(ELEMENT_PLAYER) == true)
		{
			if (m_hit_flag == false)
			{
				m_hit_flag = true;
				if (objh->GetYflag() == false)
					objh->SetDamege(dm);
				if (objh->GetX() + 32 - block->GetScroll() > m_ex)
					objh->SetHitflag(true);
				if (objh->GetX() + 32 - block->GetScroll() < m_ex)
					objh->SetHitflag(false);
			}
		}
		else if (hit->CheckElementHit(ELEMENT_PLAYER) == false)
		{
			m_hit_flag = false;
		}
	
	hit->SetPos(m_ex + block->GetScroll(), m_ey);
}
void CObjShield::Draw()
{
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src;
	RECT_F dst;

	src.m_top = 0.0f;
	src.m_left = 128.0f;
	src.m_right = 160.0f;
	src.m_bottom = 64.0f;


	CObjBlock*block = (CObjBlock*)Objs::GetObj(OBJ_BLOCK);
	//
	dst.m_top = 0.0f + m_ey;
	dst.m_left = (32.0f*m_posture) + m_ex + block->GetScroll();
	dst.m_right = (32 - 32.0f*m_posture) + m_ex + block->GetScroll();
	dst.m_bottom = 64.0f + m_ey;


	//
	Draw::Draw(22, &src, &dst, c, 0.0f);
}

