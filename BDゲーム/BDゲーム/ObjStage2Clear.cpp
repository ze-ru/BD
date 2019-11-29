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
	

}

//アクション
void CObjStage2Clear::Action()
{
	if (Input::GetVKey(VK_RETURN) == true)
	{
		Scene::SetScene(new CSceneTitle());
	}
}

//ドロー
void CObjStage2Clear::Draw()
{
	float c[4] = { 1,1,1,1 };
	
	Font::StrDraw(L"Congratulation!!", 180, 130, 50, c);

	Font::StrDraw(L"GAME CLEAR!!", 230, 230, 50, c);

	Font::StrDraw(L"Thank you for playing!!", 120, 330, 50, c);

	Font::StrDraw(L"Team BD.", 330,500, 30, c);

}