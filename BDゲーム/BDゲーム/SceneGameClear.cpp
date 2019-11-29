//STLデバック機能をOFFにする
#define _SECURE_SCL (0)
#define _HAS_ITERATOR_DEBUGGING (0)

//GameLで使用するヘッダー
#include "GameL\SceneObjManager.h"
#include "GameL\DrawFont.h"
#include "GameL\Audio.h"


//使用するネームスペース
using namespace GameL;

//使用ヘッダー
#include "SceneGameClear.h"
#include "GameHead.h"

//コンストラクタ
CSceneGameClear::CSceneGameClear()
{

}

//デストラクタ
CSceneGameClear::~CSceneGameClear()
{

}

//ゲームメイン初期化メソッド
void CSceneGameClear::InitScene()
{

	//ゲームオーバーオブジェクト作成
	CObjStage2Clear* obj = new CObjStage2Clear();
	Objs::InsertObj(obj, OBJ_STAGE2CLEAR, 10);
}

//ゲームメイン実行中メソッド
void CSceneGameClear::Scene()
{

}