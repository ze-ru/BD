#pragma once
//�g�p�w�b�_�[
#include"GameL\SceneObjManager.h"
//�g�p����l�[���X�y�[�X
using namespace GameL;

//�I�u�W�F�N�g�F�^�C�g��
class CObjStage1Clear :public CObj
{
public:
	CObjStage1Clear() {};
	~CObjStage1Clear() {};
	void Init();   //�C�j�V�����C�Y
	void Action(); //�A�N�V����
	void Draw();   //�h���[
	void SetScore(int s) { score += s; }//�X�R�A�֐�
	void Setdead() { deadflag = true; }
private:
	bool key;//�L�[�t���O
	int score;
	bool deadflag;//BOSS���j�t���O
};