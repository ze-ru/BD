//�g�p����w�b�_�[�t�@�C��
#include "GameL\DrawTexture.h"
#include "GameL\WinInputs.h"
#include "GameL\SceneManager.h"

#include "GameHead.h"
#include "Block.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�C�j�V�����C�Y
void CObjBlock::Init()
{
	//�}�b�v���
	int block_data[10][10] =
	{
		{0,0,0,0,0,0,0,0,0,0,},
		{0,0,0,0,0,0,0,1,1,0,},
		{0,0,0,0,0,0,0,0,0,0,},
		{0,0,0,0,0,0,0,0,0,0,},
		{0,0,0,0,0,0,0,0,0,0,},
		{0,0,0,0,0,0,0,0,0,0,},
		{0,0,0,1,1,1,0,0,0,1,},
		{0,0,0,0,0,0,0,0,0,1,},
		{0,0,0,0,0,0,0,0,0,1,},
		{1,1,1,1,1,1,1,1,1,1,},
	};
	//�}�b�v�f�[�^���R�s�[
	memcpy(m_map, block_data, sizeof(int)*(10 * 10));
}
//�A�N�V����
void CObjBlock::Action()
{

}
//�h���[
void CObjBlock::Draw()
{
	//�`��J���[���
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src; //�`�挳�؂���ʒu
	RECT_F dst; //�`���\���ʒu

	//�w�i�\��
	

	//�}�b�v�`�b�v�ɂ��block�ݒu
	//�؂���ʒu�̐ݒ�
	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = src.m_left + 64.0f;
	src.m_bottom = 64.0f;

	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			if (m_map[i][j] > 0)
			{
				//�\���ʒu�̐ݒ�
				dst.m_top = i *64.0f;
				dst.m_left = j *64.0f;
				dst.m_right = dst.m_left + 64.0f;
				dst.m_bottom = dst.m_top + 64.0f;

				//�`��
				Draw::Draw(0, &src, &dst, c, 0.0f);
			}
		}
	}
	
}