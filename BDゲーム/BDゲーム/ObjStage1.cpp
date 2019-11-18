#include"GameL\DrawTexture.h"
#include"GameL\WinInputs.h"
#include"GameL\SceneManager.h"
#include"GameL\DrawFont.h"
#include"ObjStage1.h"
#include"GameHead.h"

using namespace GameL;

CObjStage1::CObjStage1(int mapdata)
{
	map_flag = mapdata;
}
void CObjStage1::Init()
{
	flag = true;
}

void CObjStage1::Action()
{
	if (Input::GetVKey('A') == true)
	{
		Scene::SetScene(new stageselect());
	}
	
	
}

void CObjStage1::Draw()
{
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src;
	RECT_F dst;

	if (map_flag == 11)
	{
		src.m_top = 0.0f;
		src.m_left = 0.0f;
		src.m_right = 800.0f;
		src.m_bottom = 600.0f;
	}
	if (map_flag == 12)
	{
		src.m_top = 0.0f;
		src.m_left = 0.0f;
		src.m_right = 640.0f;
		src.m_bottom = 480.0f;
	}
	if (map_flag == 13)
	{
		src.m_top = 0.0f;
		src.m_left = 0.0f;
		src.m_right = 640.0f;
		src.m_bottom = 640.0f;
	}
	dst.m_top = 0.0f;
	dst.m_left = 0.0f;
	dst.m_right = 800.0f;
	dst.m_bottom = 600.0f;

	Draw::Draw(map_flag, &src, &dst, c, 0.0f);
	
}