#pragma once
//�g�p����w�b�_�[
#include "GameL\SceneObjManager.h"
//�g�p����l�[���X�y�[�X
using namespace GameL;

//�I�u�W�F�N�g�F�u���b�N
class CObjBlock :public CObj
{
public :
	CObjBlock(int map[11][157]);
	~CObjBlock() {};
	void Init();     //�C�j�V�����C�Y
	void Action();   //�A�N�V����
	void Draw();     //�h���[
private:
	int m_map[11][157]; //�}�b�v���

	float m_scroll; //���E�X�N���[���p
};