#pragma once
//�g�p����w�b�_�[�t�@�C��
#include"GameL\SceneObjManager.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�V�[��:�Q�[���^�C�g��
class CObjBossBlock :public CObj
{
public:
	CObjBossBlock(float x, float y);
	~CObjBossBlock() {};
	void Init();//�C�j�V�����C�Y
	void Action();//�A�N�V����
	void Draw();//�h���[

	void SetBossFlag(bool b) { m_boss_flag = b; }//
private:
	float m_bx;
	float m_by;
	float m_vx;
	float m_vy;

	int m_block_type;

	bool m_hit_down;
	bool m_hit_up;
	bool m_hit_left;
	bool m_hit_right;



	bool m_boss_flag;
};
