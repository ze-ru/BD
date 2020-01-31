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
	//音楽情報の読み込み
	Audio::LoadAudio(15, L"normal.wav", SOUND_TYPE::BACK_MUSIC);

	//スタッフロールオブジェクト作成
	CObjStage2Clear* obj = new CObjStage2Clear();
	Objs::InsertObj(obj, OBJ_STAGE2CLEAR, 10);

	float Volume = Audio::VolumeMaster(-0.0f);//マスターボリュームを下げる
	Audio::Start(15);//音楽スタート
}

//ゲームメイン実行中メソッド
void CSceneGameClear::Scene()
{

}