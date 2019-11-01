#pragma once
//�g�p����w�b�_�[
#include "GameL\SceneObjManager.h"
#include"GameL\DrawTexture.h"
//�g�p����l�[���X�y�[�X
using namespace GameL;

//�I�u�W�F�N�g�F�u���b�N
class CObjBlock2 :public CObj
{
public:
	CObjBlock2(int map2[11][156]);
	~CObjBlock2() {};
	void Init();     //�C�j�V�����C�Y
	void Action();   //�A�N�V����
	void Draw();

	void SetScroll(float s) { m_scroll = s; }
	float GetScroll() { return m_scroll; }

	//�u���b�N�Ƃ̓����蔻��
	void BlockHit2(float *x, float *y, bool scroll_on, bool *up, bool *down,
		bool *left, bool *right, float *vx, float *vy);
private:
	void BlockDraw2(float x, float y, RECT_F *dst, float c[]);
	int m_map2[11][157]; //�}�b�v���

	float m_scroll; //���E�X�N���[���p

};