#include"GameL\DrawTexture.h"
#include"GameL\WinInputs.h"
#include"GameL\SceneManager.h"
#include "GameL\HitBoxManager.h"

#include"GameHead.h"
#include"BossEnemy.h"
#include"GameL\Audio.h"

using namespace GameL;

CObjBossEnemy::CObjBossEnemy(float x, float y,float kak)
{
	m_px = x;
	m_py = y;
	k = kak;
}

void CObjBossEnemy::Init()
{
	m_ani_time = 0;
	m_ani_frame = 0;
	//m_posture = 1;

	m_vx = 0.0f;
	m_vx = 0.0f;
	m_time = 0;
	m_hit_up = false;
	m_hit_down = false;
	m_hit_left = false;
	m_hit_right = false;
	m_time_flat = 0;
	count = 0;
	m_hp = 25;
	hit_flag = false;
	score = 100;
	m_time_hit = 0;

	attack_time = 1.0f;
	
/*	m_eff.m_top = 0;
	m_eff.m_left = 0;
	m_eff.m_right = 0;
	m_eff.m_bottom = 0;

	ani = 0;
	ani_time = 0;
	m_del = false;*/
	
	Hits::SetHitBox(this, m_px, m_py, 32, 32, ELEMENT_ENEMY, OBJ_BOSSENEMY, 1);
}
void CObjBossEnemy::Action()
{

	//弾丸消滅処理
/*	if (m_del == true)
	{
		//Resoucesの描画物のRECT
		//m_eff = GetBulletEffect(&ani, &ani_time, m_del, 4);
		//着弾アニメーション終了で本当にオブジェクトの破棄
		if (ani == 8)
		{
			this->SetStatus(false);
			Hits::DeleteHitBox(this);
		}
		return;//消滅処理は、ここでアクションメソッドを終了させる
	}*/

	if (count < 4)
	{
		m_time_flat++;
		if (m_time_flat > 50)
		{
			CObjAssaultBullet*objAB = (CObjAssaultBullet*)Objs::GetObj(OBJ_ASSAULT_BULLET);
			CObjAssaultBullet*objABullet = new CObjAssaultBullet(m_px, m_py-10);
			Objs::InsertObj(objABullet, OBJ_ASSAULT_BULLET, 50);
			count++;
			m_time_flat = 0;
		}
	}
	if (count >= 4)
	{

		m_time_flat++;
		if (m_time_flat > 150 && m_time_flat < 200)
			attack_time = 0.0f;
		if (m_time_flat > 200)
		{
			count = 0;
			attack_time = 1.0f;
		}

	}
	//ブロックとの当たり判定実行
	CObjBlock*pb = (CObjBlock*)Objs::GetObj(OBJ_BLOCK);

	CHitBox*hit = Hits::GetHitBox(this);

	
	//HitBoxの内容を更新

	hit->SetPos(m_px + pb->GetScroll(), m_py);



	CObjStageUi*ui = (CObjStageUi*)Objs::GetObj(OBJ_STAGEUI);
	if (hit->CheckElementHit(ELEMENT_HEROASSULTBULLET) == true && hit_flag == false)
	{
		m_hp -= 10;
		hit_flag = true;
		CObjDamege*dm = new CObjDamege(10, m_px, m_py);
		Objs::InsertObj(dm, OBJ_DAMEGE, 20);
		Audio::Start(12);
	}
	else if (hit->CheckElementHit(ELEMENT_HERONORMALBULLET) == true && hit_flag == false)
	{
		m_hp -= 20;
		hit_flag = true;
		CObjDamege*dm = new CObjDamege(20, m_px, m_py);
		Objs::InsertObj(dm, OBJ_DAMEGE, 20);
		Audio::Start(12);
	}
	else if (hit->CheckElementHit(ELEMENT_ATTACK) == true && hit_flag == false)
	{
		m_hp -= 15;
		hit_flag = true;
		CObjDamege*dm = new CObjDamege(15, m_px, m_py);
		Objs::InsertObj(dm, OBJ_DAMEGE, 20);
		Audio::Start(12);
	}
	if (hit->CheckElementHit(ELEMENT_LASERBULLET) == true && hit_flag == false)
	{
		m_hp -= 40;
		hit_flag = true;
		CObjDamege*dm = new CObjDamege(40, m_px, m_py);
		Objs::InsertObj(dm, OBJ_DAMEGE, 20);
		Audio::Start(12);
	}
	if (hit->CheckElementHit(ELEMENT_SHOTBULLET) == true)
	{
		m_hp -= 5;
		CObjDamege*dm = new CObjDamege(5, m_px, m_py);
		Objs::InsertObj(dm, OBJ_DAMEGE, 20);
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
			dm = 0;
		
		}
	}
	if (m_hp <= 0)
	{
		//m_del = true;
		CObjStage1Clear*s1c = (CObjStage1Clear*)Objs::GetObj(OBJ_STAGE1CLEAR);

		s1c->SetScore(score);
		CObjStageUi*su = (CObjStageUi*)Objs::GetObj(OBJ_STAGEUI);
		CObjBoss2*b2 = (CObjBoss2*)Objs::GetObj(OBJ_BOSS2);
		b2->enemycount();
		su->GetScore(score);
		Audio::Start(11);
		this->SetStatus(false);//自身に削除命令を出す
		Hits::DeleteHitBox(this);//保有するHitBoxに削除する
		Audio::Stop(11);
	}
	
}
void CObjBossEnemy::Draw()
{
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src;
	RECT_F dst;

	src.m_top = 0.0f;
	src.m_left = 512.0f;
	src.m_right = 536.0f;
	src.m_bottom = 16.0f;

	CObjBlock*pb = (CObjBlock*)Objs::GetObj(OBJ_BLOCK);
		dst.m_top = m_py;
		dst.m_left = m_px + pb->GetScroll();
		dst.m_right = dst.m_left + 32.0f;
		dst.m_bottom = m_py + 32.0f;

	//
	Draw::Draw(20, &src, &dst, c, k);

	/*dst.m_top = 0.0f + m_py;
	dst.m_left = 0.0f + m_px + pb->GetScroll();
	dst.m_right = 32.0f + m_px + pb->GetScroll();
	dst.m_bottom = 32.0f + m_py;

	Draw::Draw(23, &m_eff, &dst, c, 0.0f);*/
}