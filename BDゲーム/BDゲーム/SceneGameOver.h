#pragma once
//�g�p����w�b�_�[�t�@�C��
#include "GameL\SceneManager.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�I�u�W�F�N�g�F�^�C�g��
class CSceneGameOver : public CScene
{
public:
	CSceneGameOver(int mapflag,int mapnum,int w,int b);
	~CSceneGameOver();
	void InitScene();//���������\�b�h
	void Scene();   //���s�����\�b�h
private:
	int map_flag;
	int map_num;
	int wp;
	int bullet;
};