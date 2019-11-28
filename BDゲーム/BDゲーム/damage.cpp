//�g�p�w�b�_�[�t�@�C��
#include"GameL\DrawTexture.h"
#include"GameL\WinInputs.h"
#include"GameL\SceneManager.h"
#include"GameL\HitBoxManager.h"

#include"GameHead.h"
#include "damege.h"
#include"Hero.h"

//�g�p�l�[���X�y�[�X
using namespace GameL;

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
	Hits::SetHitBox(this, m_px, m_py, 0, 0, ELEMENT_BLUE, OBJ_DAMEGE, 1);
}

//�A�N�V����
void CObjDamege::Action()
{

}

//�h���[
void CObjDamege::Draw()
{

	CObjBlock*pb = (CObjBlock*)Objs::GetObj(OBJ_BLOCK);
	//�`��J���[���
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };
	wchar_t str[50];

	
		size++;
		hit_time++;
		wchar_t str2[50];
		if (hit_time < 50)
		{
			swprintf_s(str2, L"%d", dam);

			Font::StrDraw(str2, m_px + pb->GetScroll() - 20.0f, m_py - size, 20, c);

		}
		if (hit_time > 50)
		{
			this->SetStatus(false);//���g�ɍ폜���߂��o��
			Hits::DeleteHitBox(this);//�ۗL����HitBox�ɍ폜����
		}
	
}