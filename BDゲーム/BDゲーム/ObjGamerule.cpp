//�g�p�w�b�_�[�t�@�C��
#include "GameL\DrawFont.h"
#include "GameL\WinInputs.h"

#include "GameHead.h"
#include "ObjGamerule.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�C�j�V�����C�Y
void CObjGamerule::Init()
{
	m_time = 0;
	m_frame = 0;
}

//�A�N�V����
void CObjGamerule::Action()
{
	if (m_frame == 0)
	{
		m_time++;
	}
	
	if (m_time > 10)
	{
		m_time = 0;
		m_frame = 1;
	}
	
	if (Input::GetVKey(VK_RETURN) == true&&m_frame==1)
	{
		Scene::SetScene(new CSceneStage1(11,0,0,0));
	}
}

//�h���[
void CObjGamerule::Draw()
{
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };
	Font::StrDraw(L"�������", 270, 30, 60, c);

	Font::StrDraw(L"�E���L�[", 40, 220, 30, c);
	Font::StrDraw(L"�u�A�C�e�����E���v", 40, 260, 30, c);

	Font::StrDraw(L"�E���L�[", 40, 120, 30, c);
	Font::StrDraw(L"�u���Ɉړ��v", 40, 160, 30, c);

	Font::StrDraw(L"�E���L�[", 500, 120, 30, c);
	Font::StrDraw(L"�u�E�Ɉړ��v", 500, 160, 30, c);

	Font::StrDraw(L"�E�X�y�[�X�L�[", 500, 220, 30, c);
	Font::StrDraw(L"�u�W�����v�v", 500, 260, 30, c);

	Font::StrDraw(L"�EX�L�[", 40, 320, 30, c);
	Font::StrDraw(L"�u���ōU���v(�G�̍U����h��)", 40, 360, 30, c);

	Font::StrDraw(L"�u�X�C�b�`�̋N���v", 40, 400, 30, c);

	Font::StrDraw(L"�EC�L�[", 500, 320, 30, c);
	Font::StrDraw(L"�u��������g�p�v", 500, 360, 30, c);

	Font::StrDraw(L"START:Push[EnterKey]", 115, 500, 60, c);
}