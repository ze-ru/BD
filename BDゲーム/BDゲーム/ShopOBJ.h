#pragma once
//使用するヘッダー
#include "GameL\SceneObjManager.h"
#include"GameL\DrawTexture.h"
//使用するネームスペース
using namespace GameL;

class CObjShopOBJ :public CObj
{
public:
	CObjShopOBJ(float x,float y);
	~CObjShopOBJ() {};
	void Init();
	void Action();
	void Draw();
private:

	float px;
	float py;
	
};