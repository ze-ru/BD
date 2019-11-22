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
#include"SceneStage1.h"
#include"GameHead.h"

//�R���g���N�^
CSceneStage1::CSceneStage1(int flag,int map_num)
{
	map_flag = flag;
	mapnum = map_num;
}

//�f�X�g���N�^
CSceneStage1::~CSceneStage1()
{
	
}

//���������\�b�h
void CSceneStage1::InitScene()
{
	bool flag = true;
	CObjstageselect*objss = (CObjstageselect*)Objs::GetObj(OBJ_STAGESELECT);
	
	//�O���f�[�^�̓ǂݍ���
	unique_ptr<wchar_t>p;//�X�e�[�W���|�C���^�[
	int size;//�X�e�[�W���̑傫��
	p = Save::ExternalDataOpen(L"stage1.csv", &size);//�O���f�[�^�ǂݍ���

	int map[11][157];
	int count = 1;

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
	

	unique_ptr<wchar_t>p2;//�X�e�[�W���|�C���^�[
	int size2;//�X�e�[�W���̑傫��
	p2 = Save::ExternalDataOpen(L"stage2.csv", &size2);//�O���f�[�^�ǂݍ���

	int map2[11][157];
	int count2 = 1;

	for (int i = 0; i < 11; i++)
	{
		for (int j = 0; j < 157; j++)
		{
			int w = 0;
			swscanf_s(&p2.get()[count2], L"%d", &w);


			map2[i][j] = w;

			if (w >= 10)
			{
				count2 += 3;
			}
			else
			{
				count2 += 2;
			}
		}
	}

	unique_ptr<wchar_t>p3;//�X�e�[�W���|�C���^�[
	int size3;//�X�e�[�W���̑傫��
	p3 = Save::ExternalDataOpen(L"stage3.csv", &size3);//�O���f�[�^�ǂݍ���

	int map3[11][157];
	int count3 = 1;

	for (int i = 0; i < 11; i++)
	{
		for (int j = 0; j < 157; j++)
		{
			int w = 0;
			swscanf_s(&p3.get()[count3], L"%d", &w);


			map3[i][j] = w;

			if (w >= 10)
			{
				count3 += 3;
			}
			else
			{
				count3 += 2;
			}
		}
	}
	
	//�O���t�B�b�N�ǂݍ���
	Draw::LoadImageW(L"Stage1.png", 0, TEX_SIZE_512);
	Draw::LoadImageW(L"Back.png", 10, TEX_SIZE_512);
	Draw::LoadImageW(L"Hero.png",2,TEX_SIZE_512);
	Draw::LoadImageW(L"enemy1.png", 3, TEX_SIZE_512);
	Draw::LoadImageW(L"LockEnemy.png", 4, TEX_SIZE_512);
	Draw::LoadImageW(L"face.png", 5, TEX_SIZE_512);
	Draw::LoadImageW(L"FlyEnemy.png", 6, TEX_SIZE_512);
	Draw::LoadImageW(L"Stage2.png", 7, TEX_SIZE_512);
	Draw::LoadImageW(L"Stage3.png", 9, TEX_SIZE_512);
	Draw::LoadImageW(L"Stage1Back.png", 11, TEX_SIZE_512);
	Draw::LoadImageW(L"BackGround2.png", 12, TEX_SIZE_512);
	Draw::LoadImageW(L"BackGround3.png", 13, TEX_SIZE_512);
	Draw::LoadImageW(L"Boss1.png", 14, TEX_SIZE_512);
	Draw::LoadImageW(L"Shop.png", 15, TEX_SIZE_512);
	Draw::LoadImageW(L"Boss2.png", 16, TEX_SIZE_512);
	Audio::LoadAudio(0, L"stage1.wav", SOUND_TYPE::BACK_MUSIC);
	Audio::LoadAudio(1, L"stage2.wav", SOUND_TYPE::BACK_MUSIC);


	
	CObjStage1*objs1 = new CObjStage1(map_flag);
	Objs::InsertObj(objs1, OBJ_STAGE1, 1);
	if (mapnum == 0)
	{
		CObjBlock*objb = new CObjBlock(map, mapnum);
		Objs::InsertObj(objb, OBJ_BLOCK, 2);
		CObjStage1Clear *objc = new CObjStage1Clear();
		Objs::InsertObj(objc, OBJ_STAGE1CLEAR, 2);
		//���y���̓ǂݍ���
		
		float Volume = Audio::VolumeMaster(-0.0f);//�}�X�^�[�{�����[����������
		Audio::Start(0);//���y�X�^�[�g
	}
	if (mapnum == 7)
	{
		CObjBlock*objb = new CObjBlock(map2, mapnum);
		Objs::InsertObj(objb, OBJ_BLOCK, 2);
		CObjStage1Clear *objc = new CObjStage1Clear();
		Objs::InsertObj(objc, OBJ_STAGE1CLEAR, 2);
		//���y���̓ǂݍ���
		
		float Volume = Audio::VolumeMaster(-0.0f);//�}�X�^�[�{�����[����������
		Audio::Start(0);//���y�X�^�[�g
	}
	if (mapnum == 9)
	{
		CObjBlock*objb = new CObjBlock(map3, mapnum);
		Objs::InsertObj(objb, OBJ_BLOCK, 2);
		CObjStage1Clear *objc = new CObjStage1Clear();
		Objs::InsertObj(objc, OBJ_STAGE1CLEAR, 2);
	}
	//��l���I�u�W�F�N�g�쐬
	CObjHero*obj = new CObjHero();
	Objs::InsertObj(obj, OBJ_HERO, 10);

	

	CObjStageUi*objui = new CObjStageUi();
	Objs::InsertObj(objui, OBJ_STAGEUI, 30);

	

	//�o�b�N�~���[�W�b�N�X�^�[�g
	
}

//���s�����\�b�h
void CSceneStage1::Scene()
{

}