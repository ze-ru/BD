#pragma once
//�g�p�w�b�_�[
#include"GameL\SceneManager.h"

//�g�p�l�[���X�y�[�X
using namespace GameL;

//�V�[���F���C��
class CSceneStage1 :public CScene
{
public:
	CSceneStage1(int flag,int map_num);
	~CSceneStage1();
	void InitScene();
	void Scene();

	int SetScene(int scenenum) { map_flag = scenenum; }
private:
	int map_flag;
	int mapnum;

};