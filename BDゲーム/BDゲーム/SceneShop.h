#pragma once
//使用するヘッダーファイル
#include "GameL\DrawFont.h"
#include "GameL\WinInputs.h"
#include "GameL\SceneManager.h"
#include "GameHead.h"

//使用するネームスペース
using namespace GameL;

//シーン：ゲームタイトル
class CSceneShop :public CScene
{
public:
	CSceneShop();
	~CSceneShop();
	void InitScene(); //ゲームタイトルの初期化メソッド
	void Scene();     //ゲームタイトルの実行中メソッド
private:
};
