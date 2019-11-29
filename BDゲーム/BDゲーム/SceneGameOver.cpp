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
#include "SceneGameOver.h"
#include "GameHead.h"

//�R���X�g���N�^
CSceneGameOver::CSceneGameOver(int mapflag,int mapnum)
{
	map_flag = mapflag;
	map_num = mapnum;
}

//�f�X�g���N�^
CSceneGameOver::~CSceneGameOver()
{

}

//�Q�[�����C�����������\�b�h
void CSceneGameOver::InitScene()
{
	//���y���̓ǂݍ���
	Audio::LoadAudio(0, L"GameOver.wav", SOUND_TYPE::BACK_MUSIC);

	//�o�b�N�~���[�W�b�N�X�^�[�g
	float Volume = Audio::VolumeMaster(-0.0f);//�}�X�^�[�{�����[����������
	Audio::Start(0);//���y�X�^�[�g

	//�Q�[���I�[�o�[�I�u�W�F�N�g�쐬
	CObjGameOver* obj = new CObjGameOver(map_flag,map_num);
	Objs::InsertObj(obj, OBJ_GAME_OVER, 10);
}

//�Q�[�����C�����s�����\�b�h
void CSceneGameOver::Scene()
{

}