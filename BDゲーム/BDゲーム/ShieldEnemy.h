#pragma once
//
#include"GameL\SceneObjManager.h"
//
using namespace GameL;

//
class CObjShieldEnemy :public CObj
{
public:
	CObjShieldEnemy(float x, float y);
	~CObjShieldEnemy() {};
	void Init();
	void Action();
	void Draw();

	float GetVx() { return m_vx; }
	int Getscore() { return score; }
	float GetX() { return m_ex; };
	float GetY() { return m_ey; };
	float GetPos() { return m_posture; }
	void SetDamege(int dm) { m_hp -= dm; }

	void SetShield() { dead = true; }
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
	//移動の向き用
	bool m_move;
	float m_hp;
	bool hit_flag;

	int score;
	int m_time_hit;
	bool dead;

	int ani;//着弾アニメーション用
	int ani_time;//着弾アニメーション間隔タイム
	bool m_del;//削除チェック
	RECT_F m_eff;//着弾エフェクト描画用
};