#pragma once
//�g�p����w�b�_�[
#include"GameL\SceneObjManager.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�I�u�W�F�N�g:�X�e�[�W
class CObjStage1 :public CObj
{
private:
	
	int map_flag;
	int map_num;
	bool flag;
	int score;
	
	int m_time;

	bool bossflag;
public:
	CObjStage1(int mapdata,int map_num);
	~CObjStage1() {};
	void Init();//�C�j�V�����C�Y
	void Action();//�A�N�V����
	void Draw();//�h���[

	void Getscore(int num) { score += num; }
	int Getmapnum() { return map_num; }
	int Getmapflag() { return map_flag; }
};