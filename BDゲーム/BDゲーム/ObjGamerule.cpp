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
		Scene::SetScene(new CSceneStage1(11,0));
	}
}

//ドロー
void CObjGamerule::Draw()
{
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };
	Font::StrDraw(L"操作説明", 270, 30, 60, c);

	Font::StrDraw(L"・↑キー", 70, 220, 30, c);
	Font::StrDraw(L"「ショップの扉を開ける」", 70, 250, 30, c);
	Font::StrDraw(L"「アイテムを拾う」", 70, 280, 30, c);

	Font::StrDraw(L"・←キー", 70, 120, 30, c);
	Font::StrDraw(L"「左に移動」", 70, 150, 30, c);

	Font::StrDraw(L"・→キー", 500, 120, 30, c);
	Font::StrDraw(L"「右に移動」", 500, 150, 30, c);

	Font::StrDraw(L"・スペースキー", 500, 220, 30, c);
	Font::StrDraw(L"「ジャンプ」", 500, 250, 30, c);

	Font::StrDraw(L"・Xキー", 70, 360, 30, c);
	Font::StrDraw(L"「剣攻撃」", 70, 390, 30, c);

	Font::StrDraw(L"・Cキー", 500, 360, 30, c);
	Font::StrDraw(L"「所得武器使用」", 500, 390, 30, c);

	Font::StrDraw(L"START:Push[EnterKey]", 115, 500, 60, c);
}