#pragma once
#include"GameL\SceneObjManager.h"

using namespace GameL;

class CObjLockEnemy2 :public CObj
{
public:
	CObjLockEnemy2(float x, float y);
	~CObjLockEnemy2() {};
	void Init();
	void Action();
	void Draw();

	float GetX() { return m_ex; };
	float GetY() { return m_ey; };
	int Getscore() { return score; }
	void SetDamege(int dm) { m_hp -= dm; }
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
	float m_hp;
	int score;
	bool hit_flag;
	int m_time;

	int attack_time;

	int ani;//���e�A�j���[�V�����p
	int ani_time;//���e�A�j���[�V�����Ԋu�^�C��
	bool m_del;//�폜�`�F�b�N
	RECT_F m_eff;//���e�G�t�F�N�g�`��p
};