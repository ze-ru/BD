#pragma once
//�g�p����w�b�_�[�t�@�C��
#include"GameL\SceneObjManager.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�V�[��:�Q�[���^�C�g��
class CObjSwitch2 :public CObj
{
public:
	CObjSwitch2(float x, float y);
	~CObjSwitch2() {};
	void Init();//�C�j�V�����C�Y
	void Action();//�A�N�V����
	void Draw();//�h���[

private:
	float m_sx;
	float m_sy;

	bool m_hit_down;
	bool m_hit_up;
	bool m_hit_left;
	bool m_hit_right;

	int flag;
};