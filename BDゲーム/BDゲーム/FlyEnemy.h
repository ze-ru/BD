#pragma once
#include"GameL\SceneObjManager.h"

using namespace GameL;

class CObjFlyEnemy :public CObj
{
public:
	CObjFlyEnemy(float x,float y) ;
	~CObjFlyEnemy() {};
	void Init();
	void Action();
	void Draw();

private:
	float m_px;
	float m_py;
	float m_vx;
	float m_vy;
	float m_posture;

	int m_block_type;
	
	float x;
	int m_ani_time;
	int m_ani_frame;
	int m_time;

	bool m_hit_up;
	bool m_hit_down;
	bool m_hit_left;
	bool m_hit_right;
	int m_time_flat;
	int count;
	int m_hp;
};