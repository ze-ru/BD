#pragma once
//�g�p����w�b�_�[�t�@�C��
#include"GameL\SceneObjManager.h"

using namespace GameL;
//�I�u�W�F�N�g�F���C�t��
class CObjRifle :public CObj
{
public:
	CObjRifle(float x, float y);
	~CObjRifle() {};
	void Init();
	void Action();
	void Draw();

private:
	
	float m_px;//x���ʒu
	float m_py;//�����ʒu
	
};
