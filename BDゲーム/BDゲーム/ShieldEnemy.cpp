#include "GameL\DrawTexture.h"
#include "GameL\WinInputs.h"
#include "GameL\SceneManager.h"
#include "GameL\HitBoxManager.h"

#include "GameHead.h"
#include "ShieldEnemy.h"


//
using namespace GameL;

CObjShieldEnemy::CObjShieldEnemy(float x, float y)
{
	m_ex = x;//
	m_ey = y;
}
//
void CObjShieldEnemy::Init()
{
	m_vx = 0.0f;//
	m_vy = 0.0f;
	m_posture = 0.0f;

	m_ani_time = 0;
	m_ani_frame = 0;

	m_speed_power = 0.1f;
	m_ani_max_time = 4;
	m_time = 0;

	m_move = false;//false=右　true=左
	m_hp = 30;
	m_hit_up = false;
	m_hit_down = false;
	m_hit_left = false;
	m_hit_right = false;
	hit_flag = false;
	m_dead = 0.0f;

	m_time_hit = 0;

	score = 100;

	dead = false;

	m_eff.m_top = 0;
	m_eff.m_left = 0;
	m_eff.m_right = 0;
	m_eff.m_bottom = 0;

	ani = 0;
	ani_time = 0;
	m_del = false;

	CObjShield*objs = new CObjShield(m_ex,m_ey);
	Objs::InsertObj(objs, OBJ_SHIELD, 20);

	//当たり判定用のHitBoxを作成
	Hits::SetHitBox(this, m_ex+20, m_ey, 44, 64, ELEMENT_ENEMY, OBJ_SHIELDENEMY, 1);

}

