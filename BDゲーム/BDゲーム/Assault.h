#pragma once
//�g�p����w�b�_�[�t�@�C��
#include"GameL\SceneObjManager.h"

using namespace GameL;

//�I�u�W�F�N�g�F�A�T���g���C�t��
class CObjAssault :public CObj
{
public:
	CObjAssault(float x, float y);
	~CObjAssault() {};
	void Init();//�C�j�V�����C�Y
	void Action();//�A�N�V����
	void Draw();//�h���[
private:
	float m_px;//�ʒuX
	float m_py;//�ʒuY
};
