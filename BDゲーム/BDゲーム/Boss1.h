#pragma once
//
#include"GameL\SceneObjManager.h"
//
using namespace GameL;

//
class CObjBoss1 :public CObj
{
public:
	CObjBoss1(float x, float y);
	~CObjBoss1() {};
	void Init();
	void Action();
	void Draw();
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
};