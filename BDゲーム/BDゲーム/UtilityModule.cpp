//�g�p����w�b�_�[
#include"GameHead.h"
#include"UtilityModule.h"
#include<math.h>
#include"GameL\DrawTexture.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;
bool UnitVec(float*vx, float*vy)
{
	return true;
}

//---CheckWindow�֐�
//�����P float pos_x   :�̈�O���ǂ����𒲂ׂ邘�ʒu
//�����Q float pos_y   :�̈�O���ǂ����𒲂ׂ邙�ʒu
//�����R float window_x:�̈��top�ʒu
//�����S float window_y:�̈��left�ʒu
//�����T float window_w:�̈��right�ʒu
//�����U float window_h:�̈��bottom�ʒu
//�߂�l bool          :true=�̈�� false=�̈�O
//���e
//�̈�����ǂ����𒲂ׂ�ʒupos_(x,y)��window_(x,y,w,h)�̓����O���𒲂ׂ�
bool CheckWindow(float pos_x, float pos_y,
	float window_x, float window_y, float window_w, float window_h)
{
	//�̈�`�F�b�N
	if (pos_x < window_x)
	{
		return false;//�̈�O
	}
	if (pos_x > window_w)
	{
		return false;//�̈�O
	}
	if (pos_y < window_y)
	{
		return false;//�̈�O
	}
	if (pos_y > window_h)
	{
		return false;//�̈�O
	}

	return true;//�̈��
}
//---GetAtan2Angle�֐�
//�����P float w  :��
//�����Q float h  :����
//�߂�l float    :�p�x�i0���`360���j
//���e
//�����ƕ����璼�p�O�p�`������Ɖ��肵�Ă��̊p�x�����߂�B
float GetAtan2Angle(float w, float h)
{
	//atan�Q�Ŋp�x�����߂�
	float r=atan2(h, w)*180.0f / 3.14f;

	//-180���`-0����180���`360���ɕϊ�
	if (r < 0)
	{
		r = 360 - abs(r);
	}

	return r;

}
//---GetBulletEffec�֐�
//�����P	int*	ani;���e�A�j���[�V����
//�����Q	int*	ani_time;���e�A�j���[�V�����Ԋu�^�C��
//�����R	bool	del;�폜�`�F�b�N�itrue=���e�G�t�F�N�g�@false=�ʏ�̒e��
//�����S	int		timing;�Ԋu���
//�߂�lRECT_F�@eff;�`�悷��RECT
//del�Œe�ۂ�RECT�⒅�e��effect��RECT�i�A�j���[�V������RECT�j��Ԃ�
RECT_F GetBulletEffec(int*ani, int*ani_time, bool del, int timing)
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
			{32,0,32,64},
		{32,32,64,64},
		{32,64,96,64},
		{32,96,128,64},
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