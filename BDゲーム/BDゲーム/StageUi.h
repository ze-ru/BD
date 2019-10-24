#pragma once
//使用ヘッダー
#include"GameL\SceneObjManager.h"
//使用ネームスペース
using namespace GameL;

//オブジェクト：主人公
class CObjStageUi :public CObj
{
	CObjStageUi() {};
	~CObjStageUi() {};
	void Init();
	void Action();
	void Draw();
private:
};