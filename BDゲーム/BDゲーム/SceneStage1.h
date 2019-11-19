#pragma once
//使用ヘッダー
#include"GameL\SceneManager.h"

//使用ネームスペース
using namespace GameL;

//シーン：メイン
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