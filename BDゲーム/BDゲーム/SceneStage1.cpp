//STLデバッグ機能をOFFにする
#define _SECURE_SCL (0)
#define _HAS_ITERATOR_DEBUGGING (0)

//GameLで使用するヘッダー
#include"GameL\SceneObjManager.h"
#include"GameL\DrawTexture.h"
#include"GameL\Audio.h"

#include"GameL\UserData.h"

//使用ネームスペース
using namespace GameL;

//使用ヘッダー
#include"SceneStage1.h"
#include"GameHead.h"

//コントラクタ
CSceneStage1::CSceneStage1(int flag,int map_num)
{
	map_flag = flag;
	mapnum = map_num;
}

//デストラクタ
CSceneStage1::~CSceneStage1()
{
	
}

//初期化メソッド
void CSceneStage1::InitScene()
{
	bool flag = true;
	CObjstageselect*objss = (CObjstageselect*)Objs::GetObj(OBJ_STAGESELECT);
	
	//外部データの読み込み
	unique_ptr<wchar_t>p;//ステージ情報ポインター
	int size;//ステージ情報の大きさ
	p = Save::ExternalDataOpen(L"stage1.csv", &size);//外部データ読み込み

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
	

	unique_ptr<wchar_t>p2;//ステージ情報ポインター
	int size2;//ステージ情報の大きさ
	p2 = Save::ExternalDataOpen(L"stage2.csv", &size2);//外部データ読み込み

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

	unique_ptr<wchar_t>p3;//ステージ情報ポインター
	int size3;//ステージ情報の大きさ
	p3 = Save::ExternalDataOpen(L"stage3.csv", &size3);//外部データ読み込み

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
	
	//グラフィック読み込み
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
		//音楽情報の読み込み
		
		float Volume = Audio::VolumeMaster(-0.0f);//マスターボリュームを下げる
		Audio::Start(0);//音楽スタート
	}
	if (mapnum == 7)
	{
		CObjBlock*objb = new CObjBlock(map2, mapnum);
		Objs::InsertObj(objb, OBJ_BLOCK, 2);
		CObjStage1Clear *objc = new CObjStage1Clear();
		Objs::InsertObj(objc, OBJ_STAGE1CLEAR, 2);
		//音楽情報の読み込み
		
		float Volume = Audio::VolumeMaster(-0.0f);//マスターボリュームを下げる
		Audio::Start(0);//音楽スタート
	}
	if (mapnum == 9)
	{
		CObjBlock*objb = new CObjBlock(map3, mapnum);
		Objs::InsertObj(objb, OBJ_BLOCK, 2);
		CObjStage1Clear *objc = new CObjStage1Clear();
		Objs::InsertObj(objc, OBJ_STAGE1CLEAR, 2);
	}
	//主人公オブジェクト作成
	CObjHero*obj = new CObjHero();
	Objs::InsertObj(obj, OBJ_HERO, 10);

	

	CObjStageUi*objui = new CObjStageUi();
	Objs::InsertObj(objui, OBJ_STAGEUI, 30);

	

	//バックミュージックスタート
	
}

//実行中メソッド
void CSceneStage1::Scene()
{

}