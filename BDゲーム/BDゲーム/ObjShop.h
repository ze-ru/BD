#pragma once#pragma once
//�g�p�w�b�_�[
#include"GameL\SceneManager.h"

//�g�p�l�[���X�y�[�X
using namespace GameL;

//�V�[���F���C��
class CObjShop :public CObj
{
public:
	CObjShop() {};
	~CObjShop() {};
	void Init() ;
	void Action() ;
	void Draw() ;
private:
	bool m_key_flag;
	bool key;
	bool keyS;
};