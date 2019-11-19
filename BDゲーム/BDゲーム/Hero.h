#pragma once
//使用ヘッダー
#include"GameL\SceneObjManager.h"
//使用ネームスペース
using namespace GameL;

//オブジェクト：主人公
class CObjHero :public CObj
{
  public:
	CObjHero() {};
	~CObjHero() {};
	void Init();//イニシャライズ
	void Action();//アクション
	void Draw();//ドロー

	float GetX() { return m_px; }
	float GetY() { return m_py; }
	float GetVY() { return m_vy; }
	float GetVX() { return m_vx; }

	void SetX(float x) { m_px = x; }
	void SetY(float y) { m_py = y; }
	void SetVY(float vy) { m_vy = vy; }
	void SetVX(float vx) { m_vx = vx; }

	void SetUp(bool b) { m_hit_up = b; }
	void SetDown(bool b) { m_hit_down = b; }
	void SetLeft(bool b) { m_hit_left = b; }
	void SetRight(bool b) { m_hit_right = b; }
	float GetHP() { return m_hp; };
	void EnemyHit(int enemynume);

	int GetBT() { return m_block_type; }
	void SetBT(int t) { m_block_type = t; }
	

	bool  GetFlag() 
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

	  int m_block_type;

	  bool m_attack;
	  float m_dead;
	  bool m_y_flag;
	  int m_y_num;
	  bool m_dead_flag;

};