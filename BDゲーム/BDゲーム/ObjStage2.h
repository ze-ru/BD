#pragma once
//�g�p�w�b�_�[
#include"GameL\SceneObjManager.h"

//�g�p�l�[���X�y�[�X
using namespace GameL;

//�V�[��:���C��
class CObjStage2 :public CObj
{

private:
	bool Sc_flag2=false;
public:
	CObjStage2() {};
	~CObjStage2() {};
	void Init();
	void Action();
	void Draw();


};