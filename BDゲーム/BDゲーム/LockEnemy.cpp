#include"GameL\DrawTexture.h"
#include"GameL\WinInputs.h"
#include"GameL\SceneManager.h"
#include"GameL\HitBoxManager.h"

#include"GameHead.h"
#include"LockEnemy.h"

using namespace GameL;

CObjLockEnemy::CObjLockEnemy(float x, float y)
{
	m_ex = x;
	m_ey = y;
}
void CObjLockEnemy::Init()
{
	m_vy = 0;
	m_vx = 0;
	m_ani_time = 0;
	m_ani_frame = 0;
	m_posture = 0;

	m_hit_up = false;
	m_hit_down = false;
	m_hit_left = false;
	m_hit_right = false;
	hit_flag = false;
	m_hp = 40;
	score = 100;
	m_time = 0;
	attack_time = 1.0f;

	m_eff.m_top = 0;
	m_eff.m_left = 0;
	m_eff.m_right = 0;
	m_eff.m_bottom = 0;

	ani = 0;
	ani_time = 0;
	m_del = false;
	Hits::SetHitBox(this, m_ex, m_ey, 64, 64, ELEMENT_ENEMY, OBJ_LOCKENEMY, 1);
}

void CObjLockEnemy::Action()
{
	CObjHero*objh = (CObjHero*)Objs::GetObj(OBJ_HERO);
	m_ani_time++;

	if (m_ani_time > 60 && m_ani_time < 100)
	{
		attack_time=0.0f;
	}
	if (m_ani_time > 120)
	{
		m_ani_time = 0;

		CObjNormalBullet*objNB = (CObjNormalBullet*)Objs::GetObj(OBJ_NORMAL_BULLET);
			CObjNormalBullet*objbullet = new CObjNormalBullet(m_ex,m_ey);
			Objs::InsertObj(objbullet, OBJ_NORMAL_BULLET, 50);
			attack_time = 1.0f;
	}
	
	//弾丸消滅処理
	if (m_del == true)
	{
		//Resoucesの描画物のRECT
		m_eff = GetBulletEffect(&ani, &ani_time, m_del, 2);
		//着弾アニメーション終了で本当にオブジェクトの破棄
		if (ani == 4)
		{
			CObjStage1Clear*s1c = (CObjStage1Clear*)Objs::GetObj(OBJ_STAGE1CLEAR);

			s1c->SetScore();
			CObjStageUi*su = (CObjStageUi*)Objs::GetObj(OBJ_STAGEUI);

			su->GetScore(score);
			this->SetStatus(false);
			Hits::DeleteHitBox(this);
		}
		return;//消滅処理は、ここでアクションメソッドを終了させる
	}


	//ブロックとの当たり判定実行
	CObjBlock*pb = (CObjBlock*)Objs::GetObj(OBJ_BLOCK);

	CHitBox*hit = Hits::GetHitBox(this);
	if (pb->Getmap1() == 0)
	{

		pb->BlockHit(&m_ex, &m_ey, false,
			&m_hit_up, &m_hit_down, &m_hit_left, &m_hit_right,
			&m_vx, &m_vy);
	
	}

	CObjStageUi*ui = (CObjStageUi*)Objs::GetObj(OBJ_STAGEUI);
       	hit->SetPos(m_ex + pb->GetScroll(), m_ey);
		if (hit->CheckElementHit(ELEMENT_HEROASSULTBULLET) == true && hit_flag == false)
		{
			m_hp -= 10;
			hit_flag = true;
			CObjDamege*dm = new CObjDamege(10, m_ex, m_ey);
			Objs::InsertObj(dm, OBJ_DAMEGE, 20);
		}
		if (hit->CheckElementHit(ELEMENT_HERONORMALBULLET) == true && hit_flag == false)
		{
			m_hp -= 20;
			hit_flag = true;
			CObjDamege*dm = new CObjDamege(20, m_ex, m_ey);
			Objs::InsertObj(dm, OBJ_DAMEGE, 20);
		}
		
		if (hit->CheckElementHit(ELEMENT_ATTACK) == true && hit_flag == false)
		{
			m_hp -= 15;
			hit_flag = true;
			CObjDamege*dm = new CObjDamege(15, m_ex, m_ey);
			Objs::InsertObj(dm, OBJ_DAMEGE, 20);
		}
		if (hit->CheckObjNameHit(OBJ_ASSAULT_BULLET) != nullptr)
		{
			m_hp -= 3;
			hit_flag = true;
			CObjDamege*dm = new CObjDamege(3, m_ex, m_ey);
			Objs::InsertObj(dm, OBJ_DAMEGE, 20);
		}
		if (hit->CheckElementHit(ELEMENT_LASERBULLET) == true && hit_flag == false)
		{
			m_hp -= 60;
			hit_flag = true;
			CObjDamege*dm = new CObjDamege(60, m_ex, m_ey);
			Objs::InsertObj(dm, OBJ_DAMEGE, 20);
		}

	if (hit_flag == true)
	{
		m_time++;
		if (m_time > 10)
		{
			hit_flag = false;
			m_time = 0;
		}

	}
	if (m_hp <= 0)
	{
		m_del = true;
		
	}
	if (Input::GetVKey('S') == true || (objh->GetX() - pb->GetScroll()) > 17920)
	{
		this->SetStatus(false);//自身に削除命令を出す
		Hits::DeleteHitBox(this);//保有するHitBoxに削除する
	}
}
void CObjLockEnemy::Draw()
{
	float c[4] = { 1.0f,1.0f,attack_time,1.0f };

	RECT_F src;
	RECT_F dst;


	//ブロック情報を持ってくる
	

	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 64.0f;
	src.m_bottom = 64.0f;

	CObjBlock*pb = (CObjBlock*)Objs::GetObj(OBJ_BLOCK);
	
	if (hit_flag == false)
	{
		dst.m_top = 0.0f + m_ey;
		dst.m_left = 64 - 64.0f + m_ex + pb->GetScroll();
		dst.m_right = 64.0f + m_ex + pb->GetScroll();
		dst.m_bottom = 64.0f + m_ey;
	}
	

	//
	Draw::Draw(4, &src, &dst, c, 0.0f);

	dst.m_top = 0.0f + m_ey;
	dst.m_left = 0.0f + m_ex + pb->GetScroll();
	dst.m_right = 64.0f + m_ex + pb->GetScroll();
	dst.m_bottom = 64.0f + m_ey;

	Draw::Draw(23, &m_eff, &dst, c, 0.0f);
}