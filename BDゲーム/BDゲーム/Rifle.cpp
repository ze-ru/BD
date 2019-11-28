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

}
void CObjRifle::Draw()
{
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src;
	RECT_F dst;

	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 64.0f;
	src.m_bottom = 64.0f;


	CObjBlock*block = (CObjBlock*)Objs::GetObj(OBJ_BLOCK);
	//
	dst.m_top = m_py;
	dst.m_left = m_px + block->GetScroll();
	dst.m_right = dst.m_left + 64.0f;
	dst.m_bottom = 64.0f + m_py;



	Draw::Draw(19, &src, &dst, c, 0.0f);
}

