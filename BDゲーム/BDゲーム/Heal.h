#pragma once
//�g�p�w�b�_�[
#include"GameL\SceneObjManager.h"
//�g�p����l�[���X�y�[�X
using namespace GameL;

//�I�u�W�F�N�g�F�^�C�g��
class CObjHeal :public CObj
{
public:
	CObjHeal(float x,float y);
	~CObjHeal() {};
	void Init();   //�C�j�V�����C�Y
	void Action(); //�A�N�V����
	void Draw();   //�h���[
	
private:
	
	int hp;

	float m_px;
	float m_py;
};