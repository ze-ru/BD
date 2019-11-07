#pragma once
#pragma once
#pragma once
//�g�p�w�b�_�[
#include"GameL\SceneObjManager.h"
//�g�p�l�[���X�y�[�X
using namespace GameL;

//�I�u�W�F�N�g�F��l��
class CObjAttack2 :public CObj
{
public:
	CObjAttack2(float x, float y);
	~CObjAttack2() {};
	void Init();//�C�j�V�����C�Y
	void Action();//�A�N�V����
	void Draw();//�h���[
	float GetX() { return m_px; };
	float GetY() { return m_py; };
private:
	float m_px;//�ʒu
	float m_py;
	float m_vx;//�ړ��x�N�g��
	float m_vy;
	float m_posture;//�p��
	float m_hp;
	int m_time1;
	int m_time2;
	int m_time3;
	bool flag;

	int m_ani_time;//�A�j���[�V�����t���[������Ԋu
	int m_ani_frame;//�`��t���[��

	//block�Ƃ̏Փˏ�Ԋm�F�p
	bool m_hit_up;
	bool m_hit_down;
	bool m_hit_left;
	bool m_hit_right;

	bool m_attack;
};