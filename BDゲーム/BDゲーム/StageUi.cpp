//使用ヘッダーファイル
#include"GameL\DrawTexture.h"
#include"GameL\WinInputs.h"
#include"GameL\SceneManager.h"

#include"GameHead.h"
#include "StageUi.h"
#include"Hero.h"

//使用ネームスペース
using namespace GameL;

//イニシャライズ
void CObjStageUi::Init()
{
	score = 0;
	tall = 0;
	hit_time = 0;
	hit = false;
	dam = 0;
}

//アクション
void CObjStageUi::Action()
{
	
}

//ドロー
void CObjStageUi::Draw()
{

	CObjBlock*pb = (CObjBlock*)Objs::GetObj(OBJ_BLOCK);
	//描画カラー情報
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };
	wchar_t str[50];



	swprintf_s(str, L"スコア：%d", score);

	Font::StrDraw(str, 650, 10, 20, c);

	if (hit == true)
	{
		int size = 0;
		size++;
		hit_time++;
		wchar_t str2[50];
		if (hit_time < 50)
		{
			swprintf_s(str2, L"%d", dam);

			Font::StrDraw(str2, m_px + pb->GetScroll() - 20.0f, m_py+size, 20, c);

		}
		if (hit_time > 50)
		{
			dam = 0;
			hit_time = 0;
			hit = false;
			m_px = 0;
			m_py = 0;
		}
	}
}