#pragma once
//�g�p����w�b�_�[
#include "GameL\SceneObjManager.h"
#include"GameL\DrawTexture.h"
//�g�p����l�[���X�y�[�X
using namespace GameL;

class CObjShopOBJ :public CObj
{
public:
	CObjShopOBJ(float x,float y);
	~CObjShopOBJ() {};
	void Init();
	void Action();
	void Draw();
private:

	float px;
	float py;
	
};