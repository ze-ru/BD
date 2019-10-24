//STLデバッグ機能をOFFにする
#define _SECURE_SCL (0)
#define _HAS_ITERATOR_DEBUGGING (0)

//GameLで使用するヘッダー
#include"GameL\SceneObjManager.h"
#include"GameL\DrawTexture.h"

#include"GameL\UserData.h"

//使用ネームスペース
using namespace GameL;

//使用ヘッダー
#include"SceneStage1.h"
#include"GameHead.h"

//コントラクタ
CSceneStage1::CSceneStage1()
{

}

//デストラクタ
CSceneStage1::~CSceneStage1()
{

}

//初期化メソッド
void CSceneStage1::InitScene()
{
	//外部データの読み込み
	unique_ptr<wchar_t>p;//ステージ情報ポインター
	int size;//ステージ情報の大きさ
	p = Save::ExternalDataOpen(L"stage1.csv", &size);//外部データ読み込み

	int map[10][157];
	int count = 1;
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 157; j++)
		{
			int w = 0;
			swscanf_s(&p.get()[count], L"%d", &w);

			map[i][j] = w;
			count += 2;
		}
	}

	//グラフィック読み込み
	Draw::LoadImageW(L"ORIGIN.png",1,TEX_SIZE_512);
	Draw::LoadImageW(L"Stage2..png",0, TEX_SIZE_512);
	Draw::LoadImageW(L"stage1 Back.jpg", 2, TEX_SIZE_512);

	//主人公オブジェクト作成
	CObjHero*obj = new CObjHero();
	Objs::InsertObj(obj, OBJ_HERO, 10);

	//Blockオブジェクト作成
	CObjBlock*objb = new CObjBlock(map);
	Objs::InsertObj(objb, OBJ_BLOCK, 11);

	CObjStage1*objs1 = new CObjStage1();
	Objs::InsertObj(objs1, OBJ_STAGE1, 1);

	

}

//実行中メソッド
void CSceneStage1::Scene()
{

}