//STL�f�o�b�O�@�\��OFF�ɂ���
#define _SECURE_SCL (0)
#define _HAS_ITERATOR_DEBUGGING (0)

//GameL�Ŏg�p����w�b�_�[
#include"GameL\SceneObjManager.h"
#include"GameL\DrawTexture.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�g�p�w�b�_�[
#include"stageselect.h"
#include"GameHead.h"

//�R���X�g���N�^
stageselect::stageselect()
{

}

//�f�X�g���N�^
stageselect::~stageselect()
{

}

//�Q�[���^�C�g�����������\�b�h
void stageselect::InitScene()
{
	//�X�e�[�W�Z���N�g�I�u�W�F�N�g�쐬
	CObjstageselect* t = new CObjstageselect();
	Objs::InsertObj(t, OBJ_STAGESELECT, 1);
}

//�Q�[���^�C�g�����s�����\�b�h
void stageselect::Scene()
{

}