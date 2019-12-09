//使用するヘッダーファイル
#include"GameL\WinInputs.h"
#include"GameL\SceneManager.h"
#include"GameL\DrawFont.h"
#include"GameL\HitBoxManager.h"

#include"Heal.h"
#include"GameL\UserData.h"

#include"GameHead.h"

//使用するネームスペース
using namespace GameL;

CObjHeal::CObjHeal(float x, float y)
{
	m_px = x;
	m_py = y;
}


//イニシャライズ
void CObjHeal::Init()
{
	hp = 20;
	
	Hits::SetHitBox(this, m_px, m_py, 64, 64, ELEMENT_RED, OBJ_HEAL, 1);
}

//アクション
void CObjHeal::Action()
{
	CObjBlock*pb = (CObjBlock*)Objs::GetObj(OBJ_BLOCK);
	CObjHero*hero = (CObjHero*)Objs::GetObj(OBJ_HERO);
	CHitBox* hit = Hits::GetHitBox(this);

	if (hit->CheckElementHit(ELEMENT_PLAYER) == true)
	{
		hero->SetHP(hp);
		this->SetStatus(false);//自身に削除命令を出す
		Hits::DeleteHitBox(this);//保有するHitBoxに削除する
	}
	
	hit->SetPos(m_px + pb->GetScroll(), m_py);
}

//ドロー
void CObjHeal::Draw()
{
	float c[4] = { 1,1,1,1 };
	
		RECT_F src;
		RECT_F dst;


		src.m_top = 0.0f;
		src.m_left = 0.0f;
		src.m_right = 64.0f;
		src.m_bottom = 64.0f;

		//ブロック情報を持ってくる
		CObjBlock*block = (CObjBlock*)Objs::GetObj(OBJ_BLOCK);
		//
		dst.m_top = m_py;
		dst.m_left = m_px + block->GetScroll();
		dst.m_right = dst.m_left + 64.0f;
		dst.m_bottom = 64.0f + m_py;

		Draw::Draw(21, &src, &dst, c, 0.0f);

	
}