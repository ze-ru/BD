//�g�p����w�b�_�[�t�@�C��
#include"GameL\WinInputs.h"
#include"GameL\SceneManager.h"
#include"GameL\DrawTexture.h"
#include"GameL\HitBoxManager.h"
#include"GameL\Audio.h"

#include"Switch.h"
#include"GameHead.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�R���X�g���N�^
CObjSwitch::CObjSwitch(float x, float y)
{
	m_sx = x;
	m_sy = y;
}

//�C�j�V�����C�Y
void CObjSwitch::Init()
{
	flag = false;

	//���y���̓ǂݍ���
	Audio::LoadAudio(1, L"switch.wav", SOUND_TYPE::EFFECT);

	//�����蔻��p��HitBox���쐬
	Hits::SetHitBox(this,m_sx,m_sy, 64, 64, ELEMENT_ENEMY, OBJ_SWITCH, 1);
}

//�A�N�V����
void CObjSwitch::Action()
{
	//�I�u�W�F�N�g�����擾
	CObjBlock*block = (CObjBlock*)Objs::GetObj(OBJ_BLOCK);//�u���b�N�I�u�W�F�N�g�����擾
	
	//���g��HitBox�������Ă���
	CHitBox* hit = Hits::GetHitBox(this);
	hit->SetPos(m_sx + block->GetScroll(), m_sy);

	//�X�C�b�`�̃o�[���E�������A���ōU��������
	if (hit->CheckElementHit(ELEMENT_ATTACK)==true&&flag==false)
	{
		float Volume = Audio::Volume(10.0f,1);//�{�����[�����グ��
		Audio::Start(1);//���y�X�^�[�g
		flag = true;//�X�C�b�`�����E���]������
	}
	block->SetBlock(flag);
}

//�h���[
void CObjSwitch::Draw()
{
	//�`��J���[���
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src;//�`�挳�؂���ʒu
	RECT_F dst;//�`���\���ʒu

	//�\���ʒu�̐ݒ�
	src.m_top = 0.0f;
	src.m_left = 256.0f;
	src.m_right = 320.0f;
	src.m_bottom = 64.0f;

	//�u���b�N���������Ă���
	CObjBlock*block = (CObjBlock*)Objs::GetObj(OBJ_BLOCK);

	//�\���ʒu�̐ݒ�
	if (flag == false)
	{		
		dst.m_top = m_sy;
		dst.m_left = m_sx + block->GetScroll();
		dst.m_right = dst.m_left + 64.0f;
		dst.m_bottom = 64.0f + m_sy;
	}
	if (flag == true)//���E���]�X�C�b�`��`��
	{
		dst.m_top = m_sy;
		dst.m_left = m_sx + block->GetScroll() + 64.0f;
		dst.m_right = dst.m_left-64.0f;
		dst.m_bottom = 64.0f + m_sy;	
	}

	//�`��
	Draw::Draw(0, &src, &dst, c, 0.0f);
}