#include "GameL\DrawTexture.h"
#include "GameL\WinInputs.h"
#include "GameHead.h"
#include "ObjStage2Clear.h"
#include"GameL\SceneObjManager.h"


//使用するネームスペース
using namespace GameL;

//イニシャライズ
void CObjStage2Clear::Init()
{
	
	Sc2 = false;//キーフラグ


}

//アクション
void CObjStage2Clear::Action()
{
	if ()
	{
		Sc2 = true;
	}
}

//ドロー
void CObjStage2Clear::Draw()
{
	float c[4] = { 1,1,1,1 };


	
	if (Sc2 == true)
	{
		Font::StrDraw(L"Game Clear", 85, 70, 180, c);
	}
	
}