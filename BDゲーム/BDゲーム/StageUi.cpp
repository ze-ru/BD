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
	score = 0;
}

//�A�N�V����
void CObjStageUi::Action()
{
	
}

//�h���[
void CObjStageUi::Draw()
{
	//�u���b�N�I�u�W�F�N�g�o�^
	CObjBlock*pb = (CObjBlock*)Objs::GetObj(OBJ_BLOCK);
	
	//�`��J���[���
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };
	wchar_t str[50];

	//��ʉE���SCORE�\��
	swprintf_s(str, L"�X�R�A�F%d", score);

	//SCORE�̃t�H���g�ݒ�
	Font::StrDraw(str, 650, 10, 20, c);	
}