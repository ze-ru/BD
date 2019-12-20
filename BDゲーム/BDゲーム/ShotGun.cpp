#include"GameL\DrawTexture.h"
#include"GameL\WinInputs.h"
#include"GameL\SceneManager.h"
#include"GameL\HitBoxManager.h"

#include"GameHead.h"
#include"ShotGun.h"
#include"GameL\Audio.h"
#include<math.h>

using namespace GameL;

CObjShotBullet::CObjShotBullet(float x, float y,int r)
{
	m_px = x;
	m_py = y;
	r_rad = r;
}
void CObjShotBullet::Init()
{

	m_vx = cosf(3.14 / 180 * r_rad);
	m_vy = sinf(3.14 / 180 * r_rad);
	UnitVec(&m_vx, &m_vy);
	m_time = 0;

	m_hit_up = false;
	m_hit_down = false;
	m_hit_left = false;
	m_hit_right = false;
	m_count = 0;
	m_v = 1.0f;
	dm = 3;
	Audio::Start(7);
	Hits::SetHitBox(this, m_px, m_py, 24, 16, ELEMENT_ENEMY_BULLET, OBJ_SHOT_BULLET, 1);
}
void CObjShotBullet::Action()
{
	m_time++;
	CObjBlock*block = (CObjBlock*)Objs::GetObj(OBJ_BLOCK);
	CObjHero*objh = (CObjHero*)Objs::GetObj(OBJ_HERO);
	CHitBox*hit = Hits::GetHitBox(this);

	m_px += m_vx * m_v;
	m_py += m_vy * m_v;

	hit->SetPos(m_px + block->GetScroll(), m_py);

	if (m_time > 50)
	{
		this->SetStatus(false);//自身に削除命令を出す
		Hits::DeleteHitBox(this);//保有するHitBoxに削除する
	}
	block->BulletHit(&m_px, &m_py, false, &m_hit_up, &m_hit_down,
		&m_hit_left, &m_hit_right);
	if (m_hit_up == true || m_hit_down == true || m_hit_left == true || m_hit_right == true)
	{
		Audio::Stop(7);
		this->SetStatus(false);//自身に削除命令を出す
		Hits::DeleteHitBox(this);//保有するHitBoxに削除する
	}

	if (hit->CheckElementHit(ELEMENT_PLAYER) == true)
	{
		if (objh->GetYflag() == false)
			objh->SetDamege(dm);
		if (objh->GetX() + 32 - block->GetScroll() > m_px)
			objh->SetHitflag(true);
		if (objh->GetX() + 32 - block->GetScroll() < m_px)
			objh->SetHitflag(false);
		Audio::Start(13);
		Audio::Stop(7);
		this->SetStatus(false);//自身に削除命令を出す
		Hits::DeleteHitBox(this);//保有するHitBoxに削除する
		Audio::Stop(13);
	}

}
void CObjShotBullet::Draw()
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
	dst.m_top = m_py + 4.0f;
	dst.m_left = m_px + block->GetScroll();
	dst.m_right = dst.m_left + 24.0f;
	dst.m_bottom = 20.0f + m_py;


	//
	Draw::Draw(4, &src, &dst, c, 0.0f);
}