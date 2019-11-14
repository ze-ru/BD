#pragma once
//使用するヘッダー
#include "GameL\SceneObjManager.h"
#include"GameL\DrawTexture.h"
//使用するネームスペース
using namespace GameL;

//オブジェクト：ブロック
class CObjBlock3 :public CObj
{
public:
	CObjBlock3(int map3[11][156]);
	~CObjBlock3() {};
	void Init();    //イニシャライズ
	void Action();  //アクション
	void Draw();	//ドロー

	void SetScroll3(float s) { m_scroll3 = s; }
	float GetScroll3() { return m_scroll3; }
	int Getmap3() { int m3 = m_map3[0][0]; return m3; }
	void Setmap3(int x) { m_map3[0][0] = x; }
	void BlockHit3(float *x, float *y, bool scroll_on, bool *up, bool *down,
		bool *left, bool *right, float *vx, float *vy);

private:
	void BlockDraw3(float x, float y, RECT_F *dst, float c[]);
	int m_map3[11][156]; //マップ情報
	float m_scroll3; //左右スクロール用

};