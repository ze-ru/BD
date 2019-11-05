#pragma once
//�g�p�w�b�_�[
#include"GameL\SceneObjManager.h"
//�g�p�l�[���X�y�[�X
using namespace GameL;

//�I�u�W�F�N�g�F��l��
class CObjHero2 :public CObj
{
public:
	CObjHero2() {};
	~CObjHero2() {};
	void Init();//�C�j�V�����C�Y
	void Action();//�A�N�V����
	void Draw();//�h���[

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

	bool m_attack;

};