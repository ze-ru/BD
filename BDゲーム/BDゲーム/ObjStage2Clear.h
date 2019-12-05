#pragma once
//使用ヘッダー
#include"GameL\SceneObjManager.h"
//使用するネームスペース
using namespace GameL;

//オブジェクト：タイトル
class CObjStage2Clear :public CObj
{
public:
	CObjStage2Clear() {};
	~CObjStage2Clear() {};
	void Init();   //イニシャライズ
	void Action(); //アクション
	void Draw();   //ドロー
	

private:
	int m_px;
	int m_py;
	int m_vx;
	int m_vy;
	int time;
};