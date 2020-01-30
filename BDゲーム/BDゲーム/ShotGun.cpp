#include"GameL\DrawTexture.h"
#include"GameL\WinInputs.h"
#include"GameL\SceneManager.h"
#include"GameL\HitBoxManager.h"

#include"GameHead.h"
#include"ShotGun.h"
#include"GameL\Audio.h"
#include<math.h>

using namespace GameL;

CObjShotBullet::CObjShotBullet(float x, float y,int r)
{
	m_px = x;//X���W�̏ꏊ
	m_py = y;//Y���W�̏ꏊ
	r_rad = r;//�p�x
}
void CObjShotBullet::Init()
{

	m_vx = cosf(3.14 / 180 * r_rad);//cos�̊p�x���v�Z
	m_vy = sinf(3.14 / 180 * r_rad);//sin�̊p�x���v�Z
	UnitVec(&m_vx, &m_vy);//���K��
	m_time = 0;//���Ԃ̏�����

	m_hit_up = false;//��̓����蔻��
	m_hit_down = false;//���̓����蔻��
	m_hit_left = false;//���̓����蔻��
	m_hit_right = false;//�E�̓����蔻��
	m_count = 0;//�e�̐����J�E���g
	m_v = 1.0f;//�e�̑��x
	dm = 3;//�_���[�W�l
	Audio::Start(7);
	Hits::SetHitBox(this, m_px, m_py, 24, 16, ELEMENT_ENEMY_BULLET, OBJ_SHOT_BULLET, 1);//�q�b�g�{�b�N�X�쐬
}
void CObjShotBullet::Action()
{
	m_time++;
	CObjBlock*block = (CObjBlock*)Objs::GetObj(OBJ_BLOCK);//�u���b�N�̏����擾
	CObjHero*objh = (CObjHero*)Objs::GetObj(OBJ_HERO);//��l�q�̏����擾
	CHitBox*hit = Hits::GetHitBox(this);//�q�b�g�{�b�N�X�̏����擾

	//�ʒu�̍X�V
	m_px += m_vx * m_v;
	m_py += m_vy * m_v;

	//�q�b�g�{�b�N�X�̈ʒu�X�V
	hit->SetPos(m_px + block->GetScroll(), m_py);

	if (m_time > 50)
	{
		this->SetStatus(false);//���g�ɍ폜���߂��o��
		Hits::DeleteHitBox(this);//�ۗL����HitBox�ɍ폜����
	}
	//�u���b�N�Ƃ̓����蔻��
	block->BulletHit(&m_px, &m_py, false, &m_hit_up, &m_hit_down,
		&m_hit_left, &m_hit_right);

	//��l���ɒe�����������ꍇ�e������
	if (m_hit_up == true || m_hit_down == true || m_hit_left == true || m_hit_right == true)
	{
		Audio::Stop(7);
		this->SetStatus(false);//���g�ɍ폜���߂��o��
		Hits::DeleteHitBox(this);//�ۗL����HitBox�ɍ폜����
	}

	//��l���ɒe�����������ꍇ�A��l���Ƀ_���[�W��^����
	if (hit->CheckElementHit(ELEMENT_PLAYER) == true)
	{
		if (objh->GetYflag() == false)
			objh->SetDamege(dm);
		if (objh->GetX() + 32 - block->GetScroll() > m_px)
			objh->SetHitflag(true);
		if (objh->GetX() + 32 - block->GetScroll() < m_px)
			objh->SetHitflag(false);
		Audio::Start(13);
		Audio::Stop(7);
		this->SetStatus(false);//���g�ɍ폜���߂��o��
		Hits::DeleteHitBox(this);//�ۗL����HitBox�ɍ폜����
		Audio::Stop(13);
	}

}
void CObjShotBullet::Draw()
{
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src;
	RECT_F dst;

	src.m_top = 0.0f;
	src.m_left = 88.0f;
	src.m_right = 112.0f;
	src.m_bottom = 16.0f;


	CObjBlock*block = (CObjBlock*)Objs::GetObj(OBJ_BLOCK);
	//
	dst.m_top = m_py + 4.0f;
	dst.m_left = m_px + block->GetScroll();
	dst.m_right = dst.m_left + 24.0f;
	dst.m_bottom = 20.0f + m_py;


	//
	Draw::Draw(4, &src, &dst, c, 0.0f);
}