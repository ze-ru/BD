#pragma once
#pragma once
//使用ヘッダー
#include"GameL\SceneObjManager.h"
//使用ネームスペース
using namespace GameL;

//オブジェクト：主人公
class CObjAttack :public CObj
{
public:
	CObjAttack(float x,float y);
	~CObjAttack() {};
	void Init();//イニシャライズ
	void Action();//アクション
	void Draw();//ドロー
	float GetX() { return m_px; };
	float GetY() { return m_py; };
private:
	float m_px;//位置
	float m_py;
	float m_vx;//移動ベクトル
	float m_vy;
	float m_posture;//姿勢
	float m_hp;
	int m_time1;
	int m_time2;
	int m_time3;
	bool flag;

	int m_ani_time;//アニメーションフレーム動作間隔
	int m_ani_frame;//描画フレーム

	//blockとの衝突状態確認用
	bool m_hit_up;
	bool m_hit_down;
	bool m_hit_left;
	bool m_hit_right;

	bool m_attack;
	int dm;

	bool hit_flag;
	int hit_time;
};