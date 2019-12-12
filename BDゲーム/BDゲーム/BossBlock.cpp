//�g�p����w�b�_�[�t�@�C��

#include"GameL\WinInputs.h"
#include"GameL\SceneManager.h"
#include"GameL\DrawTexture.h"
#include"GameL\HitBoxManager.h"

#include"BossBlock.h"

#include"GameHead.h"
#include"GameL\Audio.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�C�j�V�����C�Y
CObjBossBlock::CObjBossBlock(float x,float y,int stagenum)
{
    m_bx = x;
    m_by = y;
	num = stagenum;
}

void CObjBossBlock::Init()
{
	m_vy = 0;
	m_vx = 0;

	bossflag = false;

	m_hit_up = false;
	m_hit_down = false;
	m_hit_left = false;
	m_hit_right = false;

	boss_flag = false;
	m_time = 0;

	musicflag = false;

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

	if ((hero->GetX() - block->GetScroll()) > 17920 && num == 8 && boss_flag == false)
	{
		boss_flag = true;
	}
	if (boss_flag == true)
	{
		if (m_time < 150)
			m_time++;
	}
	if (m_time == 150)
	{
		num = 30;
	}
	

	//��l�������͈͂ɓ���Ɠ����蔻����s
	if ((hero->GetX() - block->GetScroll()) > 17920 || bossflag == true)
	{
	
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
			if (len < 88.0f)
			{
				//�p�x�ŏ㉺���E�𔻒�

				//�E
				if ((r < 45 && r > 0) || r > 315)
				{
					m_hit_right = true;
					hero->SetX(m_bx + 64.0f + block->GetScroll());
					hero->SetVX(-hero->GetVX()*0.1f);

				}
				//��
				if (r > 135 && r < 225)
				{
					m_hit_left = true;
					hero->SetX(m_bx - 64.0f + block->GetScroll());
					hero->SetVX(-hero->GetVX()*0.1f);

				}

			}

		}
		bossflag = true;
	}

	//�X�N���[�����~�߂�
	if (bossflag == true)
	{

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
	CObjHero*hero = (CObjHero*)Objs::GetObj(OBJ_HERO);
	CObjBlock*block = (CObjBlock*)Objs::GetObj(OBJ_BLOCK);

	if ((hero->GetX() - block->GetScroll()) > 17920 || bossflag == true)
	{
		dst.m_top = m_by;
		dst.m_left = m_bx + block->GetScroll();
		dst.m_left = m_bx + block->GetScroll();
		dst.m_right = dst.m_left + 64.0f;
		dst.m_bottom = 64.0f + m_by;
	}
	
		


	Draw::Draw(num, &src, &dst, c, 0.0f);
}