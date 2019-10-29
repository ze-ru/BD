#pragma once
//使用ヘッダー
#include"GameL\SceneObjManager.h"

//使用ネームスペース
using namespace GameL;

//シーン:メイン
class CObjStage2 :public CObj
{
public:
	CObjStage2() {};
	~CObjStage2() {};
	void Init();
	void Action();
	void Draw();
private:
};