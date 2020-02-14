#include"GameL\WinInputs.h"
#include"GameL\SceneManager.h"
#include"GameL\DrawFont.h"
#include"GameL\UserData.h"

#include"Objstageselect.h"

#include"GameHead.h"

//使用するネームスペース
using namespace GameL;

//イニシャライズ
void CObjstageselect::Init()
{
	m_mou_x = 0.0f;
	m_mou_y = 0.0f;
	m_mou_r = false;
	m_mou_l = false;
	keyE = 0;
	key = false;
	flag = false;
	m_time = 0;
	mapnum = 0;
}

//アクション
void CObjstageselect::Action()
{
	m_time++;
	if (Input::GetVKey(VK_UP) == true)
	{
		if (flag == true)
		{
			keyE--;
			flag = false;
		}
	
	}
	else if (Input::GetVKey(VK_DOWN) == true)
	{
		if (flag == true)
		{
			keyE++;
			flag = false;
		}
	}
	else
	{
		flag = true;
	}

	//選択肢を選ぶとき
	if (keyE >= 3)
	{
		keyE = 0;
	}
	if (keyE <= -1)
	{
		keyE = 1;
	}
	
	if (m_time > 10)
	{
		//選択肢
		//stage1に移行
		if (keyE == 0 && Input::GetVKey(VK_RETURN) == true)
		{
			mapnum = 0;
			mapflag = 11;
			Scene::SetScene(new CSceneStage1(11,0,0,0));
		}
		//stage2に移行
		if (keyE == 1 && Input::GetVKey(VK_RETURN) == true)
		{
			mapnum = 8;
			mapflag = 12;
			Scene::SetScene(new CSceneStage1(12,8,0,0));
		}
		//タイトル画面に移行
		if (keyE == 2 && Input::GetVKey(VK_RETURN) == true)
		{
			Scene::SetScene(new CSceneTitle());
		}
	}
}
//ドロー
void CObjstageselect::Draw()
{
	//描画カラー情報
	float c[4] = { 1,1,1,1 };

	//ステージ選択画面の描画	
	Font::StrDraw(L"Lost World", 50, 90, 140, c);//タイトル
	
	if (keyE == 0)
	{
		Font::StrDraw(L"▶stage1", 165, 300, 80, c);
		Font::StrDraw(L"  stage2", 160, 400, 80, c);
		Font::StrDraw(L"　title", 160, 500, 80, c);
	}
	if (keyE == 1)
	{
		Font::StrDraw(L"  stage1", 165, 300, 80, c);
		Font::StrDraw(L"▶stage2", 160, 400, 80, c);
		Font::StrDraw(L"　title", 160, 500, 80, c);
	}
	else if (keyE == 2)
	{
		Font::StrDraw(L"  stage1", 165, 300, 80, c);
		Font::StrDraw(L"  stage2", 160, 400, 80, c);
		Font::StrDraw(L"▶title", 160, 500, 80, c);
	}
}