#pragma once
//使用するヘッダーファイル
#include"GameL\SceneObjManager.h"

using namespace GameL;
//オブジェクト：シールド
class CObjShield :public CObj
{
public:
	CObjShield(float x, float y);
	~CObjShield() {};
	void Init();
	void Action();
	void Draw();

	void SetDead() { m_dead = true; }

private:

	float m_ex;//x軸位置
	float m_ey;//y軸位置

	int m_posture;//向き
	int dm;//ダメージ数
	bool hit_flag;//当たっているかどうかの判別
	bool m_dead;//オブジェクトを削除するかの判別用
	int m_time_hit;//Hitする回数を制御用
	bool m_hit_flag;//主人公との接触判定用
	bool dm_hit_flag;//削除判定
};