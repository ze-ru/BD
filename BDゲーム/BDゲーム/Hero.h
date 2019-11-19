#pragma once
//�g�p�w�b�_�[
#include"GameL\SceneObjManager.h"
//�g�p�l�[���X�y�[�X
using namespace GameL;

//�I�u�W�F�N�g�F��l��
class CObjHero :public CObj
{
  public:
	CObjHero() {};
	~CObjHero() {};
	void Init();//�C�j�V�����C�Y
	void Action();//�A�N�V����
	void Draw();//�h���[

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
	  float m_px;//�ʒu
	  float m_py;
	  float m_vx;//�ړ��x�N�g��
	  float m_vy;
	  float m_posture;//�p��
	  float m_hp;
	  int m_time1;
	  int m_time2;
	  bool flag;
	  bool hit_flag;
	  int m_ani_time;//�A�j���[�V�����t���[������Ԋu
	  int m_ani_frame;//�`��t���[��

	  //block�Ƃ̏Փˏ�Ԋm�F�p
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