//使用するヘッダーファイル
#include"GameL\WinInputs.h"
#include"GameL\SceneManager.h"
#include"GameL\DrawFont.h"

#include"ObjStage1Clear.h"
#include"GameL\UserData.h"

#include"GameHead.h"

//使用するネームスペース
using namespace GameL;

//イニシャライズ
void CObjStage1Clear::Init()
{
	key = true;
	score = 0;
	count = 0;
}

//アクション
void CObjStage1Clear::Action()
{	
	time++;

	//Boss1が死んだらSTAGE CLEAR
	CObjBoss1*b1 = (CObjBoss1*)Objs::GetObj(OBJ_BOSS1);
	if (b1->GetDead() == true)
	{

	}
}

//ドロー
void CObjStage1Clear::Draw()
{
	float c[4] = { 1,1,1,1 };
	wchar_t str[128];

	//ステージ１ゲームクリア
	if (key == true)
	{
		//"STAGE CLEAR"表示
		if (time > 60)
		{
			Font::StrDraw(L"STAGE CLEAR", 85, 70, 180, c);
		}
		//"STAGE CLEAR"を点滅させる
		if (time > 120)
		{
			count++;
			time = 0;
		}
		//スコア表示
		if (count > 10)
		{
			time = 60;
			
			swprintf_s(str, L"SCORE:%d", score);
			Font::StrDraw(str, 85, 120, 180, c);
		}
	}
	else
		time = 0;
}