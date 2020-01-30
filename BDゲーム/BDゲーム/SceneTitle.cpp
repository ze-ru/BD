//STLデバッグ機能をOFFにする
#define _SECURE_SCL (0)
#define _HAS_ITERATOR_DEBUGGING (0)

//GameLで使用するヘッダー
#include"GameL\SceneObjManager.h"
#include"GameL\DrawTexture.h"
#include"GameL\Audio.h"


//使用するネームスペース
using namespace GameL;

//使用ヘッダー
#include"SceneTitle.h"
#include"GameHead.h"

//コンストラクタ
CSceneTitle::CSceneTitle()
{

}

//デストラクタ
CSceneTitle::~CSceneTitle()
{

}

//ゲームタイトル初期化メソッド
void CSceneTitle::InitScene()
{
	//タイトルオブジェクト作成
	CObjTitle* t = new CObjTitle();
	Objs::InsertObj(t, OBJ_TITLE, 1);

	//音楽情報の読み込み
	Audio::LoadAudio(0, L"Title.wav", SOUND_TYPE::BACK_MUSIC);

	//バックミュージックスタート
	float Volume = Audio::VolumeMaster(-0.0f);//マスターボリュームを下げる
	Audio::Start(0);//音楽スタート
}

//ゲームタイトル実行中メソッド
void CSceneTitle::Scene()
{

}