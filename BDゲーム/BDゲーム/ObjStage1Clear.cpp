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
	key = false;
	score = 0;
	count = 0;
	deadflag = false;
	scorecount = 0;
}

//アクション
void CObjStage1Clear::Action()
{	
	time++;

	//Boss1が死んだらSTAGE CLEAR
	if (deadflag == true)
	{
		key = true;
	}
	
}

//ドロー
void CObjStage1Clear::Draw()
{
	float c[4] = { 1,1,1,1 };
	if (key == true)
	{
		RECT_F src;
		RECT_F dst;
		

		src.m_top = 0.0f;
		src.m_left = 0.0f;
		src.m_right = 800.0f;
		src.m_bottom = 600.0f;

		CObjBlock*pb = (CObjBlock*)Objs::GetObj(OBJ_BLOCK);
		CObjHero*h = (CObjHero*)Objs::GetObj(OBJ_HERO);

		
			dst.m_top = 0.0f;
			dst.m_left = 64.0f*145 + pb->GetScroll();
			dst.m_right = dst.m_left+800.0f;
			dst.m_bottom = 600.0f;
		


		//
		Draw::Draw(17, &src, &dst, c, 1.0f);

		wchar_t str[50];

		swprintf_s(str, L"%d", score);

		Font::StrDraw(str, 64.0f * 153 +pb->GetScroll() , 380, 100, c);
		


	}


}