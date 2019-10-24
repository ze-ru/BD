#pragma once
//使用するヘッダー
#include "GameL\SceneObjManager.h"
//使用するネームスペース
using namespace GameL;

//オブジェクト：ブロック
class CObjBlock :public CObj
{
public :
	CObjBlock(int map[11][157]);
	~CObjBlock() {};
	void Init();     //イニシャライズ
	void Action();   //アクション
	void Draw();     //ドロー
private:
	int m_map[11][157]; //マップ情報

	float m_scroll; //左右スクロール用
};