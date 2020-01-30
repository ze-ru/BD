#pragma once
//使用するヘッダー
#include "GameL\SceneObjManager.h"
//使用するネームスペース
using namespace GameL;

//オブジェクト：タイトル
class CObjGameOver : public CObj
{
public:
	CObjGameOver(int x, int y);
	~CObjGameOver() {};
	void Init();    //イニシャライズ
	void Action();  //アクション
	void Draw();    //ドロー
private:
	bool m_key_flag;//キーフラグ

	bool key;       //上下キーの判定

	int mapflag;    //背景番号
	int mapnum;     //ブロック描画番号

	
};