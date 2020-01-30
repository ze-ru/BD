//�g�p����w�b�_�[�t�@�C��
#include"GameL\DrawTexture.h"
#include"GameL\WinInputs.h"
#include"GameL\SceneManager.h"
#include"GameL\HitBoxManager.h"

#include"GameHead.h"
#include"AssaultBullet.h"
#include"GameL\Audio.h"

using namespace GameL;
//�R���X�g���N�^
CObjAssaultBullet::CObjAssaultBullet(float x, float y)
{
	m_px = x;//�ʒuX
	m_py = y;//�ʒuY
}
//�C�j�V�����C�Y
void CObjAssaultBullet::Init()
{
	m_vx = 0.0f;//X���̉����x
	m_vy = 0.0f;//Y���̉����x
	m_time = 0;//�e�̏����^�C�~���O�Ǘ��p

	m_hit_up = false;//�����蔻��F��
	m_hit_down = false;//�����蔻��F��
	m_hit_left = false;//�����蔻��F��
	m_hit_right = false;//�����蔻��F�E
	m_count = 0;//��x�����e�ۂ̕������Ƃ邽�߂̃J�E���g
	dm = 2;//�_���[�W��
	Audio::Start(7);//���ˉ�
	Hits::SetHitBox(this, m_px, m_py, 24, 16, ELEMENT_ENEMY_BULLET, OBJ_ASSAULT_BULLET, 1);//�����蔻��쐬
}
//�A�N�V����
void CObjAssaultBullet::Action()
{

	m_time++;
	if (m_time == 5)//m_time���T�ɂȂ����甭�ˉ����~�߂�
		Audio::Stop(7);

	CObjBlock*block = (CObjBlock*)Objs::GetObj(OBJ_BLOCK);//�u���b�N���������Ă���
	CObjHero*objh = (CObjHero*)Objs::GetObj(OBJ_HERO);//��l���̏��������Ă���
	CHitBox*hit = Hits::GetHitBox(this);//HitBox�̏��������Ă���

	if(m_count!=1)//��x�������l�𑫂�
		m_count++;

	if (m_count == 1)//��l���̈ʒu�Ɣ�ׂČ��������߂�
	{
		m_vx = (objh->GetX()+32 - m_px- block->GetScroll());
		m_vy = (objh->GetY() - m_py);
		m_count++;
	}

	UnitVec(&m_vx, &m_vy);//���K��

	if (hit->CheckElementHit(ELEMENT_PLAYER) == true)//��l���Ƃ̓����蔻��
	{
		if (objh->GetYflag() == false)//��낯��Ԃł͂Ȃ��ꍇ
			objh->SetDamege(dm);
		if (objh->GetX() + 32 - block->GetScroll() > m_px)//�e�ۂ���l���̈ʒu�����̎�
			objh->SetHitflag(true);//�������Ă���������E�ɂ���
		if (objh->GetX() + 32 - block->GetScroll() < m_px)//�e�ۂ���l���̈ʒu���E�̎�
			objh->SetHitflag(false);//�������Ă�����������ɂ���
		Audio::Start(13);
		Audio::Stop(7);
		this->SetStatus(false);//���g�ɍ폜���߂��o��
		Hits::DeleteHitBox(this);//�ۗL����HitBox�ɍ폜����
		Audio::Stop(13);
	}
	if (hit->CheckElementHit(ELEMENT_ATTACK) == true)//��l���̌��U���ɓ�����ƒe�ۂ��폜����B
	{
		Audio::Stop(7);
		this->SetStatus(false);//���g�ɍ폜���߂��o��
		Hits::DeleteHitBox(this);//�ۗL����HitBox�ɍ폜����
	}
	
	if (hit->CheckObjNameHit(OBJ_WOLKENEMY) != nullptr)//���s�G�ɓ���������
	{
		Audio::Stop(7);
		this->SetStatus(false);//���g�ɍ폜���߂��o��
		Hits::DeleteHitBox(this);//�ۗL����HitBox�ɍ폜����
	}
	if (hit->CheckObjNameHit(OBJ_SHIELDENEMY) != nullptr)//�������G�ɓ���������
	{
		Audio::Stop(7);
		this->SetStatus(false);//���g�ɍ폜���߂��o��
		Hits::DeleteHitBox(this);//�ۗL����HitBox�ɍ폜����
	}
	if (hit->CheckObjNameHit(OBJ_SHIELD) != nullptr)//���ɓ���������
	{
		Audio::Stop(7);
		this->SetStatus(false);//���g�ɍ폜���߂��o��
		Hits::DeleteHitBox(this);//�ۗL����HitBox�ɍ폜����
	}
	if (hit->CheckObjNameHit(OBJ_LOCKENEMY) != nullptr)//�C��ɓ���������
	{
		Audio::Stop(7);
		this->SetStatus(false);//���g�ɍ폜���߂��o��
		Hits::DeleteHitBox(this);//�ۗL����HitBox�ɍ폜����
	}
	//�ʒu�̍X�V
	m_px += m_vx;
	m_py += m_vy;
	//HitBox�̍X�V
	hit->SetPos(m_px + block->GetScroll(), m_py);
	
	//���Ԍo�߂Œe�ۂ��폜����
	if (m_time > 150)
	{
		Audio::Stop(7);
		this->SetStatus(false);//���g�ɍ폜���߂��o��
		Hits::DeleteHitBox(this);//�ۗL����HitBox�ɍ폜����
	}
	//�u���b�N�Ƃ̓����蔻��
	block->BulletHit(&m_px, &m_py, false, &m_hit_up, &m_hit_down,
		&m_hit_left, &m_hit_right);
	//�������Ă���ꍇ
	if (m_hit_up == true || m_hit_down == true || m_hit_left == true || m_hit_right == true)
	{
		Audio::Stop(7);
		this->SetStatus(false);//���g�ɍ폜���߂��o��
		Hits::DeleteHitBox(this);//�ۗL����HitBox�ɍ폜����
	}

}
//�h���[
void CObjAssaultBullet::Draw()
{
	//�F���@RED�@GREEN�@BULE�@alpha(���ߏ��j
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src;//�`�挳�؂���ʒu
	RECT_F dst;//�`���\���ʒu

	//�`�挳�؂���ʒu
	src.m_top = 0.0f;
	src.m_left = 88.0f;
	src.m_right = 112.0f;
	src.m_bottom = 16.0f;


	CObjBlock*block = (CObjBlock*)Objs::GetObj(OBJ_BLOCK);//�u���b�N�̏��������Ă���

	//�`���\���ʒu
	dst.m_top = m_py + 4.0f;
	dst.m_left = m_px + block->GetScroll();
	dst.m_right = dst.m_left + 24.0f;
	dst.m_bottom = 20.0f + m_py;


	//�`��
	Draw::Draw(4, &src, &dst, c, 0.0f);
}

//���K���֐�
//vx :X���̉����x
//vy :Y���̉����x
//�^����ꂽ�l�𐳋K������
bool UnitVec(float *vx, float *vy)
{
	float r = 0.0f;
	r = (*vx)*(*vx) + (*vy)*(*vy);
	r = sqrt(r);

	if (r == 0.0f)
	{
		return false;
	}
	else
	{
		(*vx) = 5.0f / r * (*vx);
		(*vy) = 5.0f / r * (*vy);
	}
	return true;
}