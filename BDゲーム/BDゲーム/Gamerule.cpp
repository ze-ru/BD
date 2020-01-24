//STLデバッグ機能をOFFにする
#define _SECURE_SCL (0)
#define _HAS_ITERATOR_DEBUGGING (0)

//GameLで使用するヘッダー
#include "GameL\SceneObjManager.h"
#include "GameL\DrawFont.h"

//使用するネームスペース
using namespace GameL;

//使用ヘッダー
#include "Gamerule.h"
#include "GameHead.h"


//コンストラクタ
CSceneGamerule::CSceneGamerule()
{

}

//デストラクタ
CSceneGamerule::~CSceneGamerule()
{

}

//ゲームメイン初期化メソッド
void CSceneGamerule::InitScene()
{
	CObjGamerule2* obj2 = new CObjGamerule2();//タイトルオブジェクト作成
	Objs::InsertObj(obj2, OBJ_GAMERULE2, 10);//主人公オブジェクト登録
	//タイトルオブジェクト作成
	CObjGamerule* obj = new CObjGamerule();//タイトルオブジェクト作成
	Objs::InsertObj(obj, OBJ_GAMERULE, 10);//主人公オブジェクト登録

	
}

//ゲームメイン実行中メソッド
void CSceneGamerule::Scene()
{

}