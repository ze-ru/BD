#pragma once
//使用するヘッダー
#include "GameL\SceneObjManager.h"
#include"GameL\DrawTexture.h"
//使用するネームスペース
using namespace GameL;

//オブジェクト：ブロック
class CObjBlock :public CObj
{
public :
	CObjBlock(int map[11][300],int mapnum);
	~CObjBlock() {};
	void Init();     //イニシャライズ
	void Action();   //アクション
	void Draw();   
	
	void SetScroll(float s) { m_scroll = s; }
	float GetScroll() { return m_scroll; }
	int Getmap1() { int m = m_map[0][0]; return m; }
	void SetDead() { dead_flag = true; }
	
	//ブロックとの当たり判定
	void BlockHit(float *x, float *y, bool scroll_on, bool *up, bool *down,
		bool *left, bool *right, float *vx, float *vy);

	void SetBlock(int flag);

	void BlockBossHit(float *x, float *y, bool scroll_on, bool *up, bool *down,
		bool *left, bool *right, float *vx, float *vy);

	void BulletHit(float *x, float *y, bool scroll_on, bool *up, bool *down,
		bool *left, bool *right);

private:
	void BlockDraw(float x, float y, RECT_F *dst, float c[],int num);
	int m_map[11][300]; //マップ情報
	int map_num;
	float m_scroll; //左右スクロール用
	bool dead_flag;

	int m_time;

	bool bossflag;

	int count;
	
};