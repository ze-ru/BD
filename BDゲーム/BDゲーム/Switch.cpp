//使用するヘッダーファイル

#include"GameL\WinInputs.h"
#include"GameL\SceneManager.h"
#include"GameL\DrawTexture.h"
#include"GameL\HitBoxManager.h"

#include"Switch.h"

#include"GameHead.h"

//使用するネームスペース
using namespace GameL;

//イニシャライズ
void CObjSwitch::Init()
{

}

//アクション
void CObjSwitch::Action()
{
	//	Switch削除test
	//自身のHitBoxを持ってくる
	CHitBox* hit = Hits::GetHitBox(this);
	if (hit->CheckObjNameHit(OBJ_HERO) != nullptr)
	{
		//this->SetStatus(false);//自身に削除命令を出す
		//Hits::DeleteHitBox(this);//保有するHitBoxに削除する
	}

}

//ドロー
void CObjSwitch::Draw()
{
	
}