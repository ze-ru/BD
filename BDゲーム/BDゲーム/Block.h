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
	CObjBlock(int map[11][157],int mapnum);
	~CObjBlock() {};
	void Init();     //�C�j�V�����C�Y
	void Action();   //�A�N�V����
	void Draw();   
	
	void SetScroll(float s) { m_scroll = s; }
	float GetScroll() { return m_scroll; }
	int Getmap1() { int m = m_map[0][0]; return m; }
	void Setmap1(int x) { m_map[0][0] = x; }
	
	//�u���b�N�Ƃ̓����蔻��
	void BlockHit(float *x, float *y, bool scroll_on, bool *up, bool *down,
		bool *left, bool *right, float *vx, float *vy,int *bt);
	void SetBlock(int flag);
	void BlockBossHit(float *x, float *y, bool scroll_on, bool *up, bool *down,
		bool *left, bool *right, float *vx, float *vy);
private:
	void BlockDraw(float x, float y, RECT_F *dst, float c[],int num);
	int m_map[11][157]; //�}�b�v���
	int map_num;
	float m_scroll; //���E�X�N���[���p
	
};