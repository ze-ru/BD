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
	Hits::SetHitBox(this, m_px, m_py, 64, 64, ELEMENT_ASSAULT, OBJ_RIFLE, 1);
}
void CObjRifle::Action()
{
	CHitBox* hit = Hits::GetHitBox(this);
	CObjBlock*pb = (CObjBlock*)Objs::GetObj(OBJ_BLOCK);

	if (hit->CheckElementHit(ELEMENT_PLAYER) == true)
	{
		if (Input::GetVKey(VK_UP) == true)
		{
			CObjHero*h = (CObjHero*)Objs::GetObj(OBJ_HERO);
			if (h->GetWeapon() == 2)
				h->Setbulletnums(10);
			else
				h->Setbulletnum(10);
			h->SetWeapon(2);
			
			this->SetStatus(false);//Ž©g‚Éíœ–½—ß‚ðo‚·
			Hits::DeleteHitBox(this);//•Û—L‚·‚éHitBox‚Éíœ‚·‚é
		}
	}
	hit->SetPos(m_px + pb->GetScroll(), m_py);
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

