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
	int Getscore() { return score; }
	void SetDamege(int dm) { m_hp -= dm; }
	float GetX() { return m_px; };
	float GetY() { return m_py; };
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

	int ani;//���e�A�j���[�V�����p
	int ani_time;//���e�A�j���[�V�����Ԋu�^�C��
	bool m_del;//�폜�`�F�b�N
	RECT_F m_eff;//���e�G�t�F�N�g�`��p
};