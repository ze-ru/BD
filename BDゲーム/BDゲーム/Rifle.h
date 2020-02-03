#pragma once
//使用するヘッダーファイル
#include"GameL\SceneObjManager.h"

using namespace GameL;
//オブジェクト：ライフル
class CObjRifle :public CObj
{
public:
	CObjRifle(float x, float y);
	~CObjRifle() {};
	void Init();
	void Action();
	void Draw();

private:
	
	float m_px;//x軸位置
	float m_py;//ｙ軸位置
	
};
