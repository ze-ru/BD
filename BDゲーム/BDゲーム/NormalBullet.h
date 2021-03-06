#pragma once
#include"GameL\SceneObjManager.h"

using namespace GameL;

class CObjNormalBullet :public CObj
{
public:
	CObjNormalBullet(float x,float y);
	~CObjNormalBullet() {};
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
	int dm;

	bool hit_flag;

};