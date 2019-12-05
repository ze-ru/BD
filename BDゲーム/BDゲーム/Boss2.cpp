#include "GameL\DrawTexture.h"
#include "GameL\WinInputs.h"
#include "GameL\SceneManager.h"
#include "GameL\HitBoxManager.h"

#include "GameHead.h"
#include "Boss2.h"


//
using namespace GameL;

CObjBoss2::CObjBoss2(float x, float y)
{
	m_ex = x;//
	m_ey = y;
}
//
void CObjBoss2::Init()
{
	m_vx = 0;
	m_vy = 0;
	hit_flag = false;
	m_time = 0;
	enemy_flag = false;
	enemy_count = 0;
	dead_count = 0;
	m_hp = 300;
	m_hit_time = 0;
	m_hit_data = 0;
	m_hit_flag = false;

	hit_count = 0;
	Hits::SetHitBox(this, m_ex+100, m_ey+200, 200, 200, ELEMENT_BOSS2, OBJ_BOSS2, 1);
}

//
void CObjBoss2::Action()
{
	CObjBlock*pb = (CObjBlock*)Objs::GetObj(OBJ_BLOCK);
	CObjHero*h = (CObjHero*)Objs::GetObj(OBJ_HERO);
	CHitBox*hit = Hits::GetHitBox(this);
	if (hit_flag == false)
	{
		if (hit->CheckElementHit(ELEMENT_ATTACK) == true && m_hit_flag == false)
		{
			m_hp -= 15;
			m_hit_flag = true;
			m_hit_data += 15;
			CObjDamege*dm = new CObjDamege(15, m_ex, m_ey+200);
			Objs::InsertObj(dm, OBJ_DAMEGE, 20);
		}
		if (hit->CheckElementHit(ELEMENT_HEROASSULTBULLET) == true && m_hit_flag == false)
		{
			m_hp -= 10;
			m_hit_flag = true;
			m_hit_data += 10;
			CObjDamege*dm = new CObjDamege(10, m_ex, m_ey+200);
			Objs::InsertObj(dm, OBJ_DAMEGE, 20);
		}
		if (hit->CheckElementHit(ELEMENT_HERONORMALBULLET) == true&&m_hit_flag==false)
		{
			m_hp -= 20;
			m_hit_flag = true;
			m_hit_data += 20;
			CObjDamege*dm = new CObjDamege(20, m_ex, m_ey+200);
			Objs::InsertObj(dm, OBJ_DAMEGE, 20);
		}
		if (hit->CheckElementHit(ELEMENT_ATTACK) == true || hit->CheckElementHit(ELEMENT_HEROASSULTBULLET) == true || hit->CheckElementHit(ELEMENT_HERONORMALBULLET) == true)
		{
			if (m_hit_data >= 60)
			{
				hit_flag = true;
				m_hit_data = 0;
				hit_count++;
			}
		}
	}
	if (m_hit_flag == true)
	{
		m_hit_time++;
		if (m_hit_time > 10)
		{
			m_hit_flag = false;
			m_hit_time = 0;
		}

	}
	if (hit_flag == true)
	{
		if (m_time <= 50)
			m_time++;
		if (m_time == 50)
		{
			enemy_flag = true;
		}

		if (enemy_flag == true&&hit_count==1)
		{
			CObjBossEnemy*objF = new CObjBossEnemy(m_ex-500+(enemy_count*128), m_ey+544,90);
			Objs::InsertObj(objF, OBJ_BOSSENEMY, 15);
			enemy_count++;
		}
		if (enemy_flag == true && hit_count == 2)
		{
			CObjBossEnemy*objF = new CObjBossEnemy(m_ex - 500 + (enemy_count * 128), m_ey + 32,270);
			Objs::InsertObj(objF, OBJ_BOSSENEMY, 15);
			enemy_count++;
		}
		if (enemy_flag == true && hit_count == 3)
		{
			CObjBossEnemy*objF = new CObjBossEnemy(m_ex-24.0f, m_ey+32 + (enemy_count * 128),180);
			Objs::InsertObj(objF, OBJ_BOSSENEMY, 15);
			enemy_count++;
		}
		if (enemy_flag == true && hit_count == 4)
		{
			CObjBossEnemy*objF = new CObjBossEnemy(m_ex - (64 * 15), m_ey + (enemy_count * 128)+32.0f,0);
			Objs::InsertObj(objF, OBJ_BOSSENEMY, 15);
			enemy_count++;
		}
	
		if (enemy_count == 5)
		{
			enemy_flag = false;
			enemy_count = 0;
		}
		if (dead_count == 5)
		{
			hit_flag = false;
			dead_count = 0;
			m_time = 0;
		}
	}
	if (m_hp <= 0)
	{
			CObjStage1Clear*s1c = (CObjStage1Clear*)Objs::GetObj(OBJ_STAGE1CLEAR);
			s1c->Setdead();
			pb->SetDead();
			this->SetStatus(false);//自身に削除命令を出す
			Hits::DeleteHitBox(this);//保有するHitBoxに削除する
			
	}
	if (m_ex+pb->GetScroll()+20 <= h->GetX())
	{
		h->SetX(m_ex+pb->GetScroll()+20);
	}
	hit->SetPos(m_ex+100 + pb->GetScroll(), m_ey+200);
}

//
void CObjBoss2::Draw()
{

	//
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src;
	RECT_F dst;

	if (hit_flag == false)
	{
		src.m_top = 0.0f;
		src.m_left = 0.0f;
		src.m_right = 256.0f;
		src.m_bottom = 256.0f;
	}
	if (hit_flag == true)
	{
		src.m_top = 0.0f;
		src.m_left = 256.0f;
		src.m_right = 512.0f;
		src.m_bottom = 256.0f;
	}
	

	CObjBlock*pb = (CObjBlock*)Objs::GetObj(OBJ_BLOCK);

		dst.m_top = m_ey;
		dst.m_left = m_ex + pb->GetScroll();
		dst.m_right = m_ex + 400.0f + pb->GetScroll();
		dst.m_bottom = m_ey + 576.0f;



	//
	Draw::Draw(20, &src, &dst, c, 0.0f);
}