#pragma once
//使用するヘッダーファイル
#include"GameL\SceneObjManager.h"

using namespace GameL;
//オブジェクト：シールド
class CObjShield :public CObj
{
public:
	CObjShield(float x, float y);
	~CObjShield() {};
	void Init();
	void Action();
	void Draw();

	void SetDead() { m_dead = true; }

private:

	float m_ex;
	float m_ey;

	float m_time;
	int m_posture;
	int dm;
	bool hit_flag;
	bool m_dead;
	int m_time_hit;
	bool m_hit_flag;
	bool dm_hit_flag;
};