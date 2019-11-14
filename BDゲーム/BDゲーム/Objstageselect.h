#pragma once
//使用ヘッダー
#include"GameL\SceneObjManager.h"
//使用するネームスペース
using namespace GameL;

//オブジェクト：タイトル
class CObjstageselect :public CObj
{
public:
	CObjstageselect() {};
	~CObjstageselect() {};
	void Init();   //イニシャライズ
	void Action(); //アクション
	void Draw();   //ドロー
	int Getmap1(int x, int y) { return map[x][y]; }
	int Getmap2(int x, int y) { return map2[x][y]; }
	int Getmap3(int x, int y) { return map3[x][y]; }

private:
	int map[11][157];
	int map2[11][156];
	int map3[11][156];
	float m_mou_x;
	float m_mou_y;
	bool m_mou_r;
	bool m_mou_l;
	bool m_key_flag;
	bool key;
};