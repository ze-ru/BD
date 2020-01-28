#include "GameL\DrawTexture.h"
#include "GameL\WinInputs.h"
#include "GameL\SceneManager.h"
#include "GameL\HitBoxManager.h"

#include "GameHead.h"
#include "Boss1.h"
#include"GameL\Audio.h"


using namespace GameL;
//

CObjBoss1::CObjBoss1(float x, float y)
{
	m_ex = x+64.0f;//
	m_ey = y-64.0f;
}
//
void CObjBoss1::Init()
{
	//変数の初期化
	m_vx = 0.0f;
	m_vy = 0.0f;

	m_hit_up = false;
	m_hit_down = false;
	m_hit_left = false;
	m_hit_right = false;

	time = 0;
	//当たり判定用のHitBoxを作成
	Hits::SetHitBox(this, m_ex, m_ey, 256, 192, ELEMENT_ENEMY, OBJ_BOSS1, 1);

	m_hp = 300;//HPを300に設定

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
	score = 1000;

	moveflag = false;//右向き = true,左向き = false;
}

//
void CObjBoss1::Action()
{
	CObjHero*objh = (CObjHero*)Objs::GetObj(OBJ_HERO);//Heroの情報を持ってくる
	CObjBlock*pb = (CObjBlock*)Objs::GetObj(OBJ_BLOCK);//Blockの情報を持ってくる

	CHitBox*hit = Hits::GetHitBox(this);
	if (time2 < 300)
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
			s1c->SetScore(score);
			s1c->Setdead();
			pb->SetDead();
			Audio::Stop(11);
			CObjStageUi*su = (CObjStageUi*)Objs::GetObj(OBJ_STAGEUI);
			su->GetScore(score);

			this->SetStatus(false);//自身に削除命令を出す
			Hits::DeleteHitBox(this);//保有するHitBoxに削除する
		}
		return;//消滅処理は、ここでアクションメソッドを終了させる
	}

	//Boss1の攻撃間隔設定
	if (time > 0 && time < 300)
	{
		if (time > 50 && time < 250)
		{
			attacktime++;
			if (attacktime == 25)
			{
				//AssaultBullet作成
				CObjAssaultBullet*objABullet = new CObjAssaultBullet(m_ex + 70, m_ey + 70);
				Objs::InsertObj(objABullet, OBJ_ASSAULT_BULLET, 50);
				attacktime = 0;
			}
		}
	}
	if (time > 300 && time < 600)
	{
		if (time > 350 && time < 550)
		{
			attacktime++;
			if (attacktime == 25)
			{
				//AssaultBullet作成
				CObjAssaultBullet*objABullet = new CObjAssaultBullet(m_ex + 70, m_ey + 70);
				Objs::InsertObj(objABullet, OBJ_ASSAULT_BULLET, 50);
				attacktime = 0;
			}
		}
	}
	switch (time2)
	{
	case 70:
	{
		if (moveflag == true)//Boss1が左向きの時
		{
			for (int i = 120; i <= 240; i += 120 / 6)
			{
				//角度iで角度弾丸発射
				CObjShotBullet*objsg = new CObjShotBullet(m_ex, m_ey + 10, i);
				Objs::InsertObj(objsg, OBJ_SHOT_BULLET, 15);
			}
		}
		if (moveflag == false)//Boss1が右向きの時
		{
			for (int i = 300; i < 360; i += 60 / 3)
			{
				//角度iで角度弾丸発射
				CObjShotBullet*objsg = new CObjShotBullet(m_ex+256, m_ey + 10, i);
				Objs::InsertObj(objsg, OBJ_SHOT_BULLET, 15);
			}
			for (int i = 0; i < 60; i += 60 / 3)
			{
				//角度iで角度弾丸発射
				CObjShotBullet*objsg = new CObjShotBullet(m_ex+256, m_ey + 10, i);
				Objs::InsertObj(objsg, OBJ_SHOT_BULLET, 15);
			}
		}
	}
	case 140:
	{
		if (moveflag == true)//Boss1が左向きの時
		{
			for (int i = 120; i <= 240; i += 120 / 6)
			{
				//角度iで角度弾丸発射
				CObjShotBullet*objsg = new CObjShotBullet(m_ex, m_ey + 10, i);
				Objs::InsertObj(objsg, OBJ_SHOT_BULLET, 15);
			}
		}
		if (moveflag == false)//Boss1が右向きの時
		{
			for (int i = 300; i < 360; i += 60 / 3)
			{
				//角度iで角度弾丸発射
				CObjShotBullet*objsg = new CObjShotBullet(m_ex+256, m_ey + 10, i);
				Objs::InsertObj(objsg, OBJ_SHOT_BULLET, 15);
			}
			for (int i = 0; i < 60; i += 60 / 3)
			{
				//角度iで角度弾丸発射
				CObjShotBullet*objsg = new CObjShotBullet(m_ex+256, m_ey + 10, i);
				Objs::InsertObj(objsg, OBJ_SHOT_BULLET, 15);
			}
		}
	}
	case 210:
	{
		if (moveflag == true)//Boss1が左向きの時
		{
			for (int i = 120; i <= 240; i += 120 / 6)
			{
				//角度iで角度弾丸発射
				CObjShotBullet*objsg = new CObjShotBullet(m_ex, m_ey + 10, i);
				Objs::InsertObj(objsg, OBJ_SHOT_BULLET, 15);
			}
		}
		if (moveflag == false)//Boss1が右向きの時
		{
			for (int i = 300; i < 360; i += 60 / 3)
			{
				//角度iで角度弾丸発射
				CObjShotBullet*objsg = new CObjShotBullet(m_ex+256, m_ey + 10, i);
				Objs::InsertObj(objsg, OBJ_SHOT_BULLET, 15);
			}
			for (int i = 0; i < 60; i += 60 / 3)
			{
				//角度iで角度弾丸発射
				CObjShotBullet*objsg = new CObjShotBullet(m_ex+256, m_ey + 10, i);
				Objs::InsertObj(objsg, OBJ_SHOT_BULLET, 15);
			}
		}
	}
	}

	//Boss1の当たり判定作成
	pb->BlockBossHit(&m_ex, &m_ey, false,
		&m_hit_up, &m_hit_down, &m_hit_left, &m_hit_right,
		&m_vx, &m_vy);

	//自由落下
	m_vy += 5.0 / (20.0f);

	//HeroがBoss1より左にいるとき
	if (m_ex > objh->GetX() - pb->GetScroll())
	{
		moveflag = true;//Boss1の向きを右向きに
		m_vx = 1.0f;//右に移動
	}
	//HeroがBoss1より右にいるとき
	if (m_ex < objh->GetX() - pb->GetScroll())
	{
		moveflag = false;//Boss1の向きを左向きに
		m_vx = -1.0f;//左に移動
	}

	if (m_ex > 295 * 64)
	{
		m_vx = -1.0f;
	}

	if (m_ex < 290 * 64)
	{
		m_vx = 1.0f;
	}

	//timeが600になったらtimeを初期化
	if (time == 600)
	{
		time = 0;
	}

	//位置の更新
	m_ex += m_vx;
	m_ey += m_vy;
	//HitBoxの更新
	hit->SetPos(m_ex + pb->GetScroll(), m_ey);

	//UIの作成
	CObjStageUi*ui = (CObjStageUi*)Objs::GetObj(OBJ_STAGEUI);

	//攻撃を受けたとき
	if (hit->CheckElementHit(ELEMENT_HEROASSULTBULLET) == true && hit_flag == false)
	{
		m_hp -= 10;
		hit_flag = true;
		CObjDamege*dm = new CObjDamege(10, m_ex, m_ey);
		Objs::InsertObj(dm, OBJ_DAMEGE, 20);
		if (time2 >= 300)
			time2 = 0;
		Audio::Start(12);
	}
	else if (hit->CheckElementHit(ELEMENT_HERONORMALBULLET) == true && hit_flag == false)
	{
		m_hp -= 20;
		hit_flag = true;
		CObjDamege*dm = new CObjDamege(20, m_ex, m_ey);
		Objs::InsertObj(dm, OBJ_DAMEGE, 20);
		if (time2 >= 300)
			time2 = 0;
		Audio::Start(12);
	}
	else if (hit->CheckElementHit(ELEMENT_ATTACK) == true && hit_flag == false)
	{
		m_hp -= 15;
		hit_flag = true;
		CObjDamege*dm = new CObjDamege(15, m_ex, m_ey);
		Objs::InsertObj(dm, OBJ_DAMEGE, 20);
		if (time2 >= 300)
			time2 = 0;
		Audio::Start(12);
	}
	else if (hit->CheckElementHit(ELEMENT_LASERBULLET) == true && hit_flag == false)
	{
		m_hp -= 40;
		hit_flag = true;
		CObjDamege*dm = new CObjDamege(40, m_ex, m_ey);
		Objs::InsertObj(dm, OBJ_DAMEGE, 20);
		if (time2 >= 300)
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