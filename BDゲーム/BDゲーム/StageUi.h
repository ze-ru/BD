#pragma once
//�g�p����w�b�_�[
#include"GameL\SceneObjManager.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�I�u�W�F�N�g�FUI
class CObjStageUi :public CObj
{
public:
	CObjStageUi() {};
	~CObjStageUi() {};
	void Init();//�C�j�V�����C�Y
	void Action();//�A�N�V����
	void Draw();//�h���[

	void GetScore(int enscore) { score += enscore; }
private:

	int score;
};