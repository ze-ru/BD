#include "GameL\DrawTexture.h"
#include "GameL\WinInputs.h"
#include "GameL\SceneManager.h"
#include"GameL\SceneObjManager.h"
#include "GameHead.h"
#include"ObjShop.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

void CObjShop::Init()
{
	Key = true;
	flag = 0;
}

void CObjShop::Action()
{
	if (Input::GetVKey(VK_DOWN) == true)
	{
		if (Key == true)
		{
			flag++;
			Key = false;
		}
	}
	else if (Input::GetVKey(VK_UP) == true)
	{
		if (Key == true)
		{
			flag--;
			Key = false;

		}
	}
	else
	{
		Key = true;
	}
	if (flag >= 3)
		flag = 0;
	if (flag < 0)
		flag = 2;
	
}

void CObjShop::Draw()
{

	//�`��J���[���
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	if (flag == 0)
	{
		Font::StrDraw(L"���V���b�v", 120, 100, 80, c);
		Font::StrDraw(L"�E����𔃂�", 120, 300, 80, c);
		Font::StrDraw(L"�E�^�C�g���ɖ߂�", 120, 500, 80, c);
	}
	if (flag == 1)
	{
		Font::StrDraw(L"�E�V���b�v", 120, 100, 80, c);
		Font::StrDraw(L"������𔃂�", 120, 300, 80, c);
		Font::StrDraw(L"�E�^�C�g���ɖ߂�", 120, 500, 80, c);
	}
	if (flag == 2)
	{
		Font::StrDraw(L"�E�V���b�v", 120, 100, 80, c);
		Font::StrDraw(L"�E����𔃂�", 120, 300, 80, c);
		Font::StrDraw(L"���^�C�g���ɖ߂�", 120, 500, 80, c);
	}
}