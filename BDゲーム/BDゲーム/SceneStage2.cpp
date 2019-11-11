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
#include"SceneStage2.h"
#include"GameHead.h"

//コントラクタ
CSceneStage2::CSceneStage2()
{

}

//デストラクタ
CSceneStage2::~CSceneStage2()
{

}

//初期化メソッド
void CSceneStage2::InitScene()
{


	
	//外部データの読み込み
	unique_ptr<wchar_t>p;//ステージ情報ポインター
	int size2;//ステージ情報の大きさ
	p = Save::ExternalDataOpen(L"stage2.csv", &size2);//外部データ読み込み

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

	//グラフィック読み込み
	Draw::LoadImageW(L"Hero.png", 1, TEX_SIZE_512);
	Draw::LoadImageW(L"Stage2.png", 6, TEX_SIZE_512);
	Draw::LoadImageW(L"BackGround2.png", 7, TEX_SIZE_512);
	Draw::LoadImageW(L"enemy1.png", 3, TEX_SIZE_512);
	Draw::LoadImageW(L"LockEnemy.png", 4, TEX_SIZE_512);
	Draw::LoadImageW(L"face.png", 5, TEX_SIZE_512);
	Draw::LoadImageW(L"FlyEnemy.png", 8, TEX_SIZE_512);
	Draw::LoadImageW(L"WolkEnemy.png", 9, TEX_SIZE_512);

	

	//Block2オブジェクト作成
	CObjBlock2*objb2 = new CObjBlock2(map2);
	Objs::InsertObj(objb2, OBJ_BLOCK2, 3);

	//Stage2オブジェクト作成
	CObjStage2*objs2 = new CObjStage2();
	Objs::InsertObj(objs2, OBJ_STAGE2, 1);
	
	//主人公オブジェクト作成
	CObjHero2*obj2 = new CObjHero2();
	Objs::InsertObj(obj2, OBJ_HERO2, 10);

	CObjStageUi*objui = new CObjStageUi();
	Objs::InsertObj(objui, OBJ_STAGEUI, 30);

	//音楽情報の読み込み
	Audio::LoadAudio(0, L"stage2.wav", SOUND_TYPE::BACK_MUSIC);

	//バックミュージックスタート
	float Volume = Audio::VolumeMaster(-0.0f);//マスターボリュームを下げる
	Audio::Start(0);//音楽スタート
}

//実行中メソッド
void CSceneStage2::Scene()
{

}