//使用するヘッダーファイル
#include"GameL\DrawTexture.h"
#include"GameL\WinInputs.h"
#include"GameL\SceneManager.h"
#include"GameL\DrawFont.h"

#include"ObjTitle.h"
#include"SceneStage1.h"

//使用するネームスペース
using namespace GameL;

//イニシャライズ
void CObjTitle::Init()
{
	m_mou_x = 0.0f;
	m_mou_y = 0.0f;
	m_mou_r = false;
	m_mou_l = false;
}

//アクション
void CObjTitle::Action()
{
	//マウスの位置を取得
	m_mou_x = (float)Input::GetPosX();
	m_mou_y = (float)Input::GetPosY();
	//マウスのボタンの状態
	m_mou_r = Input::GetMouButtonR();
	m_mou_l = Input::GetMouButtonL();

	//マウスの位置とクリックする場所で当たり判定
	if (m_mou_x > 280 && m_mou_x < 500 && m_mou_y > 400 && m_mou_y < 430)
	{
		//マウスのボタンが押されたらメインに遷移
		if (m_mou_r == true || m_mou_l == true)
		{
			Scene::SetScene(new CSceneStage1());
		}
	}
}

//ドロー
void CObjTitle::Draw()
{
	float c[4] = { 1,1,1,1 };

	//仮マウスの位置表示
	wchar_t str[256];
	swprintf_s(str, L"x=%f,y=%f", m_mou_x, m_mou_y);
	Font::StrDraw(str, 20, 20,12, c);
	//仮マウスのボタン状態
	if (m_mou_r == true)
		Font::StrDraw(L"R=押してる", 20, 30, 12, c);
	else
		Font::StrDraw(L"R=押してない", 20, 30, 12, c);

	if (m_mou_l == true)
		Font::StrDraw(L"L=押してる", 20, 40, 12, c);
	else
		Font::StrDraw(L"L=押してない", 20, 40, 12, c);

	//タイトル
	Font::StrDraw(L"Lost", 320, 200, 80, c);

	//クリックする場所
	//Gameに移行クリック場所
	Font::StrDraw(L"◆ClickStart", 300, 400, 30, c);
}