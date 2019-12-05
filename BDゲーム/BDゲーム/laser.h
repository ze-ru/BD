#pragma once
#include"GameL\SceneObjManager.h"

using namespace GameL;

class CObjlaser :public CObj
{
public:
	CObjlaser(float x, float y);
	~CObjlaser() {};
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
	
};