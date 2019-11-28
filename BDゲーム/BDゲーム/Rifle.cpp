#include"GameL\DrawTexture.h"
#include"GameL\WinInputs.h"
#include"GameL\SceneManager.h"
#include"GameL\HitBoxManager.h"

#include"GameHead.h"
#include"Rifle.h"

using namespace GameL;

CObjRifle::CObjRifle(float x, float y)
{
	m_px = x;
	m_py = y;
}
void CObjRifle::Init()
{

	m_vx = 0.0f;
	m_vy = 0.0f;
	m_time = 0;

	m_hit_up = false;
	m_hit_down = false;
	m_hit_left = false;
	m_hit_right = false;
	m_posy = 1;
	m_posx = 1;
	m_count = 0;
	Hits::SetHitBox(this, m_px, m_py, 24, 16, ELEMENT_ENEMY_BULLET, OBJ_RIFLE, 1);
}
void CObjRifle::Action()
{


	m_time++;


	CObjBlock*block = (CObjBlock*)Objs::GetObj(OBJ_BLOCK);

	m_count++;
	CObjHero*objh = (CObjHero*)Objs::GetObj(OBJ_HERO);

	if (objh->GetX() > m_px)
		m_posx = 1;
	if (objh->GetY() < m_px)
		m_posx = -1;
	if (objh->GetY() > m_py)
		m_posy = 1;
	if (objh->GetY() < m_py)
		m_posy = -1;


	if (m_count == 1)
	{
		m_vx = (objh->GetX() - m_px - block->GetScroll());
		m_vy = (objh->GetY() - m_py);
	}
	UnitVec(&m_vx, &m_vy);
	m_px += m_vx;
	m_py += m_vy;

	CHitBox*hit = Hits::GetHitBox(this);
	hit->SetPos(m_px + block->GetScroll(), m_py);

	if (hit->CheckElementHit(ELEMENT_PLAYER) == true)
	{
		this->SetStatus(false);//自身に削除命令を出す
		Hits::DeleteHitBox(this);//保有するHitBoxに削除する
	}



	if (m_time > 100)
	{
		this->SetStatus(false);//自身に削除命令を出す
		Hits::DeleteHitBox(this);//保有するHitBoxに削除する
	}
	block->BulletHit(&m_px, &m_py, false, &m_hit_up, &m_hit_down,
		&m_hit_left, &m_hit_right);
	if (m_hit_up == true || m_hit_down == true || m_hit_left == true || m_hit_right == true)
	{
		this->SetStatus(false);//自身に削除命令を出す
		Hits::DeleteHitBox(this);//保有するHitBoxに削除する
	}

}
void CObjRifle::Draw()
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



	Draw::Draw(4, &src, &dst, c, 0.0f);
}

