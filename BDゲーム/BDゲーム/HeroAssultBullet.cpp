//使用するヘッダーファイル
#include"GameL\DrawTexture.h"
#include"GameL\WinInputs.h"
#include"GameL\SceneManager.h"
#include"GameL\HitBoxManager.h"

#include"GameHead.h"
#include"HeroAssultBullet.h"

#include"GameL/Audio.h"

using namespace GameL;

CObjHeroAssultBullet::CObjHeroAssultBullet(float x, float y)
{
	CObjBlock*block = (CObjBlock*)Objs::GetObj(OBJ_BLOCK);
	m_ex = x ;
	m_ey = y+23.0f;
}
void CObjHeroAssultBullet::Init()
{

	CObjHero*h = (CObjHero*)Objs::GetObj(OBJ_HERO);

	m_time = 0;
	if (h->GetFlag() == false)
	{
		m_vx = 10.0f;//右向き0.0f 左向き1.0f
		
	}
	if (h->GetFlag() == true)
	{
		m_vx = -10.0f;//右向き0.0f 左向き1.0f
		
	}
	m_py = h->GetY();
	
	m_vy = 0;
	m_hit_up = false;
	m_hit_down = false;
	m_hit_left = false;
	m_hit_right = false;
	m_posture = 0;
	hit_flag = false;
	dm = 10;

	dm_hit_flag = false;
	Audio::Start(7);
	Hits::SetHitBox(this, m_ex, m_ey, 24, 16, ELEMENT_HEROASSULTBULLET, OBJ_HEROASSULTBULLET, 1);
}
void CObjHeroAssultBullet::Action()
{


	m_time++;
	if (m_time == 5)
		Audio::Stop(7);
	m_ex += m_vx;
	m_ey += m_vy;

	CObjBlock*block = (CObjBlock*)Objs::GetObj(OBJ_BLOCK);
	CHitBox*hit = Hits::GetHitBox(this);

	hit->SetPos(m_ex+block->GetScroll(), m_ey);

	
	block->BulletHit(&m_ex, &m_ey, false, &m_hit_up, &m_hit_down,
		&m_hit_left, &m_hit_right);

	if (m_time > 80) 
	{
		Audio::Stop(7);
		dm_hit_flag = true;

	}
	
	if (m_hit_up == true || m_hit_down == true || m_hit_left == true || m_hit_right == true)
	{
		Audio::Stop(7);
		dm_hit_flag = true;
	}

	if (hit->CheckObjNameHit(OBJ_BOSS1) != nullptr || hit->CheckObjNameHit(OBJ_BOSS2))
	{
		Audio::Stop(7);
		dm_hit_flag = true;
	}

	if (hit->CheckElementHit(ELEMENT_ENEMY) == true&&hit_flag==false)
	{
		Audio::Stop(7);
		dm_hit_flag = true;
	}
	if (hit->CheckElementHit(ELEMENT_SHIELD) == true)
	{
		Audio::Stop(7);
		hit_flag = true;
		dm_hit_flag = true;
	}
	else if(hit->CheckElementHit(ELEMENT_SHIELD)==false)
	{
		hit_flag = false;
	}

	if (dm_hit_flag == true)
	{
		this->SetStatus(false);//自身に削除命令を出す
		Hits::DeleteHitBox(this);//保有するHitBoxに削除する
	}
}
void CObjHeroAssultBullet::Draw()
{
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src;
	RECT_F dst;

	src.m_top = 0.0f;
	src.m_left = 88.0f;
	src.m_right = 112.0f;
	src.m_bottom = 16.0f;


	CObjBlock*block = (CObjBlock*)Objs::GetObj(OBJ_BLOCK);
	//
	dst.m_top = m_ey + 4.0f;
	dst.m_left = m_ex + block->GetScroll();
	dst.m_right = dst.m_left + 24.0f;
	dst.m_bottom = 20.0f + m_ey;


	//
	Draw::Draw(4, &src, &dst, c, 0.0f);
}

