#pragma once
//使用ヘッダー
#include"GameL\SceneObjManager.h"
//使用するネームスペース
using namespace GameL;

//オブジェクト：タイトル
class CObjHeal :public CObj
{
public:
	CObjHeal(float x,float y);
	~CObjHeal() {};
	void Init();   //イニシャライズ
	void Action(); //アクション
	void Draw();   //ドロー
	
private:
	
	int hp;

	float m_px;
	float m_py;
};