#pragma once
//使用ヘッダー
#include"GameL\SceneObjManager.h"
//使用するネームスペース
using namespace GameL;

//オブジェクト：タイトル
class CObjStage1Clear :public CObj
{
public:
	CObjStage1Clear() {};
	~CObjStage1Clear() {};
	void Init();   //イニシャライズ
	void Action(); //アクション
	void Draw();   //ドロー
	void SetScore(int s) { score += s; }//スコア関数
	void Setdead() { deadflag = true; }
private:
	bool key;//キーフラグ
	int score;
	bool deadflag;//BOSS撃破フラグ
};