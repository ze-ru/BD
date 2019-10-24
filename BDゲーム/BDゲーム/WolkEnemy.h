#pragma once
#pragma once
//
#include"GameL\SceneObjManager.h"
//
using namespace GameL;

//
class CObjWolkEnemy :public CObj
{
public:
	CObjWolkEnemy() {};
	~CObjWolkEnemy() {};
	void Init();
	void Action();
	void Draw();

	float GetX() { return m_px; }
	float GetY() { return m_py; }
private:
	float m_px;
	float m_py;
	float m_vx;
	float m_vy;
	float m_posture;
	bool m_hit_down;
	float x;
	int m_ani_time;
	int m_ani_frame;


};