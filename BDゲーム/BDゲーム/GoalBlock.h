#pragma once
//使用するヘッダーファイル
#include"GameL\SceneObjManager.h"

//使用するネームスペース
using namespace GameL;

//シーン:ゲームタイトル
class CObjGoalBlock :public CObj
{
public:
	CObjGoalBlock(float x, float y);
	~CObjGoalBlock() {};
	void Init();//イニシャライズ
	void Action();//アクション
	void Draw();//ドロー

private:
	float m_bx;
	float m_by;
	float m_vx;
	float m_vy;

	float hx;
	float hy;

	float hvx;
	float hvy;

	bool bossflag;

	

};
