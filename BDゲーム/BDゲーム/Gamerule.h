#pragma once
//�g�p����w�b�_�[�t�@�C��
#include "GameL\DrawFont.h"
#include "GameL\WinInputs.h"
#include "GameL\SceneManager.h"

#include "GameHead.h"
#include "ObjTitle.h"

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
