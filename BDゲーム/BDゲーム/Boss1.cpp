#include "GameL\DrawTexture.h"
#include "GameL\WinInputs.h"
#include "GameL\SceneManager.h"
#include "GameL\HitBoxManager.h"

#include "GameHead.h"
#include "Boss1.h"


//
using namespace GameL;

CObjBoss1::CObjBoss1(float x, float y)
{
	m_ex = x+64.0f;//
	m_ey = y-64.0f;
}
//
void CObjBoss1::Init()
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
	m_hp = 150;
	m_dead = 0;
	hit_flag = false;
	m_time = 0;
	attacktime = 0;
	dead_flag = false;
	time2 = 0;

	jamptime = 0;
}

//
void CObjBoss1::Action()
{
	CObjBlock*pb = (CObjBlock*)Objs::GetObj(OBJ_BLOCK);
	CHitBox*hit = Hits::GetHitBox(this);
	if(time<300)
	time2++;
	time++;

	if (time > 0 && time < 150)
	{
		m_vx = -1.0f;
		if (time > 0 && time < 100)
		{
			attacktime++;
			if (attacktime == 10)
			{
				CObjAssaultBullet*objABullet = new CObjAssaultBullet(m_ex + 70, m_ey + 70);
				Objs::InsertObj(objABullet, OBJ_ASSAULT_BULLET, 20);
				attacktime = 0;
			}
		}
	}
	if (time > 150 && time < 300)
	{
		m_vx = 1.0f;
		if (time > 150 && time < 250)
		{
			attacktime++;
			if (attacktime == 10)
			{
				CObjAssaultBullet*objABullet = new CObjAssaultBullet(m_ex + 70, m_ey + 70);
				Objs::InsertObj(objABullet, OBJ_ASSAULT_BULLET, 20);
				attacktime = 0;
			}
		}
	}
	switch (time2)
	{
	case 50:
	{
		CObjNormalBullet*objbullet = new CObjNormalBullet(m_ex, m_ey+10);
		Objs::InsertObj(objbullet, OBJ_NORMAL_BULLET, 20);
	}
	case 100:
	{
		CObjNormalBullet*objbullet = new CObjNormalBullet(m_ex, m_ey+10);
		Objs::InsertObj(objbullet, OBJ_NORMAL_BULLET, 20);
	}
	case 150:
	{
		CObjNormalBullet*objbullet = new CObjNormalBullet(m_ex, m_ey+10);
		Objs::InsertObj(objbullet, OBJ_NORMAL_BULLET, 20);
	}
	}

	pb->BlockBossHit(&m_ex, &m_ey, false,
		&m_hit_up, &m_hit_down, &m_hit_left, &m_hit_right,
		&m_vx, &m_vy);

	    //自由落下
		m_vy += 5.0 / (20.0f);

		/*jamptime++;

		if (jamptime%100==0)
		{
			if (m_hit_down == true)
			{
				if (m_vy >= 0)
					m_vy = -10.5;
			}
			
		}*/
	
	
	m_ex += m_vx;
	m_ey += m_vy;

	hit->SetPos(m_ex + pb->GetScroll(), m_ey);

	CObjStageUi*ui = (CObjStageUi*)Objs::GetObj(OBJ_STAGEUI);
	if (hit->CheckElementHit(ELEMENT_ATTACK) == true)
	{
		if (m_hp > 0)
			m_hp -= 30;
		ui->setdm(30);
		hit_flag = true;
		ui->hitflag(hit_flag);
		ui->setpos(m_ex, m_ey);
		time2 = 0;
	}
	if (hit->CheckElementHit(ELEMENT_HEROASSULTBULLET) == true)
	{
		if (m_hp > 0)
			m_hp -= 5;
		ui->setdm(5);
		hit_flag = true;
		ui->hitflag(hit_flag);
		ui->setpos(m_ex, m_ey);
		time2 = 0;
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
			CObjStage1Clear*s1c = (CObjStage1Clear*)Objs::GetObj(OBJ_STAGE1CLEAR);
			s1c->Setdead();
			pb->SetDead();
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
void CObjBoss1::Draw()
{
	
	//
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src;
	RECT_F dst;


	src.m_top = 32.0f;
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
	Draw::Draw(14, &src, &dst, c, m_dead);
}