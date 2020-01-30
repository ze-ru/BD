#pragma once
#include"GameL\SceneObjManager.h"

using namespace GameL;

class CObjShield :public CObj
{
public:
	CObjShield(float x, float y);
	~CObjShield() {};
	void Init();
	void Action();
	void Draw();

	float GetX() { return m_px; };
	float GetY() { return m_py; };

	void SetDead() { m_dead = true; }

	

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

	int m_hit;

	bool m_dead;
	int m_time_hit;

	bool m_attack;

	bool m_hit_flag;
	int m_count;

	bool dm_hit_flag;
};