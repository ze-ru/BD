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
	Draw::LoadImageW(L"ORIGIN.png",0,TEX_SIZE_512);

	//主人公オブジェクト作成
	CObjHero*obj = new CObjHero();
	Objs::InsertObj(obj, OBJ_HERO, 10);
}

//実行中メソッド
void CSceneStage1::Scene()
{

}