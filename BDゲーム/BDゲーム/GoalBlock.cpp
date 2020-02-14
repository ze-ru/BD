//使用するヘッダーファイル

#include"GameL\WinInputs.h"
#include"GameL\SceneManager.h"
#include"GameL\DrawTexture.h"
#include"GameL\HitBoxManager.h"

#include"GoalBlock.h"

#include"GameHead.h"

//使用するネームスペース
using namespace GameL;

//イニシャライズ
CObjGoalBlock::CObjGoalBlock(float x, float y)
{
	m_bx = x;
	m_by = y;
}

void CObjGoalBlock::Init()
{
	
	Hits::SetHitBox(this, m_bx, m_by, 64, 64, ELEMENT_BLOCK, OBJ_GOAL_BLOCK, 1);

}

//アクション
void CObjGoalBlock::Action()
{

	CObjBlock*pb = (CObjBlock*)Objs::GetObj(OBJ_BLOCK);
	CObjHero*h = (CObjHero*)Objs::GetObj(OBJ_HERO);
	CHitBox* hit = Hits::GetHitBox(this);
	if (hit->CheckElementHit(ELEMENT_PLAYER) == true)
	{
		CObjStage1*s1 = (CObjStage1*)Objs::GetObj(OBJ_STAGE1);
		if(s1->Getmapnum()==0)
			Scene::SetScene(new CSceneStage1(12, 8,h->Getbullet(),h->GetWeapon()));
		else
			Scene::SetScene(new CSceneGameClear());
	}
	hit->SetPos(m_bx+pb->GetScroll(), m_by);
}

//ドロー
void CObjGoalBlock::Draw()
{
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src;
	RECT_F dst;

	CObjStage1*s1 = (CObjStage1*)Objs::GetObj(OBJ_STAGE1);

	if (s1->Getmapnum() == 0)
	{
		src.m_top = 0.0f;
		src.m_left = 0.0f;
		src.m_right = 64.0f;
		src.m_bottom = 64.0f;
	}
	else
	{
		src.m_top = 0.0f;
		src.m_left = 64.0f;
		src.m_right = 128.0f;
		src.m_bottom = 64.0f;
	}
	

	//ブロック情報を持ってくる
	CObjBlock*block = (CObjBlock*)Objs::GetObj(OBJ_BLOCK);
	//
	dst.m_top = m_by;
	dst.m_left = m_bx + block->GetScroll();
	dst.m_right = dst.m_left + 64.0f;
	dst.m_bottom = 64.0f + m_by;

	Draw::Draw(24, &src, &dst, c, 0.0f);
}