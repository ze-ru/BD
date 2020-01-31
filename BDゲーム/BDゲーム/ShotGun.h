#pragma once
#include"GameL\SceneObjManager.h"

using namespace GameL;

class CObjShotBullet :public CObj
{
public:
	CObjShotBullet(float x, float y,int r);
	~CObjShotBullet() {};
	void Init();
	void Action();
	void Draw();

	float GetX() { return m_px; };
	float GetY() { return m_py; };
private:
	float m_vx;//主人子のX軸距離
	float m_vy;//主人子のY軸距離
	float m_px;//主人公のX軸
	float m_py;//主人公のY軸

	bool m_hit_up;//上判定
	bool m_hit_down;//下判定
	bool m_hit_left;//左判定
	bool m_hit_right;//右判定
	float m_time;//時間を測る
	int m_count;//カウントを測る
	int dm;//ダメージ

	int r_rad;//角度

	float m_v;

	bool dm_hit_flag;
};