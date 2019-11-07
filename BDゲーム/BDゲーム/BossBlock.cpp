//�g�p����w�b�_�[�t�@�C��

#include"GameL\WinInputs.h"
#include"GameL\SceneManager.h"
#include"GameL\DrawTexture.h"
#include"GameL\HitBoxManager.h"

#include"BossBlock.h"

#include"GameHead.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�C�j�V�����C�Y
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

//�A�N�V����
void CObjBossBlock::Action()
{
	CObjBlock*block = (CObjBlock*)Objs::GetObj(OBJ_BLOCK);
	CObjHero*hero = (CObjHero*)Objs::GetObj(OBJ_HERO);

	//HitBox�̈ʒu�ύX
	CHitBox* hit = Hits::GetHitBox(this);
	hit->SetPos(m_bx + block->GetScroll(), m_by);
	

}

//�h���[
void CObjBossBlock::Draw()
{
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src;
	RECT_F dst;


	src.m_top = 0.0f;
	src.m_left = 64.0f;
	src.m_right = 64.0f;
	src.m_bottom = 64.0f;

	//�u���b�N���������Ă���
	CObjBlock*block = (CObjBlock*)Objs::GetObj(OBJ_BLOCK);
	//
	dst.m_top = m_by;
	dst.m_left = m_bx + block->GetScroll();
	dst.m_right = dst.m_left + 64.0f;
	dst.m_bottom = 64.0f + m_by;

	Draw::Draw(0, &src, &dst, c, 0.0f);
}