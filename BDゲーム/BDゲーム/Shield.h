#pragma once
//�g�p����w�b�_�[�t�@�C��
#include"GameL\SceneObjManager.h"

using namespace GameL;
//�I�u�W�F�N�g�F�V�[���h
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

	float m_ex;//x���ʒu
	float m_ey;//y���ʒu

	int m_posture;//����
	int dm;//�_���[�W��
	bool hit_flag;//�������Ă��邩�ǂ����̔���
	bool m_dead;//�I�u�W�F�N�g���폜���邩�̔��ʗp
	int m_time_hit;//Hit����񐔂𐧌�p
	bool m_hit_flag;//��l���Ƃ̐ڐG����p
	bool dm_hit_flag;//�폜����
};