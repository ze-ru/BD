#pragma once
//�g�p����w�b�_�[
#include "GameL\SceneObjManager.h"
#include"GameL\DrawTexture.h"
//�g�p����l�[���X�y�[�X
using namespace GameL;

//�I�u�W�F�N�g�F�u���b�N
class CObjBlock :public CObj
{
public :
	CObjBlock(int map[11][157]);
	~CObjBlock() {};
	void Init();     //�C�j�V�����C�Y
	void Action();   //�A�N�V����
	void Draw();   
	
	void SetScroll(float s) { m_scroll = s; }
	float GetScroll() { return m_scroll; }
	int Getm_map() { return m_map[11][157]; }
	//�u���b�N�Ƃ̓����蔻��
	void BlockHit(float *x, float *y, bool scroll_on, bool *up, bool *down,
		bool *left, bool *right, float *vx, float *vy);
private:
	void BlockDraw(float x, float y, RECT_F *dst, float c[]);
	int m_map[11][157]; //�}�b�v���

	float m_scroll; //���E�X�N���[���p
	
};