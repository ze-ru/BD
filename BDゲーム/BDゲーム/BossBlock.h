#pragma once
//使用するヘッダーファイル
#include"GameL\SceneObjManager.h"

//使用するネームスペース
using namespace GameL;

//シーン:ゲームタイトル
class CObjBossBlock :public CObj
{
public:
	CObjBossBlock(float x,float y);
	~CObjBossBlock() {};
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


	bool m_hit_down;
	bool m_hit_up;
	bool m_hit_left;
	bool m_hit_right;

};
