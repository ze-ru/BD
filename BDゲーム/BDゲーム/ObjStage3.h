#pragma once
//使用ヘッダー
#include"GameL\SceneObjManager.h"

//使用ネームスペース
using namespace GameL;

//シーン:メイン
class CObjStage3 :public CObj
{

//private:
//	bool Sc_flag3 = false;
public:
	CObjStage3() {};
	~CObjStage3() {};
	void Init();
	void Action();
	void Draw();
};