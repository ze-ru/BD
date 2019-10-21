//�g�p����w�b�_�[�t�@�C��
#include"GameL\DrawTexture.h"
#include"GameL\WinInputs.h"
#include"GameL\SceneManager.h"
#include"GameL\DrawFont.h"

#include"ObjTitle.h"
#include"SceneStage1.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�C�j�V�����C�Y
void CObjTitle::Init()
{
	m_mou_x = 0.0f;
	m_mou_y = 0.0f;
	m_mou_r = false;
	m_mou_l = false;
}

//�A�N�V����
void CObjTitle::Action()
{
	//�}�E�X�̈ʒu���擾
	m_mou_x = (float)Input::GetPosX();
	m_mou_y = (float)Input::GetPosY();
	//�}�E�X�̃{�^���̏��
	m_mou_r = Input::GetMouButtonR();
	m_mou_l = Input::GetMouButtonL();

	//�}�E�X�̈ʒu�ƃN���b�N����ꏊ�œ����蔻��
	if (m_mou_x > 280 && m_mou_x < 500 && m_mou_y > 400 && m_mou_y < 430)
	{
		//�}�E�X�̃{�^���������ꂽ�烁�C���ɑJ��
		if (m_mou_r == true || m_mou_l == true)
		{
			Scene::SetScene(new CSceneStage1());
		}
	}
}

//�h���[
void CObjTitle::Draw()
{
	float c[4] = { 1,1,1,1 };

	//���}�E�X�̈ʒu�\��
	wchar_t str[256];
	swprintf_s(str, L"x=%f,y=%f", m_mou_x, m_mou_y);
	Font::StrDraw(str, 20, 20,12, c);
	//���}�E�X�̃{�^�����
	if (m_mou_r == true)
		Font::StrDraw(L"R=�����Ă�", 20, 30, 12, c);
	else
		Font::StrDraw(L"R=�����ĂȂ�", 20, 30, 12, c);

	if (m_mou_l == true)
		Font::StrDraw(L"L=�����Ă�", 20, 40, 12, c);
	else
		Font::StrDraw(L"L=�����ĂȂ�", 20, 40, 12, c);

	//�^�C�g��
	Font::StrDraw(L"Lost", 320, 200, 80, c);

	//�N���b�N����ꏊ
	//Game�Ɉڍs�N���b�N�ꏊ
	Font::StrDraw(L"��ClickStart", 300, 400, 30, c);
}