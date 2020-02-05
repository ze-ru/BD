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
	//変数の初期化
	m_ani_time = 0;
	m_ani_frame = 0;

	m_time = 0;

	m_hit_up = false;
	m_hit_down = false;
	m_hit_left = false;
	m_hit_right = false;

	m_time_flat = 0;
	count = 0;
	m_hp = 25;//Hpを25に設定
	hit_flag = false;
	score = 100;//撃破時のScoreを100に設定
	m_time_hit = 0;

	attack_time = 1.0f;
	

	Hits::SetHitBox(this, m_px, m_py, 32, 32, ELEMENT_ENEMY, OBJ_BOSSENEMY, 1);//HitBox作成
}
void CObjBossEnemy::Action()
{

	if (count < 4)
	{
		m_time_flat++;
		if (m_time_flat > 50)//m_time_flatが50を超えるとAssaultBullet作成
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
	//攻撃を受けたとき
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
	//切り取り位置
	src.m_top = 0.0f;
	src.m_left = 512.0f;
	src.m_right = 536.0f;
	src.m_bottom = 16.0f;

	CObjBlock*pb = (CObjBlock*)Objs::GetObj(OBJ_BLOCK);

	//表示位置
	dst.m_top = m_py;
	dst.m_left = m_px + pb->GetScroll();
	dst.m_right = dst.m_left + 32.0f;
	dst.m_bottom = m_py + 32.0f;

	//描画
	Draw::Draw(20, &src, &dst, c, k);
}