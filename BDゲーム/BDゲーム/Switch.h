#pragma once
//使用するヘッダーファイル
#include"GameL\SceneObjManager.h"

//使用するネームスペース
using namespace GameL;

//シーン:ゲームタイトル
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

	bool m_hit_down;
	bool m_hit_up;
	bool m_hit_left;
	bool m_hit_right;

	int flag;
};