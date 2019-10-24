//使用するヘッダーファイル
#include "GameL\DrawFont.h"
#include "GameL\WinInputs.h"
#include "GameL\SceneManager.h"

#include "GameHead.h"
#include "ObjGameOver.h"

//使用するネームスペース
using namespace GameL;

//イニシャライズ
void CObjGameOver::Init()
{
	m_key_flag = false;//キーフラグ
	key = false;
}

//アクション
void CObjGameOver::Action()
{
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
			Scene::SetScene(new CSceneTitle());
			m_key_flag = false;
		}
	}
	if (Input::GetVKey(VK_RETURN) == true && key == true)
	{
		if (m_key_flag == true)
		{
			Scene::SetScene(new CSceneStage1());
			m_key_flag = false;
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
	Font::StrDraw(L"GAME OVER", 120, 200, 120, c);

	if (key == false) 
	{
		Font::StrDraw(L"▶タイトルに戻る", 170, 380, 60, c);
		Font::StrDraw(L" つづきから", 200, 480, 60, c);
	}
	if (key == true)
	{
		Font::StrDraw(L" タイトルに戻る", 200, 380, 60, c);
		Font::StrDraw(L"▶つづきから", 170, 480, 60, c);
	}
	
}