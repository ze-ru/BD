#pragma once
//使用するヘッダー
#include "GameL\SceneObjManager.h"

//使用するネームスペース
using namespace GameL;

//オブジェクト:タイトル
class CObjGamerule2 :public CObj
{
public:
	CObjGamerule2() {};
	~CObjGamerule2() {};
	void Init();   //イニシャライズ
	void Action(); //アクション
	void Draw();   //ドロー

	void Getf() { s = true; }
private:
	int m_time;
	int m_frame;

	bool s;
};