#pragma once
//使用ヘッダー
#include"GameL\SceneObjManager.h"
//使用ネームスペース
using namespace GameL;

//オブジェクト：主人公
class CObjHero2 :public CObj
{
public:
	CObjHero2() {};
	~CObjHero2() {};
	void Init();//イニシャライズ
	void Action();//アクション
	void Draw();//ドロー

	float GetX2() { return m_px; }
	float GetY2() { return m_py; }
	float GetVY2() { return m_vy; }
	float GetVX2() { return m_vx; }

	void SetX2(float x) { m_px = x; }
	void SetY2(float y) { m_py = y; }
	void SetVY2(float vy) { m_vy = vy; }
	void SetVX2(float vx) { m_vx = vx; }

	void SetUp2(bool b) { m_hit_up = b; }
	void SetDown2(bool b) { m_hit_down = b; }
	void SetLeft2(bool b) { m_hit_left = b; }
	void SetRight2(bool b) { m_hit_right = b; }
	float GetHP2() { return m_hp; };



	bool  GetFlag2()
	{
		if (flag == true)
			return true;
		if (flag == false)
			return false;
	};

private:
	float m_px;//位置
	float m_py;
	float m_vx;//移動ベクトル
	float m_vy;
	float m_posture;//姿勢
	float m_hp;
	int m_time1;
	int m_time2;
	bool flag;
	bool hit_flag;
	int m_ani_time;//アニメーションフレーム動作間隔
	int m_ani_frame;//描画フレーム

	//blockとの衝突状態確認用
	bool m_hit_up;
	bool m_hit_down;
	bool m_hit_left;
	bool m_hit_right;

	bool m_attack;

};