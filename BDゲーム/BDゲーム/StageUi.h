#pragma once
//使用ヘッダー
#include"GameL\SceneObjManager.h"
//使用ネームスペース
using namespace GameL;

//オブジェクト：主人公
class CObjStageUi :public CObj
{
public:
	CObjStageUi() {};
	~CObjStageUi() {};
	void Init();
	void Action();
	void Draw();
	void GetScore(int enscore) { score += enscore; }
private:

	int score;
	int scoreframe[4];
	int tall;

};