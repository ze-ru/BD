//使用するヘッダーファイル
#include"GameL\WinInputs.h"
#include"GameL\SceneManager.h"
#include"GameL\DrawTexture.h"
#include"GameL\HitBoxManager.h"

#include"Switch2.h"
#include"GameHead.h"

//使用するネームスペース
using namespace GameL;

//イニシャライズ
CObjSwitch2::CObjSwitch2(float x, float y)
{
	m_sx = x;
	m_sy = y;
}
void CObjSwitch2::Init()
{
	m_hit_up = false;
	m_hit_down = false;
	m_hit_left = false;
	m_hit_right = false;

	flag = false;

	Hits::SetHitBox(this, m_sx, m_sy, 64, 64, ELEMENT_ENEMY, OBJ_SWITCH, 1);
}

//アクション
void CObjSwitch2::Action()
{
	CObjBlock*block = (CObjBlock*)Objs::GetObj(OBJ_BLOCK2);
	//	Switch削除test
	//自身のHitBoxを持ってくる
	CHitBox* hit = Hits::GetHitBox(this);
	hit->SetPos(m_sx + block->GetScroll(), m_sy);

	if (hit->CheckElementHit(ELEMENT_ATTACK) == true)
	{
		flag += 1;
		this->SetStatus(false);//自身に削除命令を出す
		Hits::DeleteHitBox(this);//保有するHitBoxに削除する
	}

	block->SetBlock(flag);


}

//ドロー
void CObjSwitch2::Draw()
{
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src;
	RECT_F dst;


	src.m_top = 0.0f;
	src.m_left = 256.0f;
	src.m_right = 320.0f;
	src.m_bottom = 64.0f;

	//ブロック情報を持ってくる
	CObjBlock2*block = (CObjBlock2*)Objs::GetObj(OBJ_BLOCK2);
	//
	dst.m_top = m_sy;
	dst.m_left = m_sx + block->GetScroll();
	dst.m_right = dst.m_left + 64.0f;
	dst.m_bottom = 64.0f + m_sy;

	Draw::Draw(0, &src, &dst, c, 0.0f);
}