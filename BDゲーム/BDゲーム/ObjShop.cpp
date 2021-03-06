#include "GameL\DrawTexture.h"
#include "GameL\WinInputs.h"
#include "GameL\SceneManager.h"
#include"GameL\SceneObjManager.h"
#include "GameHead.h"
#include"ObjShop.h"

//使用するネームスペース
using namespace GameL;

void CObjShop::Init()
{
	Key = true;
	flag = 0;
}

void CObjShop::Action()
{
	if (Input::GetVKey(VK_DOWN) == true)
	{
		if (Key == true)
		{
			flag++;
			Key = false;
		}
	}
	else if (Input::GetVKey(VK_UP) == true)
	{
		if (Key == true)
		{
			flag--;
			Key = false;

		}
	}
	else
	{
		Key = true;
	}
	if (flag >= 3)
		flag = 0;
	if (flag < 0)
		flag = 2;
	if (flag == 0)
	{
		if (Input::GetVKey(VK_RETURN) == true)
		{

		}
	}
	if (flag == 1)
	{
		if (Input::GetVKey(VK_RETURN) == true)
		{
			Scene::SetScene(new CSceneStage1(11,0,0,0));
		}
	}
	if (flag == 2)
	{
		if (Input::GetVKey(VK_RETURN) == true)
		{
			Scene::SetScene(new stageselect());
		}
	}
}

void CObjShop::Draw()
{

	//描画カラー情報
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	if (flag == 0)
	{
		Font::StrDraw(L"◇武器を買う", 15, 50, 90, c);
		Font::StrDraw(L"・ショップを出る", 15, 250, 90,c);
		Font::StrDraw(L"・タイトルに戻る", 15, 450, 90, c);
	}
	if (flag == 1)
	{
		Font::StrDraw(L"・武器を買う", 15, 50, 90, c);
		Font::StrDraw(L"◇ショップを出る", 15, 250, 90, c);
		Font::StrDraw(L"・タイトルに戻る", 15, 450, 90, c);
	}
	if (flag == 2)
	{
		Font::StrDraw(L"・武器を買う", 15, 50, 90, c);
		Font::StrDraw(L"・ショップを出る", 15, 250, 90, c);
		Font::StrDraw(L"◇タイトルに戻る", 15, 450, 90, c);
	}
}