#pragma once
//使用するヘッダー
#include "GameL\SceneObjManager.h"
//使用するネームスペース
using namespace GameL;

//オブジェクト：タイトル
class CObjGameOver : public CObj
{
public:
	CObjGameOver(int x, int y,int w,int b);
	~CObjGameOver() {};
	void Init();    //イニシャライズ
	void Action();  //アクション
	void Draw();    //ドロー
private:
	bool m_key_flag;//キーフラグ

	bool key;

	int mapflag;
	int mapnum;

	int wp;
	int bullet;
};