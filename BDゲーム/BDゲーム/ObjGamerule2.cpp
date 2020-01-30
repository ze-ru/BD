//�g�p�w�b�_�[�t�@�C��
#include "GameL\DrawFont.h"
#include "GameL\WinInputs.h"

#include "GameHead.h"
#include "ObjGamerule2.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�C�j�V�����C�Y
void CObjGamerule2::Init()
{
	m_time =  0;
	m_frame = 0;
	s = false;
}

//�A�N�V����
void CObjGamerule2::Action()
{
	if (Input::GetVKey(VK_RETURN) == true && s == true)
	{
		//m_frame��1�ɂ���Ԋu
		if (m_frame == 0)
		{
			m_time++;
		}

		if (m_time > 3)
		{
			Scene::SetScene(new CSceneStage1(11, 0, 0, 0));
		}
		
	}
}

//�h���[
void CObjGamerule2::Draw()
{
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };
	
	if (s == true)
	{
		Font::StrDraw(L"�������", 270, 30, 60, c);

		Font::StrDraw(L"�E�A�T���g���C�t��", 50, 120, 40, c);
		Font::StrDraw(L"�u�A�ˍU���ł���v", 70, 160, 40, c);

		Font::StrDraw(L"�E�X�i�C�p�[���C�t��", 50, 240, 40, c);
		Font::StrDraw(L"�u�G���ђʂ��čU���ł���v", 70, 280, 40, c);

		Font::StrDraw(L"�E���[�U�[�e", 50, 360, 40, c);
		Font::StrDraw(L"�u�G���ђʂ��čU���ł���v", 70, 400, 40, c);

		Font::StrDraw(L"START:Push[EnterKey]", 115, 500, 60, c);
	}

	
}