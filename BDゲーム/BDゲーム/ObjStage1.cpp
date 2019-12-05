#include"GameL\DrawTexture.h"
#include"GameL\WinInputs.h"
#include"GameL\SceneManager.h"
#include"GameL\DrawFont.h"
#include"ObjStage1.h"
#include"GameHead.h"

using namespace GameL;

CObjStage1::CObjStage1(int mapdata,int mapnum)
{
	map_flag = mapdata;
	map_num = mapnum;
}
void CObjStage1::Init()
{
	flag = true;
	score = 0;
	time = 0;
	bossflag = false;

	m_time = 0;
}

void CObjStage1::Action()
{
	time++;
	if (Input::GetVKey('A') == true)
	{
		Scene::SetScene(new stageselect());
	}

	CObjHero*hero = (CObjHero*)Objs::GetObj(OBJ_HERO);
	CObjBlock*block = (CObjBlock*)Objs::GetObj(OBJ_BLOCK);
	//ŽålŒö‚ªˆê’è”ÍˆÍ‚É“ü‚é‚Æ“–‚½‚è”»’èŽÀs
	if ((hero->GetX() - block->GetScroll()) > 17920 && map_flag == 12 && bossflag == false)
	{
		bossflag = true;
		map_flag = 10;
	}
	if (bossflag == true)
	{
		if (m_time < 150)
			m_time++;
	}
	if (m_time == 150)
	{
		map_flag = 13;
		m_time = 0;
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