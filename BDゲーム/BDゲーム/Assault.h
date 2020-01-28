#pragma once
//使用するヘッダーファイル
#include"GameL\SceneObjManager.h"

using namespace GameL;

//オブジェクト：アサルトライフル
class CObjAssault :public CObj
{
public:
	CObjAssault(float x, float y);
	~CObjAssault() {};
	void Init();//イニシャライズ
	void Action();//アクション
	void Draw();//ドロー
private:
	float m_px;//位置X
	float m_py;//位置Y
};
