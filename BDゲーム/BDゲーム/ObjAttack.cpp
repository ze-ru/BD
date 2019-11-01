//�g�p�w�b�_�[�t�@�C��
#include"GameL\DrawTexture.h"
#include"GameL\WinInputs.h"
#include"GameL\SceneManager.h"
#include"GameL\HitBoxManager.h"

#include"GameHead.h"
#include"ObjAttack.h"

//�g�p�l�[���X�y�[�X
using namespace GameL;


CObjAttack::CObjAttack(float x, float y)
{
	m_px = x;
	m_py = y;
}
//�C�j�V�����C�Y
void CObjAttack::Init()
{
	CObjHero*objh = (CObjHero*)Objs::GetObj(OBJ_HERO);

	m_px = objh->GetX() + 64.0f;
	m_py = objh->GetY();
	m_vx = objh->GetVX();//�ړ��x�N�g��
	m_vy = objh->GetVY();
	m_posture = 0.0f;//�E����0.0f ������1.0f
	
	m_ani_time = 0;
	m_ani_frame = 1;

	m_hp = 0.0f;
	m_time1 = 0;
	m_time2 = 1;
	flag = false;
	//block�Ƃ̏Փˏ�Ԋm�F�p
	m_hit_up = false;
	m_hit_down = false;
	m_hit_left = false;
	m_hit_right = false;

	m_attack = false;
	Hits::SetHitBox(this, m_px+m_vx,m_py+m_vy, 32, 64, ELEMENT_ATTACK, OBJ_HERO, 1);
}

//�A�N�V����
void CObjAttack::Action()
{
	CObjHero*objh = (CObjHero*)Objs::GetObj(OBJ_HERO);
	
	
	m_time1++;

	if (objh->GetFlag(flag) == false)
	{
		m_time2 = 1;
	}
	if (objh->GetFlag(flag) == true)
	{
		m_time2 = -1;
	}

	m_vx = objh->GetVX();
	
	//���g��HitBox�������Ă���
	CHitBox* hit = Hits::GetHitBox(this);

	//�G�Ɠ������Ă��邩�m�F
	if (hit->CheckObjNameHit(OBJ_WOLKENEMY) != nullptr)
	{
		//��l�����G�Ƃǂ̊p�x�œ������Ă邩�m�F
		
		this->SetStatus(false);//���g�ɍ폜���߂��o��
		Hits::DeleteHitBox(this);//�ۗL����HitBox�ɍ폜����
	}
	if (hit->CheckObjNameHit(OBJ_LOCKENEMY) != nullptr)
	{
		
		this->SetStatus(false);//���g�ɍ폜���߂��o��
		Hits::DeleteHitBox(this);//�ۗL����HitBox�ɍ폜����
	}
	if (hit->CheckObjNameHit(OBJ_NORMAL_BULLET) != nullptr)
	{
		this->SetStatus(false);//���g�ɍ폜���߂��o��
		Hits::DeleteHitBox(this);//�ۗL����HitBox�ɍ폜����
	}

	//�ʒu�̍X�V
	m_px +=(m_time2*m_vx);
	m_py = objh->GetY();

	//HitBox�̈ʒu�̕ύX
	hit->SetPos(m_px, m_py);

	if (m_time1 == 8)
	{

	}
	
	if (m_time1== 8)
	{
		this->SetStatus(false);//���g�ɍ폜���߂��o��
		Hits::DeleteHitBox(this);//�ۗL����HitBox�ɍ폜����
		m_time1 = 0;
	}
}

//�h���[
void CObjAttack::Draw()
{
	//�`��J���[���
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src;//�`�挳�؂���ʒu
	RECT_F dst;//�`���\���ʒu
	src.m_top = 0.0f;
	src.m_left = 64.0f*7.0f;
	src.m_right = src.m_left+64.0f;
	src.m_bottom = m_time1*8;

	dst.m_top = 0.0f + m_py;
	dst.m_left = 32.0f-32.0f* m_time2 + m_px * m_time2;
	dst.m_right = 32.0f + 32.0f* m_time2 +m_px * m_time2;
	dst.m_bottom = m_time1*8 + m_py;

	//�`��
	Draw::Draw(1, &src, &dst, c, 0.0f);
}