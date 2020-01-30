#pragma once
#include"GameL\SceneObjManager.h"

using namespace GameL;

//オブジェクト:アサルトライフルバレット（敵）
class CObjAssaultBullet :public CObj
{
public:
	CObjAssaultBullet(float x, float y);
	~CObjAssaultBullet() {};
	void Init();//イニシャライズ
	void Action();//アクション
	void Draw();//ドロー

	float GetX() { return m_px; };//X座標を返す
	float GetY() { return m_py; };//Y座標を返す
private:
	float m_vx;//X軸加速度
	float m_vy;//Y軸加速度
	float m_px;//X座標
	float m_py;//Y座標
	
	bool m_hit_up;//当たり判定：上
	bool m_hit_down;//当たり判定：下
	bool m_hit_left;//当たり判定：左
	bool m_hit_right;//当たり判定：右
	float m_time;//弾丸削除用
	int m_count;//弾丸の方向決定用
	int dm;//ダメージ

	bool dm_hit_flag;
};
bool UnitVec(float *vx, float *vy);//正規化関数