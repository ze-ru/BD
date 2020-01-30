//使用するヘッダーファイル
#include "GameL\DrawFont.h"
#include "GameL\WinInputs.h"
#include "GameL\SceneManager.h"

#include "GameHead.h"
#include "ObjGameOver.h"

//使用するネームスペース
using namespace GameL;
CObjGameOver::CObjGameOver(int x, int y)
{
	mapflag = x;//背景番号
	mapnum = y; //ブロック描画番号
}

//イニシャライズ
void CObjGameOver::Init()
{
	m_key_flag = false;//キーフラグ
	key = false;       //キー判定
}

//アクション
void CObjGameOver::Action()
{
	//上下キーの判定
	if (Input::GetVKey(VK_UP) == true)
	{
		key = false;
	}
	if (Input::GetVKey(VK_DOWN) == true)
	{
		key = true;
	}


	//エンターキーを押してシーン：ゲームTitleに移行する
	if (Input::GetVKey(VK_RETURN) == true&&key==false)
	{
		if (m_key_flag == true)
		{
			if (mapflag != 13)//マップ1に移行
				Scene::SetScene(new CSceneStage1(mapflag, mapnum, 0, 0));
			if (mapflag == 13)//マップ2に移行
				Scene::SetScene(new CSceneStage1(mapflag, mapnum, 0, 0));

			m_key_flag = false;//初期化
		}
	}
	if (Input::GetVKey(VK_RETURN) == true && key == true)
	{
		if (m_key_flag == true)
		{
			Scene::SetScene(new CSceneTitle());//タイトルに移行
			m_key_flag = false;                //初期化
		}
	}
	else
	{
		m_key_flag = true;
	}



}
//ドロー
void CObjGameOver::Draw()
{
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	Font::StrDraw(L"YOU LOST", 240, 70, 80, c);
	Font::StrDraw(L"GAME OVER", 125, 200, 120, c);

	//上下キーで選択
	if (key == false) 
	{
		Font::StrDraw(L"▶つづきから", 155, 380, 60, c);
		Font::StrDraw(L" タイトルに戻る", 185, 480, 60, c);
	}
	if (key == true)
	{
		Font::StrDraw(L" つづきから", 185, 380, 60, c);
		Font::StrDraw(L"▶タイトルに戻る", 155, 480, 60, c);
	}
	
}