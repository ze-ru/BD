//�g�p����w�b�_�[�t�@�C��
#include"GameL\DrawTexture.h"
#include"GameL\WinInputs.h"
#include"GameL\SceneManager.h"
#include"GameL\DrawFont.h"
#include"GameL\Audio.h"

#include"ObjStage1.h"
#include"GameHead.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�R���X�g���N�^
CObjStage1::CObjStage1(int mapdata,int mapnum)
{
	map_flag = mapdata;
	map_num = mapnum;
}

//�C�j�V�����C�Y
void CObjStage1::Init()
{
	flag = true;
	score = 0;
	
	bossflag = false;

	m_time = 0;
}

//�A�N�V����
void CObjStage1::Action()
{

	//T�L�[���͂ŃX�e�[�W�Z���N�g���
	if (Input::GetVKey('T') == true)
	{
		Scene::SetScene(new stageselect());
	}

	//�I�u�W�F�N�g�����擾
	CObjHero*hero = (CObjHero*)Objs::GetObj(OBJ_HERO);//��l���I�u�W�F�N�g�����擾
	CObjBlock*block = (CObjBlock*)Objs::GetObj(OBJ_BLOCK);//�u���b�N�I�u�W�F�N�g�����擾

	//��l�������͈͂ɓ���Ɠ����蔻����s
	if ((hero->GetX() - block->GetScroll()) > 17920 && map_flag == 12 && bossflag == false)
	{
		bossflag = true;
		map_flag = 10;
	}
	if (bossflag == true)
	{
		if (m_time < 150)
			m_time++;
	}
	if (m_time == 150)
	{
		map_flag = 13;
	}	
}

//�h���[
void CObjStage1::Draw()
{
	//�`��J���[���
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };
	
	RECT_F src;//�`�挳�؂���ʒu
	RECT_F dst;//�`���\���ʒu

	//map_flag�̔ԍ��̃O���t�B�b�N�̐؂���ʒu�̐ݒ�
	if (map_flag == 11)
	{
		src.m_top = 0.0f;
		src.m_left = 0.0f;
		src.m_right = 800.0f;
		src.m_bottom = 600.0f;
	}
	if (map_flag == 12)
	{
		src.m_top = 0.0f;
		src.m_left = 0.0f;
		src.m_right = 640.0f;
		src.m_bottom = 480.0f;
	}
	if (map_flag == 13)
	{
		src.m_top = 0.0f;
		src.m_left = 0.0f;
		src.m_right = 640.0f;
		src.m_bottom = 640.0f;
	}

	//�\���ʒu�̐ݒ�
	dst.m_top = 0.0f;
	dst.m_left = 0.0f;
	dst.m_right = 800.0f;
	dst.m_bottom = 600.0f;

	//map_flag�̔ԍ��ɓo�^�����O���t�B�b�N��src�Edst�Ec�̏������ɕ`��
	Draw::Draw(map_flag, &src, &dst, c, 0.0f);
}