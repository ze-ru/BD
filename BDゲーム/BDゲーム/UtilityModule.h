#pragma once
bool UnitVec(float*vx, float*vy);

//�v���g�^�C�v�錾
bool UnitVec(float vx, float vy);//�x�N�g���̐��K�����s���֐�

bool CheckWindow(float pos_x, float pos_y,
	float winbdow_x, float window_y, float window_w, float window_h);//�̈�����ǂ������`�F�b�N����֐�

float GetAtan2Angle(float w, float h);//�����ƕ��Ŋp�x�����߂�

RECT_F GetBulletEffec(int*ani, int*ani_time, bool del, int timing);//del�Œe�ۂ�RECT�⒅�eeffect��RECT�i�A�j���[�V������RECT�j��Ԃ�
