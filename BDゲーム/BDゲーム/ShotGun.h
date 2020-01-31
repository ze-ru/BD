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
	float m_vx;//��l�q��X������
	float m_vy;//��l�q��Y������
	float m_px;//��l����X��
	float m_py;//��l����Y��

	bool m_hit_up;//�㔻��
	bool m_hit_down;//������
	bool m_hit_left;//������
	bool m_hit_right;//�E����
	float m_time;//���Ԃ𑪂�
	int m_count;//�J�E���g�𑪂�
	int dm;//�_���[�W

	int r_rad;//�p�x

	float m_v;

	bool dm_hit_flag;
};