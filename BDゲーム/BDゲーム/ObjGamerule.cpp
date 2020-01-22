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
	m_time = 0;
	m_frame = 0;
}

//アクション
void CObjGamerule::Action()
{
	if (m_frame == 0)
	{
		m_time++;
	}
	
	if (m_time > 10)
	{
		m_time = 0;
		m_frame = 1;
	}
	
	if (Input::GetVKey(VK_RETURN) == true&&m_frame==1)
	{
		Scene::SetScene(new CSceneStage1(11,0,0,0));
	}
}

//ドロー
void CObjGamerule::Draw()
{
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };
	Font::StrDraw(L"操作説明", 270, 30, 60, c);

	Font::StrDraw(L"・↑キー", 40, 220, 30, c);
	Font::StrDraw(L"「アイテムを拾う」", 40, 260, 30, c);

	Font::StrDraw(L"・←キー", 40, 120, 30, c);
	Font::StrDraw(L"「左に移動」", 40, 160, 30, c);

	Font::StrDraw(L"・→キー", 500, 120, 30, c);
	Font::StrDraw(L"「右に移動」", 500, 160, 30, c);

	Font::StrDraw(L"・スペースキー", 500, 220, 30, c);
	Font::StrDraw(L"「ジャンプ」", 500, 260, 30, c);

	Font::StrDraw(L"・Xキー", 40, 320, 30, c);
	Font::StrDraw(L"「剣で攻撃」(敵の攻撃を防ぐ)", 40, 360, 30, c);

	Font::StrDraw(L"「スイッチの起動」", 40, 400, 30, c);

	Font::StrDraw(L"・Cキー", 500, 320, 30, c);
	Font::StrDraw(L"「所得武器使用」", 500, 360, 30, c);

	Font::StrDraw(L"START:Push[EnterKey]", 115, 500, 60, c);
}