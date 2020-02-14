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

//�R���X�g���N�^
CSceneStage1::CSceneStage1(int flag,int map_num,int hwp,int hbullet)
{
	map_flag = flag;
	mapnum = map_num;
	wp = hwp;
	bullet = hbullet;
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

	int map[11][300];
	int count = 1;

	for (int i = 0; i < 11; i++)
	{
		for (int j = 0; j < 300; j++)
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

	int map2[11][300];
	int count2 = 1;

	for (int i = 0; i < 11; i++)
	{
		for (int j = 0; j < 300; j++)
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

	//�O���t�B�b�N�ǂݍ���
	Draw::LoadImageW(L"Stage1.png", 0, TEX_SIZE_512);
	Draw::LoadImageW(L"Hero.png",2,TEX_SIZE_512);
	Draw::LoadImageW(L"enemy1.png", 3, TEX_SIZE_512);
	Draw::LoadImageW(L"LockEnemy.png", 4, TEX_SIZE_512);
	Draw::LoadImageW(L"face.png", 5, TEX_SIZE_512);
	Draw::LoadImageW(L"FlyEnemy.png", 6, TEX_SIZE_512);
	Draw::LoadImageW(L"Stage2.png", 8, TEX_SIZE_512);
	Draw::LoadImageW(L"Back.png", 10, TEX_SIZE_512);

	Draw::LoadImageW(L"Stage1Back.png", 11, TEX_SIZE_512);
	Draw::LoadImageW(L"BackGround2.png", 12, TEX_SIZE_512);
	Draw::LoadImageW(L"BackGround3.png", 13, TEX_SIZE_512);
	Draw::LoadImageW(L"Boss1.png", 14, TEX_SIZE_512);
	Draw::LoadImageW(L"Shop.png", 15, TEX_SIZE_512);
	Draw::LoadImageW(L"Boss2.png", 16, TEX_SIZE_512);
	Draw::LoadImageW(L"StageClear.png", 17, TEX_SIZE_512);
	Draw::LoadImageW(L"Number.png", 18, TEX_SIZE_512);
	Draw::LoadImageW(L"Weapon.png", 19, TEX_SIZE_512);
	Draw::LoadImageW(L"LastBoss.png", 20, TEX_SIZE_512);

	Draw::LoadImageW(L"HealBlock.png", 21, TEX_SIZE_512);
	Draw::LoadImageW(L"Sield.png", 22, TEX_SIZE_512);
	Draw::LoadImageW(L"DefeatEfect.png", 23, TEX_SIZE_512);
	Draw::LoadImageW(L"GOAL3.png", 24, TEX_SIZE_512);
	Draw::LoadImageW(L"SelectBack.png", 25, TEX_SIZE_512);
	Draw::LoadImageW(L"Select.png", 26, TEX_SIZE_512);

	Draw::LoadImageW(L"Stage3.png", 30, TEX_SIZE_512);


	Audio::LoadAudio(0, L"stage1.wav", SOUND_TYPE::BACK_MUSIC);
	Audio::LoadAudio(1, L"stage2.wav", SOUND_TYPE::BACK_MUSIC);
	Audio::LoadAudio(2, L"nstage2.wav", SOUND_TYPE::BACK_MUSIC);
	Audio::LoadAudio(3, L"GameOver.wav", SOUND_TYPE::BACK_MUSIC);
	Audio::LoadAudio(4, L"lastboss.wav", SOUND_TYPE::BACK_MUSIC);
	Audio::LoadAudio(5, L"stage3.wav", SOUND_TYPE::BACK_MUSIC);
	Audio::LoadAudio(6, L"�u���b�N�j��.wav", SOUND_TYPE::BACK_MUSIC);
	Audio::LoadAudio(7, L"���C�t��.wav", SOUND_TYPE::BACK_MUSIC);
	Audio::LoadAudio(8, L"���[�U�[.wav", SOUND_TYPE::BACK_MUSIC);
	Audio::LoadAudio(9, L"�a��.wav", SOUND_TYPE::BACK_MUSIC);
	Audio::LoadAudio(10, L"��.wav", SOUND_TYPE::BACK_MUSIC);
	Audio::LoadAudio(11, L"�G���S.wav", SOUND_TYPE::BACK_MUSIC);
	Audio::LoadAudio(12, L"�G��_��.wav", SOUND_TYPE::BACK_MUSIC);
	Audio::LoadAudio(13, L"��_��.wav", SOUND_TYPE::BACK_MUSIC);
	
	
	//�X�e�[�W1�I�u�W�F�N�g�쐬
	CObjStage1*objs1 = new CObjStage1(map_flag,mapnum);
	Objs::InsertObj(objs1, OBJ_STAGE1, 1);

	if (mapnum == 0)
	{
		CObjBlock*objb = new CObjBlock(map, mapnum);
		Objs::InsertObj(objb, OBJ_BLOCK, 10);
		CObjStage1Clear *objc = new CObjStage1Clear();
		Objs::InsertObj(objc, OBJ_STAGE1CLEAR, 50);
		//���y���̓ǂݍ���	
	}
	if (mapnum == 8)
	{
		CObjBlock*objb = new CObjBlock(map2, mapnum);
		Objs::InsertObj(objb, OBJ_BLOCK, 10);
		CObjStage1Clear *objc = new CObjStage1Clear();
		Objs::InsertObj(objc, OBJ_STAGE1CLEAR, 50);
		//���y���̓ǂݍ���	
	}

	//��l���I�u�W�F�N�g�쐬
	CObjHero*obj = new CObjHero(wp,bullet);
	Objs::InsertObj(obj, OBJ_HERO, 50);

	//�X�e�[�WUI�I�u�W�F�N�g�쐬
	CObjStageUi*objui = new CObjStageUi();
	Objs::InsertObj(objui, OBJ_STAGEUI, 50);

	//
	CObjSelectBack*objsbc = new CObjSelectBack();
	Objs::InsertObj(objsbc, OBJ_SELECTBACK, 80);

	//�o�b�N�~���[�W�b�N�X�^�[�g	
}

//���s�����\�b�h
void CSceneStage1::Scene()
{

}