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
#include "SceneGameOver.h"
#include "GameHead.h"

//コンストラクタ
CSceneGameOver::CSceneGameOver(int mapflag,int mapnum)
{
	map_flag = mapflag;
	map_num = mapnum;
}

//デストラクタ
CSceneGameOver::~CSceneGameOver()
{

}

//ゲームメイン初期化メソッド
void CSceneGameOver::InitScene()
{
	//音楽情報の読み込み
	Audio::LoadAudio(0, L"GameOver.wav", SOUND_TYPE::BACK_MUSIC);

	//バックミュージックスタート
	float Volume = Audio::VolumeMaster(-0.0f);//マスターボリュームを下げる
	Audio::Start(0);//音楽スタート

	//ゲームオーバーオブジェクト作成
	CObjGameOver* obj = new CObjGameOver(map_flag,map_num);
	Objs::InsertObj(obj, OBJ_GAME_OVER, 10);
}

//ゲームメイン実行中メソッド
void CSceneGameOver::Scene()
{

}