#pragma once
//使用するヘッダーファイル
#include"GameL\SceneObjManager.h"

//使用するネームスペース
using namespace GameL;

//シーン:ゲームタイトル
class CObjSwitch :public CObj
{
public:
	CObjSwitch() {};
	~CObjSwitch() {};
	void Init();//イニシャライズ
	void Action();//アクション
	void Draw();//ドロー
private:

};