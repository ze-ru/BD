//STL�f�o�b�O�@�\��OFF�ɂ���
#define _SECURE_SCL (0)
#define _HAS_ITERATOR_DEBUGGING (0)

//GameL�Ŏg�p����w�b�_�[
#include"GameL\SceneObjManager.h"
#include"GameL\DrawTexture.h"
#include"GameL\Audio.h"

#include"GameL\UserData.h"

//�g�p�l�[���X�y�[�X
using namespace GameL;

//�g�p�w�b�_�[
#include"SceneStage2.h"
#include"GameHead.h"

//�R���g���N�^
CSceneStage2::CSceneStage2()
{

}

//�f�X�g���N�^
CSceneStage2::~CSceneStage2()
{

}

//���������\�b�h
void CSceneStage2::InitScene()
{


	
	//�O���f�[�^�̓ǂݍ���
	unique_ptr<wchar_t>p;//�X�e�[�W���|�C���^�[
	int size2;//�X�e�[�W���̑傫��
	p = Save::ExternalDataOpen(L"stage2.csv", &size2);//�O���f�[�^�ǂݍ���

	int map2[11][156];
	int count = 1;

	for (int i = 0; i < 11; i++)
	{
		for (int j = 0; j < 156; j++)
		{
			int w = 0;
			swscanf_s(&p.get()[count], L"%d", &w);


			map2[i][j] = w;

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
	Draw::LoadImageW(L"Hero.png", 1, TEX_SIZE_512);
	Draw::LoadImageW(L"Stage2.png", 6, TEX_SIZE_512);
	Draw::LoadImageW(L"BackGround2.png", 7, TEX_SIZE_512);
	Draw::LoadImageW(L"enemy1.png", 3, TEX_SIZE_512);
	Draw::LoadImageW(L"LockEnemy.png", 4, TEX_SIZE_512);
	Draw::LoadImageW(L"face.png", 5, TEX_SIZE_512);
	Draw::LoadImageW(L"FlyEnemy.png", 8, TEX_SIZE_512);
	Draw::LoadImageW(L"WolkEnemy.png", 9, TEX_SIZE_512);

	

	//Block2�I�u�W�F�N�g�쐬
	CObjBlock2*objb2 = new CObjBlock2(map2);
	Objs::InsertObj(objb2, OBJ_BLOCK2, 3);

	//Stage2�I�u�W�F�N�g�쐬
	CObjStage2*objs2 = new CObjStage2();
	Objs::InsertObj(objs2, OBJ_STAGE2, 1);
	
	//��l���I�u�W�F�N�g�쐬
	CObjHero2*obj2 = new CObjHero2();
	Objs::InsertObj(obj2, OBJ_HERO2, 10);

	CObjStageUi*objui = new CObjStageUi();
	Objs::InsertObj(objui, OBJ_STAGEUI, 30);

	//���y���̓ǂݍ���
	Audio::LoadAudio(0, L"stage2.wav", SOUND_TYPE::BACK_MUSIC);

	//�o�b�N�~���[�W�b�N�X�^�[�g
	float Volume = Audio::VolumeMaster(-0.0f);//�}�X�^�[�{�����[����������
	Audio::Start(0);//���y�X�^�[�g
}

//���s�����\�b�h
void CSceneStage2::Scene()
{

}