//
void CObjShieldEnemy::Action()
{
	CObjHero*objh = (CObjHero*)Objs::GetObj(OBJ_HERO);

	CObjBlock*pb = (CObjBlock*)Objs::GetObj(OBJ_BLOCK);

	CHitBox*hit = Hits::GetHitBox(this);

	//弾丸消滅処理
	if (m_del == true)
	{
		//Resoucesの描画物のRECT
		m_eff = GetBulletEffect(&ani, &ani_time, m_del, 4);
		//着弾アニメーション終了で本当にオブジェクトの破棄
		if (ani == 8)
		{
			this->SetStatus(false);
			Hits::DeleteHitBox(this);
		}
		return;//消滅処理は、ここでアクションメソッドを終了させる
	}
	if (m_hp > 0)
	{
		//通常速度
		m_speed_power = 0.1f;
		m_ani_max_time = 6;

		
		//方向
		if (m_move == true)
		{
			m_posture = 1.0f;
		}
		if (m_move == false)
		{
			m_posture = 0.0f;
		}

	
		if (m_hit_down == true)
		{
			m_vy = 0;
		}
		//摩擦
		m_vx += -(m_vx*0.098);

		//自由落下
		m_vy += 9.8f / (16.0f);

		if (hit->CheckElementHit(ELEMENT_PLAYER) == true)
		{
			m_vx =0;
		}



		//位置の更新
		m_ex += m_vx;
		m_ey += m_vy;

		//主人公の位置で向き変更

		if (m_ex > objh->GetX() - pb->GetScroll())
		{
			m_move = false;
		}

		if (m_ex < objh->GetX() - pb->GetScroll())
		{
			m_move = true;
		}

		//HitBoxの内容を更新

		pb->BlockHit(&m_ex, &m_ey, false,
			&m_hit_up, &m_hit_down, &m_hit_left, &m_hit_right,
			&m_vx, &m_vy);

		if (m_move == true)
			hit->SetPos(m_ex + pb->GetScroll(), m_ey);
		if (m_move == false)
			hit->SetPos(m_ex + 20 + pb->GetScroll(), m_ey);




		CObjStageUi*ui = (CObjStageUi*)Objs::GetObj(OBJ_STAGEUI);
		if (hit->CheckElementHit(ELEMENT_HEROASSULTBULLET) == true && hit_flag == false)
		{
			m_hp -= 10;
			hit_flag = true;
			CObjDamege*dm = new CObjDamege(10, m_ex, m_ey);
			Objs::InsertObj(dm, OBJ_DAMEGE, 20);
		}
		else if (hit->CheckElementHit(ELEMENT_HERONORMALBULLET) == true && hit_flag == false)
		{
			m_hp -= 20;
			hit_flag = true;
			CObjDamege*dm = new CObjDamege(20, m_ex, m_ey);
			Objs::InsertObj(dm, OBJ_DAMEGE, 20);
		}
		else if (hit->CheckElementHit(ELEMENT_ATTACK) == true && hit_flag == false)
		{
			m_hp -= 15;
			hit_flag = true;
			CObjDamege*dm = new CObjDamege(15, m_ex, m_ey);
			Objs::InsertObj(dm, OBJ_DAMEGE, 20);
		}
		else if (hit->CheckElementHit(ELEMENT_ENEMY_BULLET) == true && hit_flag == false)
		{
			m_hp -= 15;
			hit_flag = true;
			CObjDamege*dm = new CObjDamege(15, m_ex, m_ey);
			Objs::InsertObj(dm, OBJ_DAMEGE, 20);
		}
		else if (hit->CheckElementHit(ELEMENT_LASERBULLET) == true && hit_flag == false)
		{
			m_hp -= 60;
			hit_flag = true;
			CObjDamege*dm = new CObjDamege(60, m_ex, m_ey);
			Objs::InsertObj(dm, OBJ_DAMEGE, 20);
		}


		if (Input::GetVKey('S') == true || (objh->GetX() - pb->GetScroll()) > 17920)
		{
			this->SetStatus(false);//自身に削除命令を出す
			Hits::DeleteHitBox(this);//保有するHitBoxに削除する
		}
	}

	if (m_hp <= 0)
	{
		m_del = true;
		hit->SetPos(m_ex + pb->GetScroll(), m_ey);
		m_time++;
		if (m_time > 10 && m_time < 20)
		{
			if (m_move == false)
				m_dead += 1.0f;
			if (m_move == true)
				m_dead -= 1.0f;

		}
		if (m_time == 50)
		{
			if (dead == false)
			{
				CObjShield*shield = (CObjShield*)Objs::GetObj(OBJ_SHIELD);
				shield->SetDead();
			}
			
			CObjStage1Clear*s1c = (CObjStage1Clear*)Objs::GetObj(OBJ_STAGE1CLEAR);

			s1c->SetScore();
			CObjStageUi*su = (CObjStageUi*)Objs::GetObj(OBJ_STAGEUI);

			su->GetScore(score);
			
			this->SetStatus(false);//自身に削除命令を出す
			Hits::DeleteHitBox(this);//保有するHitBoxに削除する
		}
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
}

//
void CObjShieldEnemy::Draw()
{
	//
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src;
	RECT_F dst;


	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 64.0f;
	src.m_bottom = 64.0f;

	CObjBlock*pb = (CObjBlock*)Objs::GetObj(OBJ_BLOCK);

	if (hit_flag == false)
	{
		dst.m_top = 0.0f + m_ey;
		dst.m_left = (64.0f*m_posture) + m_ex + pb->GetScroll();
		dst.m_right = (64 - 64.0f*m_posture) + m_ex + pb->GetScroll();
		dst.m_bottom = 64.0f + m_ey;
	}
	//
	Draw::Draw(22, &src, &dst, c, m_dead);

	dst.m_top = 0.0f + m_ey;
	dst.m_left = 0.0f + m_ex + pb->GetScroll();
	dst.m_right = 64.0f + m_ex + pb->GetScroll();
	dst.m_bottom = 64.0f + m_ey;

	Draw::Draw(23, &m_eff, &dst, c, 0.0f);
}