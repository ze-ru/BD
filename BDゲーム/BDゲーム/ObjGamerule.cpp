//�g�p�w�b�_�[�t�@�C��
#include "GameL\DrawFont.h"
#include "GameL\WinInputs.h"

#include "GameHead.h"
#include "ObjGamerule.h"
#include "GameL\HitBoxManager.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�C�j�V�����C�Y
void CObjGamerule::Init()
{
	m_time = 0;  //��ʐ؂�ւ��̎��ԊǗ�
	m_frame = 0; //��ʐ؂�ւ��̃t���O
	Hits::SetHitBox(this, 0, 0, 64, 64, ELEMENT_ENEMY, OBJ_WOLKENEMY, 1);//���̓����蔻��
}

//�A�N�V����
void CObjGamerule::Action()
{
	//m_frame��1�ɂ���Ԋu
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
		CObjGamerule2 *objg = (CObjGamerule2*)Objs::GetObj(OBJ_GAMERULE2);
		objg->Getf();
		this->SetStatus(false);  //���g�ɍ폜���߂��o��
		Hits::DeleteHitBox(this);//�ۗL����HitBox�ɍ폜����
	}
}

//�h���[
void CObjGamerule::Draw()
{
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };
	Font::StrDraw(L"�������", 270, 30, 60, c);

	Font::StrDraw(L"�E���L�[", 70, 220, 30, c);
	Font::StrDraw(L"�u�A�C�e�����E���v", 70, 260, 30, c);

	Font::StrDraw(L"�E���L�[", 70, 120, 30, c);
	Font::StrDraw(L"�u���Ɉړ��v", 70, 160, 30, c);

	Font::StrDraw(L"�E���L�[", 500, 120, 30, c);
	Font::StrDraw(L"�u�E�Ɉړ��v", 500, 160, 30, c);

	Font::StrDraw(L"�E�X�y�[�X�L�[", 500, 220, 30, c);
	Font::StrDraw(L"�u�W�����v�v", 500, 260, 30, c);

	Font::StrDraw(L"�EX�L�[", 70, 320, 30, c);
	Font::StrDraw(L"�u���ōU���v", 70, 360, 30, c);

	Font::StrDraw(L"�u�X�C�b�`�̋N���v", 70, 400, 30, c);

	Font::StrDraw(L"�EC�L�[", 500, 320, 30, c);
	Font::StrDraw(L"�u�擾��������g�p�v", 500, 360, 30, c);

	Font::StrDraw(L"Push[EnterKey]", 185, 500, 60, c);
}