//STL�f�o�b�O�@�\��OFF�ɂ���
#define _SECURE_SCL (0)
#define _HAS_ITERATOR_DEBUGGING (0)

//GameL�Ŏg�p����w�b�_�[
#include"GameL\SceneObjManager.h"
#include"GameL\DrawTexture.h"

#include"GameL\UserData.h"

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
	//�O���f�[�^�̓ǂݍ���
	unique_ptr<wchar_t>p;//�X�e�[�W���|�C���^�[
	int size;//�X�e�[�W���̑傫��
	p = Save::ExternalDataOpen(L"stage1.csv", &size);//�O���f�[�^�ǂݍ���

	int map[11][157];
	int count =1;
	
	for (int i = 0; i < 11; i++)
	{
		for (int j = 0; j < 157; j++)
		{
			int w = 0;
			swscanf_s(&p.get()[count], L"%d", &w);

			
				map[i][j] = w;

				if (w >= 10)
				{
					count += 3;
				}
				else
				{
					count += 2;
				}
		}
	}

	//�O���t�B�b�N�ǂݍ���
	Draw::LoadImageW(L"ORIGIN.png",1,TEX_SIZE_512);
	Draw::LoadImageW(L"Stage2..png",0, TEX_SIZE_512);
	Draw::LoadImageW(L"Stage1Back.png", 2, TEX_SIZE_512);
	Draw::LoadImageW(L"enemy1.png", 3, TEX_SIZE_512);
	Draw::LoadImageW(L"kyaramemo.png", 4, TEX_SIZE_512);
	Draw::LoadImageW(L"face.png", 5, TEX_SIZE_512);

	//��l���I�u�W�F�N�g�쐬
	CObjHero*obj = new CObjHero();
	Objs::InsertObj(obj, OBJ_HERO, 10);

	//Block�I�u�W�F�N�g�쐬
	CObjBlock*objb = new CObjBlock(map);
	Objs::InsertObj(objb, OBJ_BLOCK, 11);

	CObjStage1*objs1 = new CObjStage1();
	Objs::InsertObj(objs1, OBJ_STAGE1, 1);

	CObjLockEnemy*obje2 = new CObjLockEnemy();
	Objs::InsertObj(obje2, OBJ_LOCKENEMY, 10);

	CObjWolkEnemy*obje1 = new CObjWolkEnemy();
	Objs::InsertObj(obje1, OBJ_WOLKENEMY, 10);

	CObjStageUi*objui = new CObjStageUi();
	Objs::InsertObj(objui, OBJ_STAGEUI, 12);
}

//���s�����\�b�h
void CSceneStage1::Scene()
{

}