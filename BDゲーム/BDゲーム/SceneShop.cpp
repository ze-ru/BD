//STL�f�o�b�O�@�\��OFF�ɂ���
#define _SECURE_SCL (0)
#define _HAS_ITERATOR_DEBUGGING (0)

//GameL�Ŏg�p����w�b�_�[
#include "GameL\SceneObjManager.h"
#include "GameL\DrawFont.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�g�p�w�b�_�[
#include "GameHead.h"

//�R���X�g���N�^
CSceneShop::CSceneShop()
{

}

//�f�X�g���N�^
CSceneShop::~CSceneShop()
{

}

//�Q�[�����C�����������\�b�h
void CSceneShop::InitScene()
{
	//�o�͂����镶���̃O���t�B�b�N���쐬
	Font::SetStrTex(L"");

	
}

//�Q�[�����C�����s�����\�b�h
void CSceneShop::Scene()
{
	//�`��J���[���
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	Font::StrDraw(L"���V���b�v", 100, 50, 120, c);
	Font::StrDraw(L"�E����𔃂�", 120, 100, 80, c);
	Font::StrDraw(L"�E�Z�[�u", 2, 130, 80, c);
	Font::StrDraw(L"�E�^�C�g���ɖ߂�", 120, 200, 80, c);
}