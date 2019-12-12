//�g�p����w�b�_�[�t�@�C��

#include"GameL\DrawTexture.h"
#include"explosion.h"

using namespace GameL;


RECT_F GetBulletEffect(int *ani, int *ani_time, bool del, int timing)
{
	//�Ԃ�RECT���
	RECT_F rect;

	//�u���O�Œʏ�e�ۂ����e�A�j���[�V������������
	if (del == true)
	{
		//���e�A�j���[�V����
		//���\�[�X���e�A�j���[�V�����ʒu
		RECT_F ani_src[4] =
		{
			{64,0,64,128},
			{64,64,128,128},
			{64,128,192,128},
			{64,256,256,128},
		};
		//�A�j���[�V�����̃R�}�Ԋu
		if (*ani_time > timing)
		{
			*ani += 1;//�A�j���[�V�����̃R�}��1�i�߂�
			*ani_time = 0;
		}
		else
		{
			*ani_time += 1;
		}
		rect = ani_src[*ani];//�A�j���[�V������RECT�z�񂩂�m_ani�Ԗڂ�RECT����n��
	}
	else
	{
		//�e�ۃA�j���[�V��������
		//���\�[�X�͒e�ۈʒu
		RECT_F bullet = { 0.0f,96.0f,126.0f,32.0f };
		rect = bullet;
	}
	return rect;
}