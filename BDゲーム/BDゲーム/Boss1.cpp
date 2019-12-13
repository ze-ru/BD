#include "GameL\DrawTexture.h"
#include "GameL\WinInputs.h"
#include "GameL\SceneManager.h"
#include "GameL\HitBoxManager.h"

#include "GameHead.h"
#include "Boss1.h"
#include"GameL\Audio.h"


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
	m_hp = 300;
	m_dead = 0;
	hit_flag = false;
	m_time = 0;
	attacktime = 0;
	dead_flag = false;
	time2 = 0;
	m_time_hit = 0;

	m_eff.m_top = 0;
	m_eff.m_left = 0;
	m_eff.m_right = 0;
	m_eff.m_bottom = 0;

	ani = 0;
	ani_time = 0;
	m_del = false;

	moveflag = false;//右向き = true,左向き = false;
}

//
void CObjBoss1::Action()
{
	CObjHero*objh = (CObjHero*)Objs::GetObj(OBJ_HERO);
	CObjBlock*pb = (CObjBlock*)Objs::GetObj(OBJ_BLOCK);
	CHitBox*hit = Hits::GetHitBox(this);
	if(time<=300)
	time2++;
	time++;
	//弾丸消滅処理
	if (m_del == true)
	{
		Audio::Start(11);
		//Resoucesの描画物のRECT
		m_eff = GetBulletEffect(&ani, &ani_time, m_del, 2);
		//着弾アニメーション終了で本当にオブジェクトの破棄
		if (ani == 4)
		{
			CObjStage1Clear*s1c = (CObjStage1Clear*)Objs::GetObj(OBJ_STAGE1CLEAR);
			s1c->Setdead();
			pb->SetDead();
			Audio::Stop(11);
			this->SetStatus(false);//自身に削除命令を出す
			Hits::DeleteHitBox(this);//保有するHitBoxに削除する
		}
		return;//消滅処理は、ここでアクションメソッドを終了させる
	}

	if (time > 0 && time < 150)
	{
		if (time > 0 && time < 100)
		{
			attacktime++;
			if (attacktime == 10)
			{
				CObjAssaultBullet*objABullet = new CObjAssaultBullet(m_ex + 70, m_ey + 70);
				Objs::InsertObj(objABullet, OBJ_ASSAULT_BULLET, 50);
				attacktime = 0;
			}
		}
	}
	if (time > 150 && time < 300)
	{
		if (time > 150 && time < 250)
		{
			attacktime++;
			if (attacktime == 10)
			{
				CObjAssaultBullet*objABullet = new CObjAssaultBullet(m_ex + 70, m_ey + 70);
				Objs::InsertObj(objABullet, OBJ_ASSAULT_BULLET, 50);
				attacktime = 0;
			}
		}
	}
	switch (time2)
	{
	case 50:
	{
		CObjNormalBullet*objbullet = new CObjNormalBullet(m_ex, m_ey+10);
		Objs::InsertObj(objbullet, OBJ_NORMAL_BULLET, 50);
	}
	case 100:
	{
		CObjNormalBullet*objbullet = new CObjNormalBullet(m_ex, m_ey+10);
		Objs::InsertObj(objbullet, OBJ_NORMAL_BULLET, 50);
	}
	case 150:
	{
		CObjNormalBullet*objbullet = new CObjNormalBullet(m_ex, m_ey+10);
		Objs::InsertObj(objbullet, OBJ_NORMAL_BULLET, 50);
	}
	}

	pb->BlockBossHit(&m_ex, &m_ey, false,
		&m_hit_up, &m_hit_down, &m_hit_left, &m_hit_right,
		&m_vx, &m_vy);

	//自由落下
	m_vy += 5.0 / (20.0f);

	if (m_ex > objh->GetX() - pb->GetScroll())
	{
		moveflag = true;
		m_vx = 1.0f;
	}

	if (m_ex < objh->GetX() - pb->GetScroll())
	{
		moveflag = false;
		m_vx = -1.0f;
	}
	if (m_ex > 295 * 64)
	{
		m_vx = -1.0f;
	}
	if (m_ex < 290 * 64)
	{
		m_vx = 1.0f;
	}
	if (time == 300)
	{
		time = 0;
	}
	m_ex += m_vx;
	m_ey += m_vy;



	
	hit->SetPos(m_ex + pb->GetScroll(), m_ey);

	CObjStageUi*ui = (CObjStageUi*)Objs::GetObj(OBJ_STAGEUI);
	if (hit->CheckElementHit(ELEMENT_HEROASSULTBULLET) == true && hit_flag == false)
	{
		m_hp -= 10;
		hit_flag = true;
		CObjDamege*dm = new CObjDamege(10, m_ex, m_ey);
		Objs::InsertObj(dm, OBJ_DAMEGE, 20);
		time2 = 0;
		Audio::Start(12);
	}
	else if (hit->CheckElementHit(ELEMENT_HERONORMALBULLET) == true && hit_flag == false)
	{
		m_hp -= 20;
		hit_flag = true;
		CObjDamege*dm = new CObjDamege(20, m_ex, m_ey);
		Objs::InsertObj(dm, OBJ_DAMEGE, 20);
		time2 = 0;
		Audio::Start(12);
	}
	else if (hit->CheckElementHit(ELEMENT_ATTACK) == true && hit_flag == false)
	{
		m_hp -= 15;
		hit_flag = true;
		CObjDamege*dm = new CObjDamege(15, m_ex, m_ey);
		Objs::InsertObj(dm, OBJ_DAMEGE, 20);
		time2 = 0;
		Audio::Start(12);
	}
	else if (hit->CheckElementHit(ELEMENT_LASERBULLET) == true && hit_flag == false)
	{
		m_hp -= 60;
		hit_flag = true;
		CObjDamege*dm = new CObjDamege(60, m_ex, m_ey);
		Objs::InsertObj(dm, OBJ_DAMEGE, 20);
		time2 = 0;
		Audio::Start(12);
	}
	

	if (hit_flag == true)
	{
		Audio::Stop(12);
		m_time_hit++;
		if (m_time_hit > 10)
		{
			hit_flag = false;
			m_time_hit = 0;
			
		}

	}
	if (m_hp <= 0)
	{
		m_del = true;
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

	if (hit_flag == false && moveflag == true)
	{
		dst.m_top = m_ey;
		dst.m_left = m_ex + pb->GetScroll();
		dst.m_right = m_ex + 256.0f + pb->GetScroll();
		dst.m_bottom = m_ey + 192.0f;
	}
	else if (hit_flag == false && moveflag == false)
	{
		dst.m_top = m_ey;
		dst.m_left = m_ex + 256.0f + pb->GetScroll();
		dst.m_right = m_ex + pb->GetScroll();
		dst.m_bottom = m_ey + 192.0f;
	}

	
	//
	Draw::Draw(14, &src, &dst, c, m_dead);

	dst.m_top = 0.0f + m_ey;
	dst.m_left = 32.0f + m_ex + pb->GetScroll();
	dst.m_right = 224.0f + m_ex + pb->GetScroll();
	dst.m_bottom = 192.0f + m_ey;

	Draw::Draw(23, &m_eff, &dst, c, 0.0f);
}