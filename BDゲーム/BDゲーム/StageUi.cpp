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
	tall = 0;
	scoreframe[4] = { NULL };
}

//�A�N�V����
void CObjStageUi::Action()
{
	int scorefalse = score;
	for (int i = 0; i < 4; i++)
	{
		if (scorefalse <= 0)
			break;
		scoreframe[i] = scorefalse % 10;
		scorefalse=score/10;
	}

}

//�h���[
void CObjStageUi::Draw()
{
	//�`��J���[���
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };
	int aniframe[10] = { 0,1,2,3,4,5,6,7,8,9 };
	RECT_F src;//�`�挳�؂���ʒu
	RECT_F dst;//�`���\���ʒu


	for (int i = 0; i < 4; i++)
	{

		if(scoreframe[i]==0)
		{
			src.m_top = 64.0f;
			src.m_left = 32.0f*aniframe[0];
			src.m_right = src.m_left + 32.0f;
			src.m_bottom = 96.0f;
		}
		if (scoreframe[i] == 1)
		{
			src.m_top = 64.0f;
			src.m_left = 32.0f*aniframe[1];
			src.m_right = src.m_left + 32.0f;
			src.m_bottom = 96.0f;
		}
		if (scoreframe[i] == 2)
		{
			src.m_top = 64.0f;
			src.m_left = 32.0f*aniframe[2];
			src.m_right = src.m_left + 32.0f;
			src.m_bottom = 96.0f;
		}
		if (scoreframe[i] == 3)
		{
			src.m_top = 64.0f;
			src.m_left = 32.0f*aniframe[3];
			src.m_right = src.m_left + 32.0f;
			src.m_bottom = 96.0f;
		}
		if (scoreframe[i] == 4)
		{
			src.m_top = 64.0f;
			src.m_left = 32.0f*aniframe[4];
			src.m_right = src.m_left + 32.0f;
			src.m_bottom = 96.0f;
		}
		if (scoreframe[i] == 5)
		{
			src.m_top = 64.0f;
			src.m_left = 32.0f*aniframe[5];
			src.m_right = src.m_left + 32.0f;
			src.m_bottom = 96.0f;
		}
		if (scoreframe[i] == 6)
		{
			src.m_top = 64.0f;
			src.m_left =32.0f*aniframe[6];
			src.m_right = src.m_left + 32.0f;
			src.m_bottom = 96.0f;
		}
		if (scoreframe[i] == 7)
		{
			src.m_top = 64.0f;
			src.m_left = 32.0f*aniframe[7];
			src.m_right = src.m_left + 32.0f;
			src.m_bottom = 96.0f;
		}
		if (scoreframe[i] == 8)
		{
			src.m_top = 64.0f;
			src.m_left = 32.0f*aniframe[8];
			src.m_right = src.m_left + 32.0f;
			src.m_bottom = 96.0f;
		}
		if (scoreframe[i] == 9)
		{
			src.m_top = 64.0f;
			src.m_left = 32.0f*aniframe[9];
			src.m_right = src.m_left + 32.0f;
			src.m_bottom = 96.0f;
		}
		
		

		dst.m_top = 10.0f;
		dst.m_left = 600.0f + 64.0f*(i+1);
		dst.m_right = dst.m_left + 64.0f;
		dst.m_bottom = 74.0f;

		Draw::Draw(18, &src, &dst, c, 1.0f);
	}
	


}