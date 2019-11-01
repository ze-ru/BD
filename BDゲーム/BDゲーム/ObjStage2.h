#pragma once
//使用ヘッダー
#include"GameL\SceneObjManager.h"

//使用ネームスペース
using namespace GameL;

//シーン:メイン
class CObjStage2 :public CObj
{

private:
	bool Sc_flag2=false;
public:
	CObjStage2() {};
	~CObjStage2() {};
	void Init();
	void Action();
	void Draw();


};