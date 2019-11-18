#include "GameL\DrawTexture.h"
#include "GameL\WinInputs.h"
#include "GameL\SceneManager.h"
#include "GameL\HitBoxManager.h"

#include "GameHead.h"
#include "Boss1.h"


//
using namespace GameL;

CObjBoss1::CObjBoss1(float x, float y)
{
	m_ex = x;//
	m_ey = y;
}
//
void CObjBoss1::Init()
{

	m_vx = 0.0f;//
	m_vy = 0.0f;
	m_hit_up = false;
	m_hit_down = false;
	m_hit_left = false;
	m_hit_right = false;
}

//
void CObjBoss1::Action()
{
	CObjBlock*pb = (CObjBlock*)Objs::GetObj(OBJ_BLOCK);

	CHitBox*hit = Hits::GetHitBox(this);

	pb->BlockHit(&m_ex, &m_ey, false,
		&m_hit_up, &m_hit_down, &m_hit_left, &m_hit_right,
		&m_vx, &m_vy);


	hit->SetPos(m_ex + pb->GetScroll(), m_ey);
}

//
void CObjBoss1::Draw()
{
	
	//
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src;
	RECT_F dst;


	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 256.0f;
	src.m_bottom = 192.0f;




	dst.m_top = m_ey;
	dst.m_left =m_ex ;
	dst.m_right = m_ex+256.0f;
	dst.m_bottom = m_ey+192.0f;




	//
	Draw::Draw(14, &src, &dst, c, 0.0f);
}