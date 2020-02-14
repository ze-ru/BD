//�g�p����w�b�_�[�t�@�C��
#include"GameL\WinInputs.h"
#include"GameL\SceneManager.h"
#include"GameL\DrawFont.h"
#include"GameL\HitBoxManager.h"

#include"Heal.h"
#include"GameL\UserData.h"

#include"GameHead.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�R���X�g���N�^
CObjHeal::CObjHeal(float x, float y)
{
	m_px = x;//�ʒuX
	m_py = y;//�ʒuY
}

//�C�j�V�����C�Y
void CObjHeal::Init()
{
	//��l����HP��20�񕜂�����
	hp = 20;
	
	//�����蔻��pHitBox���쐬
	Hits::SetHitBox(this, m_px, m_py, 64, 64, ELEMENT_RED, OBJ_HEAL, 1);
}

//�A�N�V����
void CObjHeal::Action()
{
	//�I�u�W�F�N�g�����擾
	CObjBlock*pb = (CObjBlock*)Objs::GetObj(OBJ_BLOCK);//�u���b�N�I�u�W�F�N�g���擾
	CObjHero*hero = (CObjHero*)Objs::GetObj(OBJ_HERO);//��l���I�u�W�F�N�g���擾

	//HitBox�̓��e���X�V
	CHitBox* hit = Hits::GetHitBox(this);//�쐬����HitBox�X�V�p�̓���������o��	
	//��l���ƐڐG������HP���񕜁AHealBlock�폜
	if (hit->CheckElementHit(ELEMENT_PLAYER) == true)
	{
		hero->SetHP(hp);//��l����HP����
		this->SetStatus(false);//���g�ɍ폜���߂��o��
		Hits::DeleteHitBox(this);//�ۗL����HitBox�ɍ폜����
	}
	hit->SetPos(m_px + pb->GetScroll(), m_py);//���������V�����ʒu���ɒu��������
}

//�h���[
void CObjHeal::Draw()
{
	//�`��J���[���
	float c[4] = { 1,1,1,1 };
	
	RECT_F src;//�`�挳�؂���ʒu
	RECT_F dst;//�`���\���ʒu

	//�؂���ʒu�̐ݒ�
	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 64.0f;
	src.m_bottom = 64.0f;

	//�u���b�N���������Ă���
	CObjBlock*block = (CObjBlock*)Objs::GetObj(OBJ_BLOCK);
		
	//�\���ʒu�̐ݒ�
	dst.m_top = m_py;
	dst.m_left = m_px + block->GetScroll();
	dst.m_right = dst.m_left + 64.0f;
	dst.m_bottom = 64.0f + m_py;

	//�`��
	Draw::Draw(21, &src, &dst, c, 0.0f);	
}