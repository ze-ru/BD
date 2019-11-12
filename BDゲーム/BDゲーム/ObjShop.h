#pragma once#pragma once
//使用ヘッダー
#include"GameL\SceneManager.h"

//使用ネームスペース
using namespace GameL;

//シーン：メイン
class CObjShop :public CObj
{
public:
	CObjShop() {};
	~CObjShop() {};
	void Init() ;
	void Action() ;
	void Draw() ;
private:
	bool m_key_flag;
	bool key;
	bool keyS;
};