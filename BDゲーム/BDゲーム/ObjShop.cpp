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
	key = true;
	keyS = 0;
}

void CObjShop::Action()
{

	//�V���b�v�ɓ���Ƃ�
	if (Input::GetVKey(VK_UP) == true)
	{
		key = true;
	}

	//�I������I�ԂƂ�
	if (Input::GetVKey(VK_DOWN) == true)
	{
		key = false;
	}

	if (key = false)
	{
		keyS += 1;
		if (keyS >= 3)
		{
			keyS -= 1;
		}
	}
	else 
	{
		keyS -= 1;
		if (keyS <= -1)
		{
			keyS += 1;
		}
	}
	

	//�I����
	if (0)
	{
		//Scene::SetScene(new SceneWeaponShop);
	}

	if (1)
	{
		

		if (2)
		{
			//Scene::SetScene(new);
		}
	}

}

void CObjShop::Draw()
{
	
}