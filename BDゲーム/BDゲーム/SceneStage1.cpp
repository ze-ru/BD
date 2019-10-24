//STL�f�o�b�O�@�\��OFF�ɂ���
#define _SECURE_SCL (0)
#define _HAS_ITERATOR_DEBUGGING (0)

//GameL�Ŏg�p����w�b�_�[
#include"GameL\SceneObjManager.h"
#include"GameL\DrawTexture.h"

//�g�p�l�[���X�y�[�X
using namespace GameL;

//�g�p�w�b�_�[
#include"SceneStage1.h"
#include"GameHead.h"

//�R���g���N�^
CSceneStage1::CSceneStage1()
{

}

//�f�X�g���N�^
CSceneStage1::~CSceneStage1()
{

}

//���������\�b�h
void CSceneStage1::InitScene()
{
	//�O���t�B�b�N�ǂݍ���
	Draw::LoadImageW(L"ORIGIN.png",1,TEX_SIZE_512);
	Draw::LoadImageW(L"Stage2..png",0, TEX_SIZE_512);
	Draw::LoadImageW(L"stage1 Back.jpg", 2, TEX_SIZE_512);
	Draw::LoadImageW(L"enemy1.png", 3, TEX_SIZE_512);
	Draw::LoadImageW(L"kyaramemo.png", 4, TEX_SIZE_512);

	//��l���I�u�W�F�N�g�쐬
	CObjHero*obj = new CObjHero();
	Objs::InsertObj(obj, OBJ_HERO, 10);

	CObjBlock*objb = new CObjBlock();
	Objs::InsertObj(objb, OBJ_BLOCK, 11);

	CObjStage1*objs1 = new CObjStage1();
	Objs::InsertObj(objs1, OBJ_STAGE1, 1);

	CObjLockEnemy*obje2 = new CObjLockEnemy();
	Objs::InsertObj(obje2, OBJ_LOCKENEMY, 10);
}

//���s�����\�b�h
void CSceneStage1::Scene()
{

}