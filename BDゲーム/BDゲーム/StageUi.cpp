//�g�p�w�b�_�[�t�@�C��
#include"GameL\DrawTexture.h"
#include"GameL\WinInputs.h"
#include"GameL\SceneManager.h"

#include"GameHead.h"
#include "StageUi.h"

//�g�p�l�[���X�y�[�X
using namespace GameL;

//�C�j�V�����C�Y
void CObjStageUi::Init()
{
	m_hp = 0;
	m_ani_time = 0;
	m_ani_frame = 0;
}

//�A�N�V����
void CObjStageUi::Action()
{
	if (m_hp <50) 
	{
		m_ani_time++;
	}
	if (m_ani_time == 5)
	{
		m_ani_frame++;
		m_ani_time = 0;
	}
	if (m_ani_frame == 9)
	{
		m_hp++;
		m_ani_frame = 0;
	}
	if (m_hp >= 50)
	{
		//Scene::SetScene(new CSceneGameOver());
	}

}

//�h���[
void CObjStageUi::Draw()
{
	//�`��J���[���
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src;//�`�挳�؂���ʒu
	RECT_F dst;//�`���\���ʒu

	//�؂���ʒu�̐ݒ�
	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 128.0f;
	src.m_bottom = 24.0f;
	

	//�\���ʒu�̐ݒ�
	dst.m_top = 0.0f;
	dst.m_left = 0.0f;
	dst.m_right = 128.0f;
	dst.m_bottom = 24.0f;

	

	//�`��
	Draw::Draw(5, &src, &dst, c, 0.0f);

	src.m_top = 2.0f;
	src.m_left = 128.0f;
	src.m_right = 130.0f;
	src.m_bottom = 22.0f;

	
		dst.m_top = 2.0f;
		dst.m_left = 2.0f;
		dst.m_right = 128.0f-m_hp*2.5f;
		dst.m_bottom = 22.0f;

		Draw::Draw(5, &src, &dst, c, 0.0f);
	
	

}