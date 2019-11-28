#include "GameL\DrawTexture.h"
#include "GameL\WinInputs.h"
#include "GameL\SceneManager.h"
#include "GameL\HitBoxManager.h"

#include "GameHead.h"
#include "WolkEnemy.h"


//
using namespace GameL;

CObjWolkEnemy::CObjWolkEnemy(float x,float y)
{
	m_ex = x;//
	m_ey = y;
}
//
void CObjWolkEnemy::Init()
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
	//当たり判定用のHitBoxを作成
	Hits::SetHitBox(this, m_ex, m_ey, 64, 64, ELEMENT_ENEMY, OBJ_WOLKENEMY, 1);

}

//
void CObjWolkEnemy::Action()
{
	//通常速度
	m_speed_power = 0.1f;
	m_ani_max_time = 6;

	CObjHero*objh = (CObjHero*)Objs::GetObj(OBJ_HERO);
	
	CObjBlock*pb = (CObjBlock*)Objs::GetObj(OBJ_BLOCK);
	
	CHitBox*hit = Hits::GetHitBox(this);
	
	

	//ブロック衝突で向き変更(仮)
	/*if (m_hit_left == true)
	{
		m_move = false;
	}
	if (m_hit_right == true)
	{
		m_move = true;
	}*/

	//方向
	if (m_move==true)
	{
		m_vx += m_speed_power;
		m_posture = 1.0f;
		m_ani_time += 1;
		
	}
	if (m_move==false)
	{
		m_vx -= m_speed_power;
		m_posture = 0.0f;
		m_ani_time += 1;
	}

	if (m_ani_time > m_ani_max_time)
	{
		m_ani_frame += 1;
		m_ani_time = 0;
	}

	if (m_ani_frame == 4)
	{
		m_ani_frame = 0;
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
		m_vx *= -1;
	}



	//位置の更新
   	m_ex += m_vx;
	m_ey += m_vy ;

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
	
	
	hit->SetPos(m_ex + pb->GetScroll(), m_ey);
	


	
	CObjStageUi*ui = (CObjStageUi*)Objs::GetObj(OBJ_STAGEUI);
	if (hit->CheckElementHit(ELEMENT_ATTACK) == true)
	{
		if (m_hp > 0)
			m_hp -= 30;
		CObjDamege*dm = new CObjDamege(30, m_ex, m_ey);
		Objs::InsertObj(dm, OBJ_DAMEGE, 20);
	}
	if (hit->CheckElementHit(ELEMENT_HEROASSULTBULLET) == true)
	{
		if (m_hp > 0)
			m_hp -= 5;
		CObjDamege*dm = new CObjDamege(5, m_ex, m_ey);
		Objs::InsertObj(dm, OBJ_DAMEGE, 20);
	}
	if (hit_flag == true)
	{
		m_time_hit++;
		if (m_time_hit > 20)
		{
			hit_flag = false;
			m_time_hit = 0;
		}

	}
	if (m_hp <= 0)
	{
		m_time++;
		if (m_time >10&&m_time<20)
		{
			if(m_move==false)
			m_dead += 1.0f;
			if (m_move == true)
				m_dead -= 1.0f;
		}
		if(m_time==50)
		{
			CObjStage1Clear*s1c = (CObjStage1Clear*)Objs::GetObj(OBJ_STAGE1CLEAR);
			
			s1c->SetScore();
			CObjStageUi*su = (CObjStageUi*)Objs::GetObj(OBJ_STAGEUI);

			su->GetScore(score);
			this->SetStatus(false);//自身に削除命令を出す
			Hits::DeleteHitBox(this);//保有するHitBoxに削除する
		}
	}
	if (Input::GetVKey('S') == true)
	{
		this->SetStatus(false);//自身に削除命令を出す
		Hits::DeleteHitBox(this);//保有するHitBoxに削除する
	}
	
}

//
void CObjWolkEnemy::Draw()
{
	int AniData[4]=
	{
		0,1,0,1,
	};
	//
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src;
	RECT_F dst;


	src.m_top = 0.0f;
	src.m_left = 0.0f + AniData[m_ani_frame] * 64;
	src.m_right = 64.0f + AniData[m_ani_frame] * 64;
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
	Draw::Draw(3, &src, &dst, c, m_dead);
}