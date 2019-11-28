#include"GameL\DrawTexture.h"
#include"GameL\WinInputs.h"
#include"GameL\SceneManager.h"
#include"GameL\HitBoxManager.h"

#include"GameHead.h"
#include"Assault.h"

using namespace GameL;

CObjAssault::CObjAssault(float x, float y)
{
	m_px = x;
	m_py = y;
}
void CObjAssault::Init()
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
	Hits::SetHitBox(this, m_px, m_py, 24, 16, ELEMENT_ASSAULT, OBJ_ASSAULT, 1);
}
void CObjAssault::Action()
{

	CHitBox* hit = Hits::GetHitBox(this);

	if (hit->CheckElementHit(ELEMENT_PLAYER) == true)
	{
		if (Input::GetVKey(VK_UP) == true)
		{
			CObjHero*h = (CObjHero*)Objs::GetObj(OBJ_HERO);
			h->SetWeapon(1);
			this->SetStatus(false);//Ž©g‚Éíœ–½—ß‚ðo‚·
			Hits::DeleteHitBox(this);//•Û—L‚·‚éHitBox‚Éíœ‚·‚é
		}
	}

}
void CObjAssault::Draw()
{
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src;
	RECT_F dst;

	src.m_top = 0.0f;
	src.m_left = 192.0f;
	src.m_right = 256.0f;
	src.m_bottom = 64.0f;


	CObjBlock*block = (CObjBlock*)Objs::GetObj(OBJ_BLOCK);
	//
	dst.m_top = m_py;
	dst.m_left = m_px + block->GetScroll();
	dst.m_right = dst.m_left+64.0f;
	dst.m_bottom = 64.0f + m_py;


	
	Draw::Draw(19, &src, &dst, c, 0.0f);
}
