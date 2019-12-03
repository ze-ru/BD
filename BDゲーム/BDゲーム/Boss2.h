#pragma once
//
#include"GameL\SceneObjManager.h"
//
using namespace GameL;

//
class CObjBoss2 :public CObj
{
public:
	CObjBoss2(float x, float y);
	~CObjBoss2() {};
	void Init();
	void Action();
	void Draw();
	float GetVx() { return m_vx; }
	bool GetDead() { return dead_flag; }
	void SetDamege(int dm) { m_hp -= dm; }
	float GetX() { return m_ex; };
	float GetY() { return m_ey; };
private:
	float m_ex;
	float m_ey;
	float m_vx;
	float m_vy;

	bool m_hit_up;
	bool m_hit_down;
	bool m_hit_left;
	bool m_hit_right;
	int time;
	int m_hp;
	int m_time;
	float m_dead;
	bool hit_flag;
	int attacktime;
	bool dead_flag;
	int time2;


};