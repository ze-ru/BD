#include"GameL\DrawTexture.h"
#include"GameL\WinInputs.h"
#include"GameL\SceneManager.h"
#include"GameL\HitBoxManager.h"

#include"GameHead.h"
#include"NormalBullet.h"

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

	m_hit_up = false;
	m_hit_down = false;
	m_hit_left = false;
	m_hit_right = false;
	dm = 5;


	Hits::SetHitBox(this, m_ex, m_ey, 24, 16, ELEMENT_ENEMY_BULLET, OBJ_NORMAL_BULLET, 1);
}
void CObjNormalBullet::Action()
{
	m_vx = -7.5f;
	CObjHero*objh = (CObjHero*)Objs::GetObj(OBJ_HERO);
	m_time++;
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
		this->SetStatus(false);//自身に削除命令を出す
		Hits::DeleteHitBox(this);//保有するHitBoxに削除する
	}
	if (hit->CheckElementHit(ELEMENT_ATTACK) == true)
	{
		this->SetStatus(false);//自身に削除命令を出す
		Hits::DeleteHitBox(this);//保有するHitBoxに削除する
	}
	
	
	
	if (m_time>100)
	{
		this->SetStatus(false);//自身に削除命令を出す
		Hits::DeleteHitBox(this);//保有するHitBoxに削除する
	}
	block->BulletHit(&m_ex, &m_ey, false, &m_hit_up, &m_hit_down,
		&m_hit_left, &m_hit_right);
	if (m_hit_up == true || m_hit_down == true || m_hit_left == true || m_hit_right == true)
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

