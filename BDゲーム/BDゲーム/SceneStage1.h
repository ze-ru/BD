#pragma once
//使用するヘッダー
#include"GameL\SceneManager.h"

//使用するネームスペース
using namespace GameL;

//シーン：ステージ
class CSceneStage1 :public CScene
{
public:
	CSceneStage1(int flag,int map_num,int hbullet,int hwp);
	~CSceneStage1();
	void InitScene();//初期化メソッド
	void Scene();//実行中メソッド

	int SetScene(int scenenum) { map_flag = scenenum; }
private:
	int map_flag;
	int mapnum;
	int wp;
	int bullet;
};