#pragma once
//�g�p�w�b�_�[
#include"GameL\SceneObjManager.h"
//�g�p����l�[���X�y�[�X
using namespace GameL;

//�I�u�W�F�N�g�F�^�C�g��
class CObjStage2Clear :public CObj
{
public:
	CObjStage2Clear() {};
	~CObjStage2Clear() {};
	void Init();   //�C�j�V�����C�Y
	void Action(); //�A�N�V����
	void Draw();   //�h���[
	

private:
	int m_px;
	int m_py;
	int m_vx;
	int m_vy;
	int time;
};