#pragma once
//�g�p�w�b�_�[
#include"GameL\SceneObjManager.h"
//�g�p����l�[���X�y�[�X
using namespace GameL;

//�I�u�W�F�N�g�F�^�C�g��
class CObjStage2Clear :public CObj
{
public:
	CObjStage2Clear() {};
	~CObjStage2Clear() {};
	void Init();   //�C�j�V�����C�Y
	void Action(); //�A�N�V����
	void Draw();   //�h���[
	int Getmap1(int x, int y) { return map[x][y]; }
	int Getmap2(int x, int y) { return map2[x][y]; }
	int SetScore() { score += 100; }//�X�R�A�֐�

private:
	int map[11][157];
	int map2[11][156];
	int Sc2;
	int score;
	int time;
	int count;
};