#include "GameL\DrawTexture.h"
#include"GameL\WinInputs.h"
#include"GameL\SceneManager.h"
#include"GameL\DrawFont.h"
#include"ObjStage2.h"

using namespace GameL;

void CObjStage2::Init()
{

}

void CObjStage2::Action()
{

}

void CObjStage2::Draw()
{
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src;
	RECT_F dst;

	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 640.0f;
	src.m_bottom = 480.0f;

	dst.m_top = 0.0f;
	dst.m_left = 0.0f;
	dst.m_right = 640.0f;
	dst.m_bottom = 480.0f;

	Draw::Draw(2, &src, &dst, c, 0.0f);
}

