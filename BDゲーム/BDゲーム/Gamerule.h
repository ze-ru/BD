#pragma once
//�g�p����w�b�_�[�t�@�C��
#include "GameL\SceneManager.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�V�[���F�Q�[���^�C�g��
class CSceneGamerule :public CScene
{
public:
	CSceneGamerule();
	~CSceneGamerule();
	void InitScene(); //�Q�[���^�C�g���̏��������\�b�h
	void Scene();     //�Q�[���^�C�g���̎��s�����\�b�h
private:
};
