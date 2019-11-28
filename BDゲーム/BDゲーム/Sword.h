#pragma once
#include"GameL\SceneObjManager.h"

using namespace GameL;

class CObjHeroAssultBullet :public CObj
{
public:
	CObjHeroAssultBullet(float x, float y);
	~CObjHeroAssultBullet() {};
	void Init();
	void Action();
	void Draw();

	float GetX() { return m_px; };
	float GetY() { return m_py; };

private:
	float m_vx;
	float m_vy;
	float m_px;
	float m_py;
	float m_ex;
	float m_ey;
	
};