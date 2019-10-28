//STLデバッグ機能をOFFにする
#define _SECURE_SCL (0)
#define _HAS_ITERATOR_DEBUGGING (0)

//GameLで使用するヘッダー
#include "GameL\SceneObjManager.h"
#include "GameL\DrawFont.h"
#include "GameL\Audio.h"

//使用するネームスペース
using namespace GameL;

//使用ヘッダー
#include "GameHead.h"

//コンストラクタ
CSceneShop::CSceneShop()
{

}

//デストラクタ
CSceneShop::~CSceneShop()
{

}

//ゲームメイン初期化メソッド
void CSceneShop::InitScene()
{
	/*//音楽情報の読み込み
	Audio::LoadAudio(0, L"shop.wav", SOUND_TYPE::BACK_MUSIC);

	//バックミュージックスタート
	float Volume = Audio::VolumeMaster(-0.0f);//マスターボリュームを下げる
	Audio::Start(0);//音楽スタート*/

	//出力させる文字のグラフィックを作成
	Font::SetStrTex(L"");

	
}

//ゲームメイン実行中メソッド
void CSceneShop::Scene()
{
	//描画カラー情報
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	Font::StrDraw(L"◇ショップ", 100, 50, 120, c);
	Font::StrDraw(L"・武器を買う", 120, 100, 80, c);
	Font::StrDraw(L"・セーブ", 2, 130, 80, c);
	Font::StrDraw(L"・タイトルに戻る", 120, 200, 80, c);
}