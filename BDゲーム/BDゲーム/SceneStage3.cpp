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
#include"SceneStage3.h"
#include"GameHead.h"

//コントラクタ
CSceneStage3::CSceneStage3()
{

}

//デストラクタ
CSceneStage3::~CSceneStage3()
{

}

//初期化メソッド
void CSceneStage3::InitScene()
{
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

	int map2[11][156];
	int count2 = 1;

	for (int i = 0; i < 11; i++)
	{
		for (int j = 0; j < 156; j++)
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

	int map3[11][156];
	int count3 = 1;

	for (int i = 0; i < 11; i++)
	{
		for (int j = 0; j < 156; j++)
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
	Draw::LoadImageW(L"Hero.png", 1, TEX_SIZE_512);
	Draw::LoadImageW(L"Stage3.png", 9, TEX_SIZE_512);
	Draw::LoadImageW(L"BackGround3.png", 10, TEX_SIZE_512);
	Draw::LoadImageW(L"enemy1.png", 3, TEX_SIZE_512);

	Draw::LoadImageW(L"face.png", 5, TEX_SIZE_512);

	//主人公オブジェクト作成
	CObjHero*obj = new CObjHero();
	Objs::InsertObj(obj, OBJ_HERO, 10);

	/*//Block3オブジェクト作成
	CObjBlock3*objb3 = new CObjBlock3(map3);
	Objs::InsertObj(objb3, OBJ_BLOCK3, 5);

	CObjBlock*objb = new CObjBlock(map);
	Objs::InsertObj(objb, OBJ_BLOCK, 1);
	CObjBlock2*objb2 = new CObjBlock2(map2);
	Objs::InsertObj(objb2, OBJ_BLOCK2, 1);
	CObjBlock2*pb2 = (CObjBlock2*)Objs::GetObj(OBJ_BLOCK2);
	pb2->Setmap2(22);

	CObjBlock3*pb3 = (CObjBlock3*)Objs::GetObj(OBJ_BLOCK3);
	pb3->Setmap3(0);

	CObjBlock*pb = (CObjBlock*)Objs::GetObj(OBJ_BLOCK);
	pb->Setmap1(21);

	*/

	//Stage3オブジェクト作成
	CObjStage3*objs3 = new CObjStage3();
	Objs::InsertObj(objs3, OBJ_STAGE3, 2);



	CObjStageUi*objui = new CObjStageUi();
	Objs::InsertObj(objui, OBJ_STAGEUI, 30);

	//音楽情報の読み込み
	//Audio::LoadAudio(0, L"stage2.wav", SOUND_TYPE::BACK_MUSIC);

	//バックミュージックスタート
	//float Volume = Audio::VolumeMaster(-0.0f);//マスターボリュームを下げる
	//Audio::Start(0);//音楽スタート
}

//実行中メソッド
void CSceneStage3::Scene()
{

}