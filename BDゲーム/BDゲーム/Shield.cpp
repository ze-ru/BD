#include"GameL\DrawTexture.h"
#include"GameL\WinInputs.h"
#include"GameL\SceneManager.h"
#include"GameL\HitBoxManager.h"

#include"GameHead.h"
#include"HeroNormalBullet.h"

using namespace GameL;

CObjShield::CObjShield(float x, float y)
{
	m_ex = x;
	m_ey = y;
}
void CObjShield::Init()
{
	CObjHero*h = (CObjHero*)Objs::GetObj(OBJ_HERO);
	m_time = 0;
	if (h->GetFlag() == false)
	{
		m_vx = 10.0f;//右向き0.0f 左向き1.0f
	}
	if (h->GetFlag() == true)
	{
		m_vx = -10.0f;//右向き0.0f 左向き1.0f
	}
	m_py = h->GetY();

	m_vy = 0;
	m_hit_up = false;
	m_hit_down = false;
	m_hit_left = false;
	m_hit_right = false;
	m_posture = 0;
	hit_flag = false;
	dm = 20;
	m_hit = 0;
	m_dead = false;

	m_time_hit = false;
	Hits::SetHitBox(this, m_ex, m_ey, 32, 64, ELEMENT_SHIELD, OBJ_SHIELD, 1);
}
void CObjShield::Action()
{
	if (m_dead == true)
	{
		this->SetStatus(false);//自身に削除命令を出す
		Hits::DeleteHitBox(this);//保有するHitBoxに削除する
	}
	CObjBlock*block = (CObjBlock*)Objs::GetObj(OBJ_BLOCK);
	CHitBox*hit = Hits::GetHitBox(this);

	CObjShieldEnemy*se = (CObjShieldEnemy*)Objs::GetObj(OBJ_SHIELDENEMY);
	m_posture = se->GetPos();
	m_ex = se->GetX()-4.0f;
	m_ey = se->GetY();
	if (m_posture == 1.0f)
	{
		m_ex += 38.0f;
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

