#pragma once
//使用ヘッダー
#include"GameL\SceneManager.h"

//使用ネームスペース
using namespace GameL;

//シーン：メイン　ステージ2
class CSceneStage2 :public CScene
{
public:
	CSceneStage2();
	~CSceneStage2();
	void InitScene();
	void Scene();
private:
};