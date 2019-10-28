#pragma once
#include"GameL\SceneObjManager.h"

using namespace GameL;

class CObjLockEnemy :public CObj
{
public:
	CObjLockEnemy(float x,float y) ;
	~CObjLockEnemy() {};
	void Init();
	void Action();
	void Draw();

private:
	float m_ex;
	float m_ey;
	float m_vx;
	float m_vy;
	float m_posture;
	bool m_hit_down;
	bool m_hit_up;
	bool m_hit_left;
	bool m_hit_right;
	float x;
	int m_ani_time;
	int m_ani_frame;
};