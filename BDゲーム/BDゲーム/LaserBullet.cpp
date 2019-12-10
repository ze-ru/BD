#include"GameL\DrawTexture.h"
#include"GameL\WinInputs.h"
#include"GameL\SceneManager.h"
#include"GameL\HitBoxManager.h"

#include"GameHead.h"
#include"LaserBullet.h"

using namespace GameL;

CObjLaserBullet::CObjLaserBullet(float x, float y)
{
	m_ex = x;
	m_ey = y + 23.0f;
}
void CObjLaserBullet::Init()
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
	dm = 20;
	m_hit = 0;
	Hits::SetHitBox(this, m_ex, m_ey, 24, 16, ELEMENT_LASERBULLET, OBJ_LASER_BULLET, 1);
}
void CObjLaserBullet::Action()
{


	m_time++;

	m_ex += m_vx;
	m_ey += m_vy;

	CObjBlock*block = (CObjBlock*)Objs::GetObj(OBJ_BLOCK);
	CHitBox*hit = Hits::GetHitBox(this);

	hit->SetPos(m_ex + block->GetScroll(), m_ey);






	if (m_time > 80)
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
	if (hit->CheckObjNameHit(OBJ_BOSS1) != nullptr || hit->CheckObjNameHit(OBJ_BOSS2))
	{
		this->SetStatus(false);//自身に削除命令を出す
		Hits::DeleteHitBox(this);//保有するHitBoxに削除する
	}

	if (hit->CheckElementHit(ELEMENT_ENEMY) == true)
	{
		if (hit_flag == false)
		{
			hit_flag = true;
			m_hit++;
			if (m_hit >= 3)
			{
				this->SetStatus(false);//自身に削除命令を出す
				Hits::DeleteHitBox(this);//保有するHitBoxに削除する
			}
		}
	}
	else
	{
		hit_flag = false;
	}

}
void CObjLaserBullet::Draw()
{
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src;
	RECT_F dst;

	src.m_top = 0.0f;
	src.m_left = 288.0f;
	src.m_right = 320.0f;
	src.m_bottom = 8.0f;


	CObjBlock*block = (CObjBlock*)Objs::GetObj(OBJ_BLOCK);
	//
	dst.m_top = m_ey + 4.0f;
	dst.m_left = m_ex + block->GetScroll();
	dst.m_right = dst.m_left + 24.0f;
	dst.m_bottom = 20.0f + m_ey;


	//
	Draw::Draw(19, &src, &dst, c, 0.0f);
}

