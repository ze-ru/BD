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
	score = 0;
	count = 0;

}

//アクション
void CObjStage2Clear::Action()
{

	CObjBoss2*b2 = (CObjBoss2*)Objs::GetObj(OBJ_BOSS2);
	if (b2->GetDead()==true)
	{
		Sc2 = true;
	}
}

//ドロー
void CObjStage2Clear::Draw()
{
	float c[4] = { 1,1,1,1 };
	wchar_t str[128];

	
	if (Sc2 == true)
	{
		if (time > 80)
		{
			Font::StrDraw(L"STAGE CLEAR", 85, 70, 180, c);
		}
		if (time > 120)
		{
			count++;
			time = 0;
		}
		if (count > 10)
		{
			time = 60;

			//スコア表示
			swprintf_s(str, L"SCORE:%d", score);
			Font::StrDraw(str, 85, 120, 180, c);
		}
	}
	else
		time = 0;
	
}