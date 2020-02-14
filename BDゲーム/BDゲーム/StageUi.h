#pragma once
//使用するヘッダー
#include"GameL\SceneObjManager.h"

//使用するネームスペース
using namespace GameL;

//オブジェクト：UI
class CObjStageUi :public CObj
{
public:
	CObjStageUi() {};
	~CObjStageUi() {};
	void Init();//イニシャライズ
	void Action();//アクション
	void Draw();//ドロー

	void GetScore(int enscore) { score += enscore; }
private:

	int score;
};