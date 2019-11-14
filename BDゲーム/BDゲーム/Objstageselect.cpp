#include"GameL\WinInputs.h"
#include"GameL\SceneManager.h"
#include"GameL\DrawFont.h"

#include"Objstageselect.h"
#include"GameL\UserData.h"

#include"GameHead.h"

//使用するネームスペース
using namespace GameL;

//イニシャライズ
void CObjstageselect::Init()
{
	m_mou_x = 0.0f;
	m_mou_y = 0.0f;
	m_mou_r = false;
	m_mou_l = false;
	m_key_flag = false;//キーフラグ
	key = true;


}

//アクション
void CObjstageselect::Action()
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

		if (m_key_flag == 0)
		{
			Scene::SetScene(new CSceneStage1());
			m_key_flag ==0;
		}
	}
	if (Input::GetVKey(VK_RETURN) == true && key == true)
	{
		if (m_key_flag == 1)
		{
			Scene::SetScene(new CSceneStage2());
			m_key_flag == 1;
		}
	}
	if (Input::GetVKey(VK_RETURN) == true && key == true)
	{
		if (m_key_flag == 2)
		{
			//Scene::SetScene(new CSceneStage3());
			m_key_flag = 2;
		}
	}
	else
	{
		m_key_flag = true;
	}
}

//ドロー
void CObjstageselect::Draw()
{
	float c[4] = { 1,1,1,1 };


	Font::StrDraw(L"L O S T", 85, 70, 180, c);
	if (key == 1)
	{
		Font::StrDraw(L"▶はじめから", 125, 320, 80, c);
		Font::StrDraw(L" つづきから", 160, 450, 80, c);
		Font::StrDraw(L" つづきから2", 160, 520, 50, c);
	}
	if (key == 2)
	{
		Font::StrDraw(L" はじめから", 165, 320, 80, c);
		Font::StrDraw(L"▶つづきから", 120, 450, 80, c);
		Font::StrDraw(L" つづきから2", 160, 520, 50, c);
	}
	else
	{
		Font::StrDraw(L" はじめから", 165, 320, 80, c);
		Font::StrDraw(L"つづきから", 160, 450, 80, c);
		Font::StrDraw(L"▶つづきから2", 120, 520, 50, c);
	}
}