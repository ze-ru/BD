#pragma once
//使用するヘッダー
#include"GameL\SceneObjManager.h"

//使用するネームスペース
using namespace GameL;

//オブジェクト：ダメージ
class CObjDamege :public CObj
{
public:
	CObjDamege(int dm,float x,float y);
	~CObjDamege() {};
	void Init();//イニシャライズ
	void Action();//アクション
	void Draw();//ドロー

private:
	int dam;
	int hit_time;
	float m_px;
	float m_py;
	int size;

};