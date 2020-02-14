#pragma once
//使用するヘッダーファイル
#include"GameL\SceneObjManager.h"

//使用するネームスペース
using namespace GameL;

//オブジェクト：スイッチ
class CObjSwitch :public CObj
{
public:
	CObjSwitch(float x,float y);
	~CObjSwitch() {};
	void Init();//イニシャライズ
	void Action();//アクション
	void Draw();//ドロー

private:
	float m_sx;
	float m_sy;

	bool flag;
};