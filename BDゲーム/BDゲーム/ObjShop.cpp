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
	Key = false;
	flag = 0;
}

void CObjShop::Action()
{
	if (Key == true && flag < 3 && flag >= 0)
	{
		Key = false;
		if (Input::GetVKey(VK_DOWN) == true)
		{
			flag++;
		}
	}
	if (flag >= 3)
		flag = 0;
	if (flag < 0)
		flag = 2;
}

void CObjShop::Draw()
{

	//描画カラー情報
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	if (flag == 0)
	{
		Font::StrDraw(L"◇ショップ", 120, 50, 120, c);
		Font::StrDraw(L"・武器を買う", 120, 100, 80, c);
		Font::StrDraw(L"・タイトルに戻る", 120, 200, 80, c);
	}
	if (flag == 1)
	{
		Font::StrDraw(L"・ショップ", 120, 50, 120, c);
		Font::StrDraw(L"◇武器を買う", 120, 100, 80, c);
		Font::StrDraw(L"・タイトルに戻る", 120, 200, 80, c);
	}
	if (flag == 2)
	{
		Font::StrDraw(L"・ショップ", 120, 50, 120, c);
		Font::StrDraw(L"・武器を買う", 120, 100, 80, c);
		Font::StrDraw(L"◇タイトルに戻る", 120, 200, 80, c);
	}
}