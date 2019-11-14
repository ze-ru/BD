#pragma once
//使用ヘッダー
#include"GameL\SceneManager.h"

//使用ネームスペース
using namespace GameL;

//シーン：メイン
class SceneWeaponShop :public Scene
{
public:
	SceneWeaponShop() {};
	~SceneWeaponShop() {};
	void Init();
	void Action();
	void Draw();
private:
};