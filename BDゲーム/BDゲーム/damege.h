#pragma once
//�g�p�w�b�_�[
#include"GameL\SceneObjManager.h"
//�g�p�l�[���X�y�[�X
using namespace GameL;

//�I�u�W�F�N�g�F��l��
class CObjDamege :public CObj
{
public:
	CObjDamege(int dm,float x,float y);
	~CObjDamege() {};
	void Init();
	void Action();
	void Draw();
private:
	int dam;
	int hit_time;
	float m_px;
	float m_py;
	int size;

};