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
	m_vx = 0.0f;
	m_vy = 0.0f;
	m_px = 400.0f - 32.0f;
    m_py = -64.0f;
	int time = 0;
}

//アクション
void CObjStage2Clear::Action()
{
	//time++;
	if(m_vy<=1700)
	m_vy ++;

	
	//for(int i=0;)

	if (Input::GetVKey(VK_RETURN) == true&&m_vy>1600)
	{
		Scene::SetScene(new CSceneTitle());
	}
}

//ドロー
void CObjStage2Clear::Draw()
{
	float c[4] = { 1,1,1,1 };

	Font::StrDraw(L"Congratulation!!", 100, 600 - m_vy, 80, c);

	Font::StrDraw(L"GAME CLEAR!!", 180, 750 - m_vy, 80, c);

	Font::StrDraw(L"ゲーム作成スタッフ", 180, 920 - m_vy, 50, c);

	Font::StrDraw(L"総合ディレクター 岩本　紫苑", 50, 1050 - m_vy, 50, c);

	Font::StrDraw(L"プログラマー　   寺井　望斗季", 50, 1150 - m_vy, 50, c);

	Font::StrDraw(L"グラフィック　   立和名　克弥", 50, 1250 - m_vy, 50, c);

	Font::StrDraw(L"プランナー　     松﨑　隼人", 50, 1350 - m_vy, 50, c);

	Font::StrDraw(L"アシスタント  　 松本　和益",  50, 1450 - m_vy, 50, c);

	Font::StrDraw(L"スペシャルサンクス  近コン", 50, 1550 - m_vy, 50, c);

	Font::StrDraw(L"Thank you for playing!!", 120, 1900-m_vy, 50, c);

	Font::StrDraw(L"Team BD.", 330,2100-m_vy, 30, c);

}