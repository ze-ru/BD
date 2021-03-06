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
	bool m_hit_up;
	bool m_hit_down;
	bool m_hit_left;
	bool m_hit_right;
	float m_time;
	int m_posture;

	int dm;
	bool hit_flag;

	bool dm_hit_flag;
};