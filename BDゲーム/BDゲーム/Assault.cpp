//�g�p����w�b�_�[�t�@�C��
#include"GameL\DrawTexture.h"
#include"GameL\WinInputs.h"
#include"GameL\SceneManager.h"
#include"GameL\HitBoxManager.h"

#include"GameHead.h"
#include"Assault.h"

using namespace GameL;
//�R���X�g���N�^
CObjAssault::CObjAssault(float x, float y)
{
	m_px = x;
	m_py = y;
}
//�C�j�V�����C�Y
void CObjAssault::Init()
{
	//HitBox�쐬
	Hits::SetHitBox(this, m_px, m_py, 64, 64, ELEMENT_ASSAULT, OBJ_ASSAULT, 1);
}
//�A�N�V����
void CObjAssault::Action()
{
	CHitBox* hit = Hits::GetHitBox(this);//HitBox���������Ă���
	CObjBlock*pb = (CObjBlock*)Objs::GetObj(OBJ_BLOCK);//�u���b�N���������Ă���

	//�v���C���[�Ƃ̓����蔻��
	if (hit->CheckElementHit(ELEMENT_PLAYER) == true)
	{
		if (Input::GetVKey(VK_UP) == true)
		{
			CObjHero*h = (CObjHero*)Objs::GetObj(OBJ_HERO);//��l�����������Ă���
			if (h->GetWeapon() == 1)
				h->Setbulletnums(30);//��������ԍ��̎��e�ۂ𑝂₷
			else
				h->Setbulletnum(30);//�قȂ镐��ԍ��̎��e�ۂ��R�O���ɂ���
			h->SetWeapon(1);
			
			this->SetStatus(false);//���g�ɍ폜���߂��o��
			Hits::DeleteHitBox(this);//�ۗL����HitBox�ɍ폜����
		}
	}
	//HitBox�X�V
	hit->SetPos(m_px + pb->GetScroll(), m_py);
}
//�h���[
void CObjAssault::Draw()
{
	//�F���@RED�@GREEN�@BULE�@alpha(���ߏ��j
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src;//�`�挳�؂���ʒu
	RECT_F dst;//�`���\���ʒu

	//�`�挳�؂���ʒu
	src.m_top = 0.0f;
	src.m_left = 192.0f;
	src.m_right = 256.0f;
	src.m_bottom = 64.0f;


	CObjBlock*block = (CObjBlock*)Objs::GetObj(OBJ_BLOCK);
	//�`���\���ʒu
	dst.m_top = m_py;
	dst.m_left = m_px + block->GetScroll();
	dst.m_right = dst.m_left+64.0f;
	dst.m_bottom = 64.0f + m_py;


	//�`��
	Draw::Draw(19, &src, &dst, c, 0.0f);
}
