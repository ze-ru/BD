#include "GameL\DrawTexture.h"
#include "GameL\WinInputs.h"
#include "GameL\SceneManager.h"
#include"GameL\SceneObjManager.h"
#include "GameHead.h"
#include"ObjShop.h"

//使用するネームスペース
using namespace GameL;

void CObjShop::Init()
{
	key = true;
	keyS = 0;
}

void CObjShop::Action()
{

	//ショップに入るとき
	if (Input::GetVKey(VK_UP) == true)
	{
		key = true;
	}

	//選択肢を選ぶとき
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
	

	//選択肢
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