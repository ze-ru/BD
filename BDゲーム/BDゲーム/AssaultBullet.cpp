#include"GameL\DrawTexture.h"
#include"GameL\WinInputs.h"
#include"GameL\SceneManager.h"
#include"GameL\HitBoxManager.h"

#include"GameHead.h"
#include"AssaultBullet.h"

using namespace GameL;

CObjAssaultBullet::CObjAssaultBullet(float x, float y)
{
	m_ex = x;
	m_ey = y;
}
void CObjAssaultBullet::Init()
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
	Hits::SetHitBox(this, m_ex, m_ey, 24, 16, ELEMENT_ENEMY, OBJ_ASSAULT_BULLET, 1);
}
void CObjAssaultBullet::Action()
{
	

	m_time++;
	

	CObjBlock*block = (CObjBlock*)Objs::GetObj(OBJ_BLOCK);

	m_count++;
	CObjHero*objh = (CObjHero*)Objs::GetObj(OBJ_HERO);
	

	if (m_count == 1)
	{
		m_vx = (objh->GetX() - m_ex);
		m_vy = (objh->GetY() - m_ey);
	}
	UnitVec(&m_vx, &m_vy);
	m_ex += m_vx;
	m_ey += m_vy;

	CHitBox*hit = Hits::GetHitBox(this);
	hit->SetPos(m_ex + block->GetScroll(), m_ey);

	if (hit->CheckElementHit(ELEMENT_PLAYER) == true)
	{
		this->SetStatus(false);//���g�ɍ폜���߂��o��
		Hits::DeleteHitBox(this);//�ۗL����HitBox�ɍ폜����
	}



	if (m_time > 100)
	{
		this->SetStatus(false);//���g�ɍ폜���߂��o��
		Hits::DeleteHitBox(this);//�ۗL����HitBox�ɍ폜����
	}

}
void CObjAssaultBullet::Draw()
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

bool UnitVec(float *vx, float *vy)
{
	float r = 0.0f;
	r = (*vx)*(*vx) + (*vy)*(*vy);
	r = sqrt(r);

	if (r == 0.0f)
	{
		return false;
	}
	else
	{
		(*vx) = 5.0f / r * (*vx);
		(*vy) = 5.0f / r * (*vy);
	}
	return true;
}