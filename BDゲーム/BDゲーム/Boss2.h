#pragma once
//
#include"GameL\SceneObjManager.h"
//
using namespace GameL;

//
class CObjBoss2 :public CObj
{
public:
	CObjBoss2(float x, float y);
	~CObjBoss2() {};
	void Init();
	void Action();
	void Draw();

	void enemycount() { dead_count++; }
	
private:
	float m_ex;
	float m_ey;
	float m_vx;
	float m_vy;

	bool hit_flag;
	int m_time;

	bool enemy_flag;
	int enemy_count;
	int dead_count;
	int m_hp;

	int m_hit_time;
	bool m_hit_flag;
	int m_hit_data;

	int hit_count;

	int ani;//���e�A�j���[�V�����p
	int ani_time;//���e�A�j���[�V�����Ԋu�^�C��
	bool m_del;//�폜�`�F�b�N
	RECT_F m_eff;//���e�G�t�F�N�g�`��p
};