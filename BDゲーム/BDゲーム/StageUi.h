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

	void setdm(int dm) { dam = dm; }
	void setpos(float x, float y) { m_px = x; m_py = y; }
	void hitflag(bool h) { hit = h; }
private:

	int score;
	int scoreframe[4] = { 0,0,0,0 };
	int tall;

	int dam;

	bool hit;
	int hit_time;

	float m_px;
	float m_py;

};