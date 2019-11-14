#pragma once
//�g�p����w�b�_�[
#include "GameL\SceneObjManager.h"
#include"GameL\DrawTexture.h"
//�g�p����l�[���X�y�[�X
using namespace GameL;

//�I�u�W�F�N�g�F�u���b�N
class CObjBlock3 :public CObj
{
public:
	CObjBlock3(int map3[11][156]);
	~CObjBlock3() {};
	void Init();    //�C�j�V�����C�Y
	void Action();  //�A�N�V����
	void Draw();	//�h���[

	void SetScroll3(float s) { m_scroll3 = s; }
	float GetScroll3() { return m_scroll3; }
	int Getmap3() { int m3 = m_map3[0][0]; return m3; }
	void Setmap3(int x) { m_map3[0][0] = x; }
	void BlockHit3(float *x, float *y, bool scroll_on, bool *up, bool *down,
		bool *left, bool *right, float *vx, float *vy);

private:
	void BlockDraw3(float x, float y, RECT_F *dst, float c[]);
	int m_map3[11][156]; //�}�b�v���
	float m_scroll3; //���E�X�N���[���p

};