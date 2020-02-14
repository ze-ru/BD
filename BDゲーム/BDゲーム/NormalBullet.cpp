#include"GameL\DrawTexture.h"
#include"GameL\WinInputs.h"
#include"GameL\SceneManager.h"
#include"GameL\HitBoxManager.h"

#include"GameHead.h"
#include"NormalBullet.h"
#include"GameL\Audio.h"

using namespace GameL;

CObjNormalBullet::CObjNormalBullet(float x,float y)
{
	m_ex = x;
	m_ey = y+23.0f;
}
void CObjNormalBullet::Init()
{
	CObjLockEnemy*objeL = (CObjLockEnemy*)Objs::GetObj(OBJ_LOCKENEMY);
	m_vx = 5.0f;
	m_vy = 0.0f;
	m_time = 0;

	m_hit_up = false;//上の当たり判定
	m_hit_down = false;//下の当たり判定
	m_hit_left = false;//左の当たり判定
	m_hit_right = false;//右の当たり判定
	dm = 5;//ダメージ値
	Audio::Start(7);

	hit_flag = false;

	Hits::SetHitBox(this, m_ex, m_ey, 24, 16, ELEMENT_ENEMY_BULLET, OBJ_NORMAL_BULLET, 1);
}
void CObjNormalBullet::Action()
{
	m_vx = -7.5f;
	CObjHero*objh = (CObjHero*)Objs::GetObj(OBJ_HERO);
	m_time++;

	if (m_time == 5)
		Audio::Stop(7);
	m_ex += m_vx;
	m_ey += m_vy;
	
	CObjBlock*block = (CObjBlock*)Objs::GetObj(OBJ_BLOCK);
	CHitBox*hit = Hits::GetHitBox(this);
	hit->SetPos(m_ex + block->GetScroll(), m_ey);
	
	

	if (hit->CheckElementHit(ELEMENT_PLAYER) == true)
	{
		if (objh->GetYflag() == false)
			objh->SetDamege(dm);//ダメージ
		if (objh->GetX() +32> m_ex)
			objh->SetHitflag(true);
		if (objh->GetX() + 32 < m_ex)
			objh->SetHitflag(false);
		
		Audio::Start(13);
		Audio::Stop(7);
		
		hit_flag = true;
		Audio::Stop(13);
	}
	if (hit->CheckElementHit(ELEMENT_ATTACK) == true)
	{
		Audio::Stop(7);
		hit_flag = true;
	}
	if (hit->CheckObjNameHit(OBJ_WOLKENEMY) != nullptr)
	{
		Audio::Stop(7);
		hit_flag = true;
	}
	if (hit->CheckObjNameHit(OBJ_SHIELDENEMY) != nullptr)
	{
		Audio::Stop(7);
		hit_flag = true;
	}
	if (hit->CheckObjNameHit(OBJ_SHIELD) != nullptr)
	{
		Audio::Stop(7);
		hit_flag = true;
	}
	if (hit->CheckObjNameHit(OBJ_FLYENEMY) != nullptr)
	{
		Audio::Stop(7);
		hit_flag = true;
	}
	
	if (m_time>100)
	{
		Audio::Stop(7);
		this->SetStatus(false);//自身に削除命令を出す
		Hits::DeleteHitBox(this);//保有するHitBoxに削除する
	}
	block->BulletHit(&m_ex, &m_ey, false, &m_hit_up, &m_hit_down,
		&m_hit_left, &m_hit_right);
	if (m_hit_up == true || m_hit_down == true || m_hit_left == true || m_hit_right == true)
	{
		Audio::Stop(7);
		hit_flag = true;
	}
	if (hit_flag == true)
	{
		this->SetStatus(false);//自身に削除命令を出す
		Hits::DeleteHitBox(this);//保有するHitBoxに削除する
	}


}
void CObjNormalBullet::Draw()
{
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src;
	RECT_F dst;

	src.m_top = 0.0f;
	src.m_left = 64.0f;
	src.m_right = 88.0f;
	src.m_bottom = 16.0f;


	CObjBlock*block = (CObjBlock*)Objs::GetObj(OBJ_BLOCK);
	//
	dst.m_top = m_ey+4.0f;
	dst.m_left = m_ex+ block->GetScroll();
	dst.m_right = dst.m_left+24.0f;
	dst.m_bottom = 20.0f+m_ey;


	//
	Draw::Draw(4, &src, &dst, c, 0.0f);
}

