//STL�f�o�b�O�@�\��OFF�ɂ���
#define _SECURE_SCL (0)
#define _HAS_ITERATOR_DEBUGGING (0)

//GameL�Ŏg�p����w�b�_�[
#include "GameL\SceneObjManager.h"
#include "GameL\DrawFont.h"
#include "GameL\Audio.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�g�p�w�b�_�[
#include "GameHead.h"
#include"SceneShop.h"

//�R���X�g���N�^
CSceneShop::CSceneShop()
{

}

//�f�X�g���N�^
CSceneShop::~CSceneShop()
{

}

//�Q�[�����C�����������\�b�h
void CSceneShop::InitScene()
{

	CObjShop* s = new CObjShop();
	Objs::InsertObj(s, OBJ_SHOP, 1);

	//���y���̓ǂݍ���
	Audio::LoadAudio(0, L"shop.wav", SOUND_TYPE::BACK_MUSIC);

	//�o�b�N�~���[�W�b�N�X�^�[�g
	float Volume = Audio::VolumeMaster(-0.0f);//�}�X�^�[�{�����[����������
	Audio::Start(0);//���y�X�^�[�g

	//�o�͂����镶���̃O���t�B�b�N���쐬
	Font::SetStrTex(L"");

	
}

//�Q�[�����C�����s�����\�b�h
void CSceneShop::Scene()
{
	

	


}