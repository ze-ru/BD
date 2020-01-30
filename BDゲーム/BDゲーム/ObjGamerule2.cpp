//使用ヘッダーファイル
#include "GameL\DrawFont.h"
#include "GameL\WinInputs.h"

#include "GameHead.h"
#include "ObjGamerule2.h"

//使用するネームスペース
using namespace GameL;

//イニシャライズ
void CObjGamerule2::Init()
{
	m_time =  0;
	m_frame = 0;
	s = false;
}

//アクション
void CObjGamerule2::Action()
{
	if (Input::GetVKey(VK_RETURN) == true && s == true)
	{
		//m_frameを1にする間隔
		if (m_frame == 0)
		{
			m_time++;
		}

		if (m_time > 3)
		{
			Scene::SetScene(new CSceneStage1(11, 0, 0, 0));
		}
		
	}
}

//ドロー
void CObjGamerule2::Draw()
{
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };
	
	if (s == true)
	{
		Font::StrDraw(L"操作説明", 270, 30, 60, c);

		Font::StrDraw(L"・アサルトライフル", 50, 120, 40, c);
		Font::StrDraw(L"「連射攻撃できる」", 70, 160, 40, c);

		Font::StrDraw(L"・スナイパーライフル", 50, 240, 40, c);
		Font::StrDraw(L"「敵を貫通して攻撃できる」", 70, 280, 40, c);

		Font::StrDraw(L"・レーザー銃", 50, 360, 40, c);
		Font::StrDraw(L"「敵を貫通して攻撃できる」", 70, 400, 40, c);

		Font::StrDraw(L"START:Push[EnterKey]", 115, 500, 60, c);
	}

	
}