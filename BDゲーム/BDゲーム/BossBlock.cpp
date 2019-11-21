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
CObjBossBlock::CObjBossBlock(float x,float y)
{
    m_bx = x;
    m_by = y;
}

void CObjBossBlock::Init()
{
	m_vy = 0;
	m_vx = 0;

	m_hit_up = false;
	m_hit_down = false;
	m_hit_left = false;
	m_hit_right = false;

	Hits::SetHitBox(this, m_bx, m_by, 64, 64, ELEMENT_BLOCK, OBJ_BOSSBLOCK, 1);
	
}

//�A�N�V����
void CObjBossBlock::Action()
{
	CObjHero*hero = (CObjHero*)Objs::GetObj(OBJ_HERO);
	CObjBlock*block = (CObjBlock*)Objs::GetObj(OBJ_BLOCK);

    hx = hero->GetX() - block->GetScroll();
    hy = hero->GetY();

	hvx = hero->GetVX();
	hvy = hero->GetVY();

	if ((hx + 64.0f > m_bx) && (hx < m_bx + 64.0f) && (hy + 64.0f > m_by) && (hy < m_by + 64.0f))
	{
		//���E����

		//vector�̍쐬
		float rvx = hx - m_bx;
		float rvy = hy - m_by;

		//���������߂�
		float len = sqrt(rvx * rvx + rvy * rvy);

		//�p�x�����߂�
		float r = atan2(rvy, rvx);
		r = r * 180.0f / 3.14f;

		if (r <= 0.0f)
			r = abs(r);
		else
			r = 360.0f - abs(r);

		//len��������̒������Z���ꍇ����ɓ���
		//if (len < 88.0f)
		{
			//�p�x�ŏ㉺���E�𔻒�

			//�E
			if ((r < 45 && r > 0) || r > 315)
			{
				m_hit_right = true;
				hx = m_bx + 64.0f + (block->GetScroll());
				hvx = -(hvx)*0.1f;

			}
			//��
			else if (r > 135 && r < 225)
			{
				m_hit_left = true;
				hx = m_bx - 64.0f + (block->GetScroll());
				hvx = -(hvx)*0.1f;

			}

		}

	}

}

//�h���[
void CObjBossBlock::Draw()
{
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src;
	RECT_F dst;


	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 64.0f;
	src.m_bottom = 64.0f;

	//�u���b�N���������Ă���
	CObjBlock*block = (CObjBlock*)Objs::GetObj(OBJ_BLOCK);

	dst.m_top = m_by;
	dst.m_left = m_bx + block->GetScroll();
	dst.m_right = dst.m_left + 64.0f;
    dst.m_bottom = 64.0f + m_by;
	
		


	Draw::Draw(0, &src, &dst, c, 0.0f);
}