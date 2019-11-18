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
	m_mou_x = 0.0f;
	m_mou_y = 0.0f;
	m_mou_r = false;
	m_mou_l = false;
	m_key_flag = false;//キーフラグ
	key = true;
}

//アクション
void CObjStage1Clear::Action()
{
	
}

//ドロー
void CObjStage1Clear::Draw()
{
	float c[4] = { 1,1,1,1 };


	if (key == true)
	{	
		Font::StrDraw(L"STAGE CLEAR", 85, 70, 180, c);
	}
	
}