#pragma once
#include"GameL\SceneObjManager.h"

using namespace GameL;

//�I�u�W�F�N�g:�A�T���g���C�t���o���b�g�i�G�j
class CObjAssaultBullet :public CObj
{
public:
	CObjAssaultBullet(float x, float y);
	~CObjAssaultBullet() {};
	void Init();//�C�j�V�����C�Y
	void Action();//�A�N�V����
	void Draw();//�h���[

	float GetX() { return m_px; };//X���W��Ԃ�
	float GetY() { return m_py; };//Y���W��Ԃ�
private:
	float m_vx;//X�������x
	float m_vy;//Y�������x
	float m_px;//X���W
	float m_py;//Y���W
	
	bool m_hit_up;//�����蔻��F��
	bool m_hit_down;//�����蔻��F��
	bool m_hit_left;//�����蔻��F��
	bool m_hit_right;//�����蔻��F�E
	float m_time;//�e�ۍ폜�p
	int m_count;//�e�ۂ̕�������p
	int dm;//�_���[�W

	bool dm_hit_flag;
};
bool UnitVec(float *vx, float *vy);//���K���֐