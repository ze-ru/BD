//�g�p�w�b�_�[�t�@�C��
#include"GameL\DrawTexture.h"
#include"GameL\WinInputs.h"
#include"GameL\SceneManager.h"

#include"GameHead.h"
#include "StageUi.h"
#include"Hero.h"

//�g�p�l�[���X�y�[�X
using namespace GameL;

//�C�j�V�����C�Y
void CObjStageUi::Init()
{
	m_hp = 50.0f;
	m_ani_time = 0;
	m_ani_frame = 0;
}

//�A�N�V����
void CObjStageUi::Action()
{
	

}

//�h���[
void CObjStageUi::Draw()
{
	//�`��J���[���
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src;//�`�挳�؂���ʒu
	RECT_F dst;//�`���\���ʒu

	/*//�؂���ʒu�̐ݒ�
	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 128.0f;
	src.m_bottom = 24.0f;
	

	//�\���ʒu�̐ݒ�
	dst.m_top = 0.0f;
	dst.m_left = 0.0f;
	dst.m_right = 256.0f;
	dst.m_bottom = 48.0f;

	

	//�`��
	Draw::Draw(5, &src, &dst, c, 0.0f);

	src.m_top = 2.0f;
	src.m_left = 128.0f;
	src.m_right = 129.0f;
	src.m_bottom = 22.0f;

	
		dst.m_top = 4.0f;
		dst.m_left = 4.0f;
		dst.m_right = 256.0f+m_hp;
		dst.m_bottom = 44.0f;

		Draw::Draw(5, &src, &dst, c, 0.0f);
	
	*/

}