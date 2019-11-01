#pragma once
//使用するヘッダー
#include "GameL\SceneObjManager.h"
#include"GameL\DrawTexture.h"
//使用するネームスペース
using namespace GameL;

//オブジェクト：ブロック
class CObjBlock2 :public CObj
{
public:
	CObjBlock2(int map2[11][156]);
	~CObjBlock2() {};
	void Init();     //イニシャライズ
	void Action();   //アクション
	void Draw();

	void SetScroll(float s) { m_scroll = s; }
	float GetScroll() { return m_scroll; }

	//ブロックとの当たり判定
	void BlockHit2(float *x, float *y, bool scroll_on, bool *up, bool *down,
		bool *left, bool *right, float *vx, float *vy);
private:
	void BlockDraw2(float x, float y, RECT_F *dst, float c[]);
	int m_map2[11][157]; //マップ情報

	float m_scroll; //左右スクロール用

};