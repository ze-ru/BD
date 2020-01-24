#pragma once
#include"GameL\SceneObjManager.h"

using namespace GameL;

class CObjShotGun :public CObj
{
public:
	CObjShotGun(float x, float y);
	~CObjShotGun() {};
	void Init();
	void Action();
	void Draw();
private:
	float m_vx;
	float m_vy;
	float m_px;
	float m_py;
	float m_time;


};
