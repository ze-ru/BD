#pragma once
//使用するヘッダーファイル
#include "GameL\SceneManager.h"

//使用するネームスペース
using namespace GameL;

//オブジェクト：タイトル
class CSceneGameOver : public CScene
{
public:
	CSceneGameOver(int mapflag,int mapnum);
	~CSceneGameOver();
	void InitScene();//初期化メソッド
	void Scene();   //実行中メソッド
private:
	int map_flag;//背景番号
	int map_num;//ブロック描画番号
	
};