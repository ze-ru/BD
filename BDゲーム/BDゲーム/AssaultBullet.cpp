#include"GameL\DrawTexture.h"
#include"GameL\WinInputs.h"
#include"GameL\SceneManager.h"
#include"GameL\HitBoxManager.h"

#include"GameHead.h"
#include"AssaultBullet.h"

using namespace GameL;

CObjAssaultBullet::CObjAssaultBullet(float x, float y)
{
	m_px = x;
	m_py = y;
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
	dm = 2;
	Hits::SetHitBox(this, m_px, m_py, 24, 16, ELEMENT_ENEMY_BULLET, OBJ_ASSAULT_BULLET, 1);
}
void CObjAssaultBullet::Action()
{
	

	m_time++;
	

	CObjBlock*block = (CObjBlock*)Objs::GetObj(OBJ_BLOCK);

	m_count++;
	CObjHero*objh = (CObjHero*)Objs::GetObj(OBJ_HERO);

	
	if (m_count == 1)
	{
		m_vx = (objh->GetX()+32 - m_px- block->GetScroll());
		m_vy = (objh->GetY() - m_py);
	}
	UnitVec(&m_vx, &m_vy);

	CHitBox*hit = Hits::GetHitBox(this);

	
	
	if (hit->CheckElementHit(ELEMENT_PLAYER) == true)
	{
		if (objh->GetYflag() == false)
			objh->SetDamege(dm);
		if (objh->GetX() + 32 - block->GetScroll() > m_px)
			objh->SetHitflag(true);
		if (objh->GetX() + 32 - block->GetScroll() < m_px)
			objh->SetHitflag(false);
		this->SetStatus(false);//自身に削除命令を出す
		Hits::DeleteHitBox(this);//保有するHitBoxに削除する
	}
	if (hit->CheckElementHit(ELEMENT_ATTACK) == true)
	{
		this->SetStatus(false);//自身に削除命令を出す
		Hits::DeleteHitBox(this);//保有するHitBoxに削除する
	}
	m_px += m_vx;
	m_py += m_vy;
	hit->SetPos(m_px + block->GetScroll(), m_py);
	

	



	if (m_time > 150)
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
	dst.m_top = m_py + 4.0f;
	dst.m_left = m_px + block->GetScroll();
	dst.m_right = dst.m_left + 24.0f;
	dst.m_bottom = 20.0f + m_py;


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