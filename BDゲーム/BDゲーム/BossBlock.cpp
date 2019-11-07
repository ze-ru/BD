//使用するヘッダーファイル

#include"GameL\WinInputs.h"
#include"GameL\SceneManager.h"
#include"GameL\DrawTexture.h"
#include"GameL\HitBoxManager.h"

#include"BossBlock.h"

#include"GameHead.h"

//使用するネームスペース
using namespace GameL;

//イニシャライズ
CObjBossBlock::CObjBossBlock(float x, float y)
{
	m_bx = x;
	m_by = y;
}
void CObjBossBlock::Init()
{
	m_hit_up = false;
	m_hit_down = false;
	m_hit_left = false;
	m_hit_right = false;

	Hits::SetHitBox(this, m_bx, m_by, 64, 64, ELEMENT_BLOCK, OBJ_BOSSBLOCK, 1);
	
}

//アクション
void CObjBossBlock::Action()
{
	CObjBlock*block = (CObjBlock*)Objs::GetObj(OBJ_BLOCK);
	CObjHero*hero = (CObjHero*)Objs::GetObj(OBJ_HERO);

	//HitBoxの位置変更
	CHitBox* hit = Hits::GetHitBox(this);
	hit->SetPos(m_bx + block->GetScroll(), m_by);
	

}

//ドロー
void CObjBossBlock::Draw()
{
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src;
	RECT_F dst;


	src.m_top = 0.0f;
	src.m_left = 64.0f;
	src.m_right = 64.0f;
	src.m_bottom = 64.0f;

	//ブロック情報を持ってくる
	CObjBlock*block = (CObjBlock*)Objs::GetObj(OBJ_BLOCK);
	//
	dst.m_top = m_by;
	dst.m_left = m_bx + block->GetScroll();
	dst.m_right = dst.m_left + 64.0f;
	dst.m_bottom = 64.0f + m_by;

	Draw::Draw(0, &src, &dst, c, 0.0f);
}