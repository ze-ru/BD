//STLデバッグ機能をOFFにする
#define _SECURE_SCL (0)
#define _HAS_ITERATOR_DEBUGGING (0)

//GameLで使用するヘッダー
#include"GameL\SceneObjManager.h"
#include"GameL\DrawTexture.h"

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
	//グラフィック読み込み
	Draw::LoadImageW(L"ORIGIN.png",1,TEX_SIZE_512);
	Draw::LoadImageW(L"Stage2..png",0, TEX_SIZE_512);
	Draw::LoadImageW(L"stage1 Back.jpg", 2, TEX_SIZE_512);
	Draw::LoadImageW(L"enemy1.png", 3, TEX_SIZE_512);
	Draw::LoadImageW(L"kyaramemo.png", 4, TEX_SIZE_512);

	//主人公オブジェクト作成
	CObjHero*obj = new CObjHero();
	Objs::InsertObj(obj, OBJ_HERO, 10);

	CObjBlock*objb = new CObjBlock();
	Objs::InsertObj(objb, OBJ_BLOCK, 11);

	CObjStage1*objs1 = new CObjStage1();
	Objs::InsertObj(objs1, OBJ_STAGE1, 1);

	CObjLockEnemy*obje2 = new CObjLockEnemy();
	Objs::InsertObj(obje2, OBJ_LOCKENEMY, 10);
}

//実行中メソッド
void CSceneStage1::Scene()
{

}