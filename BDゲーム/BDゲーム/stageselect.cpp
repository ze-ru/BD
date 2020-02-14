//STLデバッグ機能をOFFにする
#define _SECURE_SCL (0)
#define _HAS_ITERATOR_DEBUGGING (0)

//GameLで使用するヘッダー
#include"GameL\SceneObjManager.h"
#include"GameL\DrawTexture.h"

//使用するネームスペース
using namespace GameL;

//使用ヘッダー
#include"stageselect.h"
#include"GameHead.h"

//コンストラクタ
stageselect::stageselect()
{

}

//デストラクタ
stageselect::~stageselect()
{

}

//ゲームタイトル初期化メソッド
void stageselect::InitScene()
{
	//ステージセレクトオブジェクト作成
	CObjstageselect* t = new CObjstageselect();
	Objs::InsertObj(t, OBJ_STAGESELECT, 1);
}

//ゲームタイトル実行中メソッド
void stageselect::Scene()
{

}