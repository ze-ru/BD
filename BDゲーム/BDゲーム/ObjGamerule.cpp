//使用ヘッダーファイル
#include "GameL\DrawFont.h"
#include "GameL\WinInputs.h"

#include "GameHead.h"
#include "ObjGamerule.h"

//使用するネームスペース
using namespace GameL;

//イニシャライズ
void CObjGamerule::Init()
{

}

//アクション
void CObjGamerule::Action()
{
	if (Input::GetVKey(VK_RETURN) == true)
	{
		Scene::SetScene(new CSceneStage1());
	}
}

//ドロー
void CObjGamerule::Draw()
{
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };
	Font::StrDraw(L"", 230, 250, 32, c);

	Font::StrDraw(L"GameStart:PushEnterKey", 200, 400, 32, c);
}