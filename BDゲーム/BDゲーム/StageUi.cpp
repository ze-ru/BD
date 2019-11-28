//使用ヘッダーファイル
#include"GameL\DrawTexture.h"
#include"GameL\WinInputs.h"
#include"GameL\SceneManager.h"

#include"GameHead.h"
#include "StageUi.h"
#include"Hero.h"

//使用ネームスペース
using namespace GameL;

//イニシャライズ
void CObjStageUi::Init()
{
	score = 0;
}

//アクション
void CObjStageUi::Action()
{
	
}

//ドロー
void CObjStageUi::Draw()
{

	CObjBlock*pb = (CObjBlock*)Objs::GetObj(OBJ_BLOCK);
	//描画カラー情報
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };
	wchar_t str[50];



	swprintf_s(str, L"スコア：%d", score);

	Font::StrDraw(str, 650, 10, 20, c);

	
}