//STL�f�o�b�O�@�\��OFF�ɂ���
#define _SECURE_SCL (0)
#define _HAS_ITERATOR_DEBUGGING (0)

//GameL�Ŏg�p����w�b�_�[
#include"GameL\SceneObjManager.h"
#include"GameL\DrawTexture.h"
#include"GameL\Audio.h"


//�g�p����l�[���X�y�[�X
using namespace GameL;

//�g�p�w�b�_�[
#include"SceneTitle.h"
#include"GameHead.h"

//�R���X�g���N�^
CSceneTitle::CSceneTitle()
{

}

//�f�X�g���N�^
CSceneTitle::~CSceneTitle()
{

}

//�Q�[���^�C�g�����������\�b�h
void CSceneTitle::InitScene()
{
	//�^�C�g���I�u�W�F�N�g�쐬
	CObjTitle* t = new CObjTitle();
	Objs::InsertObj(t, OBJ_TITLE, 1);

	//���y���̓ǂݍ���
	Audio::LoadAudio(0, L"Title.wav", SOUND_TYPE::BACK_MUSIC);

	//�o�b�N�~���[�W�b�N�X�^�[�g
	float Volume = Audio::VolumeMaster(-0.0f);//�}�X�^�[�{�����[����������
	Audio::Start(0);//���y�X�^�[�g
}

//�Q�[���^�C�g�����s�����\�b�h
void CSceneTitle::Scene()
{

}