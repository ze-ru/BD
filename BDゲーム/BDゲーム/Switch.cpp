//�g�p����w�b�_�[�t�@�C��

#include"GameL\WinInputs.h"
#include"GameL\SceneManager.h"
#include"GameL\DrawTexture.h"
#include"GameL\HitBoxManager.h"

#include"Switch.h"

#include"GameHead.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�C�j�V�����C�Y
void CObjSwitch::Init()
{

}

//�A�N�V����
void CObjSwitch::Action()
{
	//	Switch�폜test
	//���g��HitBox�������Ă���
	CHitBox* hit = Hits::GetHitBox(this);
	if (hit->CheckObjNameHit(OBJ_HERO) != nullptr)
	{
		//this->SetStatus(false);//���g�ɍ폜���߂��o��
		//Hits::DeleteHitBox(this);//�ۗL����HitBox�ɍ폜����
	}

}

//�h���[
void CObjSwitch::Draw()
{
	
}