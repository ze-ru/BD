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
	m_vx = 0.0f;//
	m_vy = 0.0f;
	m_hit_up = false;
	m_hit_down = false;
	m_hit_left = false;
	m_hit_right = false;
	time = 0;
	//当たり判定用のHitBoxを作成
	Hits::SetHitBox(this, m_ex, m_ey, 256, 192, ELEMENT_ENEMY, OBJ_BOSS1, 1);
	m_hp = 50;
	m_dead = 0;
	hit_flag = false;
	m_time = 0;
	attacktime = 0;
	dead_flag = false;
}

//
void CObjBoss2::Action()
{
	CObjBlock*pb = (CObjBlock*)Objs::GetObj(OBJ_BLOCK);
	CHitBox*hit = Hits::GetHitBox(this);
	time++;

	if (time > 0 && time < 100)
	{
		m_vx = -1.0f;
		if (time > 30 && time < 80)
		{
			attacktime++;
			if (attacktime == 5)
			{
				CObjAssaultBullet*objABullet = new CObjAssaultBullet(m_ex + 70, m_ey + 100);
				Objs::InsertObj(objABullet, OBJ_ASSAULT_BULLET, 20);
				attacktime = 0;
			}
		}
	}
	if (time > 100 && time < 200)
	{
		m_vx = 1.0f;
		if (time > 130 && time < 180)
		{
			attacktime++;
			if (attacktime == 5)
			{
				CObjAssaultBullet*objABullet = new CObjAssaultBullet(m_ex + 70, m_ey + 100);
				Objs::InsertObj(objABullet, OBJ_ASSAULT_BULLET, 20);
				attacktime = 0;
			}
		}
	}
	switch (time)
	{
	case 50:
	{
		CObjNormalBullet*objbullet = new CObjNormalBullet(m_ex, m_ey + 30);
		Objs::InsertObj(objbullet, OBJ_NORMAL_BULLET, 20);
	}
	case 100:
	{
		CObjNormalBullet*objbullet = new CObjNormalBullet(m_ex, m_ey + 30);
		Objs::InsertObj(objbullet, OBJ_NORMAL_BULLET, 20);
	}
	case 150:
	{
		CObjNormalBullet*objbullet = new CObjNormalBullet(m_ex, m_ey + 30);
		Objs::InsertObj(objbullet, OBJ_NORMAL_BULLET, 20);
	}
	}
	if (time == 200)
		time = 0;


	pb->BlockBossHit(&m_ex, &m_ey, false,
		&m_hit_up, &m_hit_down, &m_hit_left, &m_hit_right,
		&m_vx, &m_vy);
	if (m_hit_down == false)
		m_vy += 5.0 / (20.0f);
	if (m_hit_down == true)
		m_vy = 0;
	m_ex += m_vx;
	m_ey += m_vy;

	hit->SetPos(m_ex + pb->GetScroll(), m_ey);


	if (hit->CheckElementHit(ELEMENT_ATTACK) == true)
	{
		if (m_hp > 0)
			m_hp -= 5;
		hit_flag = true;
	}

	if (m_hp <= 0)
	{
		m_time++;
		if (m_time > 10 && m_time < 20)
		{
			m_dead += 1.0f;
		}
		if (m_time == 50)
		{
			dead_flag = true;
			this->SetStatus(false);//自身に削除命令を出す
			Hits::DeleteHitBox(this);//保有するHitBoxに削除する
			m_time = 0;
		}
	}
	if (hit_flag == true)
	{
		m_time++;
		if (m_time > 20)
		{
			hit_flag = false;
			m_time = 0;
		}

	}

}

//
void CObjBoss2::Draw()
{

	//
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src;
	RECT_F dst;


	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 256.0f;
	src.m_bottom = 192.0f;

	CObjBlock*pb = (CObjBlock*)Objs::GetObj(OBJ_BLOCK);

	if (hit_flag == false)
	{
		dst.m_top = m_ey;
		dst.m_left = m_ex + pb->GetScroll();
		dst.m_right = m_ex + 256.0f + pb->GetScroll();
		dst.m_bottom = m_ey + 192.0f;
	}



	//
	Draw::Draw(16, &src, &dst, c, m_dead);
}