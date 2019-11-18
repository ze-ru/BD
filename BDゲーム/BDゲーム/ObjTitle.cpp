//使用するヘッダーファイル

#include"GameL\WinInputs.h"
#include"GameL\SceneManager.h"
#include"GameL\DrawFont.h"

#include"ObjTitle.h"
#include"GameL\UserData.h"

#include"GameHead.h"

//使用するネームスペース
using namespace GameL;

//イニシャライズ
void CObjTitle::Init()
{
	m_mou_x = 0.0f;
	m_mou_y = 0.0f;
	m_mou_r = false;
	m_mou_l = false;
	m_key_flag = false;//キーフラグ
	key = true;

	
}

//アクション
void CObjTitle::Action()
{
	if (Input::GetVKey(VK_UP) == true)
	{
		key = true;
	}
	if (Input::GetVKey(VK_DOWN) == true)
	{
		key = false;
	}

	if (Input::GetVKey(VK_RETURN) == true && key == false)
	{
		
		if (m_key_flag == true)
		{
			Scene::SetScene(new CSceneStage1());
			m_key_flag == false;
		}
	}
	if (Input::GetVKey(VK_RETURN) == true && key == true)
	{
		if (m_key_flag == true)
		{
	
			m_key_flag == false;
		}
	}
	else
	{
		m_key_flag = true;
	}
}

//ドロー
void CObjTitle::Draw()
{
	float c[4] = { 1,1,1,1 };


	Font::StrDraw(L"L O S T", 85, 70, 180, c);
	if (key == true)
	{
		Font::StrDraw(L"▶はじめから", 125, 320, 80, c);
		Font::StrDraw(L" つづきから", 160, 450, 80, c);
	}
	if (key == false)
	{
		Font::StrDraw(L" はじめから", 165, 320, 80, c);
		Font::StrDraw(L"▶つづきから", 120, 450, 80, c);
	}
}