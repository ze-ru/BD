#pragma once
//�g�p����w�b�_�[�t�@�C��
#include"GameL\SceneObjManager.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�V�[��:�Q�[���^�C�g��
class CObjGoalBlock :public CObj
{
public:
	CObjGoalBlock(float x, float y);
	~CObjGoalBlock() {};
	void Init();//�C�j�V�����C�Y
	void Action();//�A�N�V����
	void Draw();//�h���[

private:
	float m_bx;
	float m_by;

};
