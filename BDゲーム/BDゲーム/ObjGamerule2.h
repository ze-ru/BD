#pragma once
//�g�p����w�b�_�[
#include "GameL\SceneObjManager.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�I�u�W�F�N�g:�^�C�g��
class CObjGamerule2 :public CObj
{
public:
	CObjGamerule2() {};
	~CObjGamerule2() {};
	void Init();   //�C�j�V�����C�Y
	void Action(); //�A�N�V����
	void Draw();   //�h���[

	void Getf() { s = true; }
private:
	int m_time;
	int m_frame;

	bool s;
};