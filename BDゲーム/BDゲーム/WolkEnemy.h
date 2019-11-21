#pragma once
//
#include"GameL\SceneObjManager.h"
//
using namespace GameL;

//
class CObjWolkEnemy :public CObj
{
public:
	CObjWolkEnemy(float x,float y);
	~CObjWolkEnemy() {};
	void Init();
	void Action();
	void Draw();

	float GetVx() { return m_vx; }
	int Getscore() { return score; }
private:
	float m_ex;
	float m_ey;
	float m_vx;
	float m_vy;
	float m_posture;
	float m_time;
	int m_ani_time;
	int m_ani_frame;

	float m_speed_power;
	float m_ani_max_time;

	bool m_hit_up;
	bool m_hit_down;
	bool m_hit_left;
	bool m_hit_right;

	float m_dead;
	//ˆÚ“®‚ÌŒü‚«—p
	bool m_move;
	float m_hp;
	bool hit_flag;

	int score;
	int m_time_hit;
};