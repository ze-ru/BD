//�g�p�w�b�_�[�t�@�C��
#include"GameL\DrawTexture.h"
#include"GameL\WinInputs.h"
#include"GameL\SceneManager.h"
#include"GameL\HitBoxManager.h"

#include"damege.h"
#include"Hero.h"
#include"GameHead.h"

//�g�p�l�[���X�y�[�X
using namespace GameL;

//�R���X�g���N�^
CObjDamege::CObjDamege(int dm, float x, float y)
{
	dam = dm;
	m_px = x;
	m_py = y;
}

//�C�j�V�����C�Y
void CObjDamege::Init()
{
	size = 0;
	hit_time = 0;

	//�����蔻��
	Hits::SetHitBox(this, m_px, m_py, 0, 0, ELEMENT_BLUE, OBJ_DAMEGE, 1);
}

//�A�N�V����
void CObjDamege::Action()
{

}

//�h���[
void CObjDamege::Draw()
{	
	//�I�u�W�F�N�g�����擾
	CObjBlock*pb = (CObjBlock*)Objs::GetObj(OBJ_BLOCK);//�u���b�N�I�u�W�F�N�g���擾

	//�G�Ƀ_���[�W��^������_���[�W��\������
	//�`��J���[���
	float c[4] = { 1.0f,0.0f,0.0f,1.0f };
	
	size++;
	hit_time++;

	//�_���[�W�\��
	wchar_t str2[50];
	if (hit_time < 50)
	{
		swprintf_s(str2, L"%d", dam);
		Font::StrDraw(str2, m_px + pb->GetScroll() - 20.0f, m_py - size, 25, c);//�t�H���g�ݒ�
	}
	if (hit_time > 50)
	{
		this->SetStatus(false);//���g�ɍ폜���߂��o��
		Hits::DeleteHitBox(this);//�ۗL����HitBox�ɍ폜����
	}
}