//使用ヘッダーファイル
#include "GameL\DrawFont.h"
#include "GameL\WinInputs.h"

#include "GameHead.h"
#include "ObjGamerule.h"
#include "GameL\HitBoxManager.h"

//使用するネームスペース
using namespace GameL;

//イニシャライズ
void CObjGamerule::Init()
{
	m_time = 0;  //画面切り替えの時間管理
	m_frame = 0; //画面切り替えのフラグ
	Hits::SetHitBox(this, 0, 0, 64, 64, ELEMENT_ENEMY, OBJ_WOLKENEMY, 1);//仮の当たり判定
}

//アクション
void CObjGamerule::Action()
{
	//m_frameを1にする間隔
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
		CObjGamerule2 *objg = (CObjGamerule2*)Objs::GetObj(OBJ_GAMERULE2);
		objg->Getf();
		this->SetStatus(false);  //自身に削除命令を出す
		Hits::DeleteHitBox(this);//保有するHitBoxに削除する
	}
}

//ドロー
void CObjGamerule::Draw()
{
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };
	Font::StrDraw(L"操作説明", 270, 30, 60, c);

	Font::StrDraw(L"・↑キー", 70, 220, 30, c);
	Font::StrDraw(L"「アイテムを拾う」", 70, 260, 30, c);

	Font::StrDraw(L"・←キー", 70, 120, 30, c);
	Font::StrDraw(L"「左に移動」", 70, 160, 30, c);

	Font::StrDraw(L"・→キー", 500, 120, 30, c);
	Font::StrDraw(L"「右に移動」", 500, 160, 30, c);

	Font::StrDraw(L"・スペースキー", 500, 220, 30, c);
	Font::StrDraw(L"「ジャンプ」", 500, 260, 30, c);

	Font::StrDraw(L"・Xキー", 70, 320, 30, c);
	Font::StrDraw(L"「剣で攻撃」", 70, 360, 30, c);

	Font::StrDraw(L"「スイッチの起動」", 70, 400, 30, c);

	Font::StrDraw(L"・Cキー", 500, 320, 30, c);
	Font::StrDraw(L"「取得した武器使用」", 500, 360, 30, c);

	Font::StrDraw(L"Push[EnterKey]", 185, 500, 60, c);
}