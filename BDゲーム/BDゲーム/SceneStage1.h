#pragma once
//�g�p����w�b�_�[
#include"GameL\SceneManager.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�V�[���F�X�e�[�W
class CSceneStage1 :public CScene
{
public:
	CSceneStage1(int flag,int map_num,int hbullet,int hwp);
	~CSceneStage1();
	void InitScene();//���������\�b�h
	void Scene();//���s�����\�b�h

	int SetScene(int scenenum) { map_flag = scenenum; }
private:
	int map_flag;
	int mapnum;
	int wp;
	int bullet;
};