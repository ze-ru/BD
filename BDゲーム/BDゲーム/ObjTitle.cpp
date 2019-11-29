﻿//使用するヘッダーファイル

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
	time = 0;
}

//アクション
void CObjTitle::Action()
{
	time++;
	if (time >= 10)
	{
		if (Input::GetVKey(VK_RETURN) == true && Input::GetVKey(' ') == false)
		{

			Scene::SetScene(new CSceneGamerule());
		}
		if (Input::GetVKey(VK_RETURN) == true && Input::GetVKey(' ') == true)
		{
			Scene::SetScene(new CSceneStage1(12, 8));
		}
		time = 10;
	}
}

//ドロー
void CObjTitle::Draw()
{
	float c[4] = { 1,1,1,1 };


	Font::StrDraw(L"L O S T", 85, 70, 180, c);
	
		Font::StrDraw(L"START:EnterKey", 110, 400, 80, c);
}