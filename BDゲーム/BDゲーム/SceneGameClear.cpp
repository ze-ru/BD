//STL�f�o�b�N�@�\��OFF�ɂ���
#define _SECURE_SCL (0)
#define _HAS_ITERATOR_DEBUGGING (0)

//GameL�Ŏg�p����w�b�_�[
#include "GameL\SceneObjManager.h"
#include "GameL\DrawFont.h"
#include "GameL\Audio.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�g�p�w�b�_�[
#include "SceneGameClear.h"
#include "GameHead.h"

//�R���X�g���N�^
CSceneGameClear::CSceneGameClear()
{

}

//�f�X�g���N�^
CSceneGameClear::~CSceneGameClear()
{

}

//�Q�[�����C�����������\�b�h
void CSceneGameClear::InitScene()
{
	//���y���̓ǂݍ���
	Audio::LoadAudio(15, L"normal.wav", SOUND_TYPE::BACK_MUSIC);

	//�X�^�b�t���[���I�u�W�F�N�g�쐬
	CObjStage2Clear* obj = new CObjStage2Clear();
	Objs::InsertObj(obj, OBJ_STAGE2CLEAR, 10);

	float Volume = Audio::VolumeMaster(-0.0f);//�}�X�^�[�{�����[����������
	Audio::Start(15);//���y�X�^�[�g
}

//�Q�[�����C�����s�����\�b�h
void CSceneGameClear::Scene()
{

}