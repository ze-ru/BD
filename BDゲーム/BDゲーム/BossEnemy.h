#pragma once
#include"GameL\SceneObjManager.h"

using namespace GameL;

class CObjBossEnemy :public CObj
{
public:
	CObjBossEnemy(float x, float y,float kak);
	~CObjBossEnemy() {};
	void Init();
	void Action();
	void Draw();

private:
	float m_px;
	float m_py;
	float m_vx;
	float m_vy;
	
	float m_posture;

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
	bool hit_flag;
	int score;

	int m_time_hit;

	int dm;
	bool hit;

	int attack_time;

	float k;

	/*int ani;//着弾アニメーション用
	int ani_time;//着弾アニメーション間隔タイム
	bool m_del;//削除チェック*/
	//RECT_F m_eff;//着弾エフェクト描画用
};