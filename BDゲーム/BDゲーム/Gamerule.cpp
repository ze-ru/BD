//STL�f�o�b�O�@�\��OFF�ɂ���
#define _SECURE_SCL (0)
#define _HAS_ITERATOR_DEBUGGING (0)

//GameL�Ŏg�p����w�b�_�[
#include "GameL\SceneObjManager.h"
#include "GameL\DrawFont.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�g�p�w�b�_�[
#include "Gamerule.h"
#include "GameHead.h"


//�R���X�g���N�^
CSceneGamerule::CSceneGamerule()
{

}

//�f�X�g���N�^
CSceneGamerule::~CSceneGamerule()
{

}

//�Q�[�����C�����������\�b�h
void CSceneGamerule::InitScene()
{
	CObjGamerule2* obj2 = new CObjGamerule2();//�^�C�g���I�u�W�F�N�g�쐬
	Objs::InsertObj(obj2, OBJ_GAMERULE2, 10);//��l���I�u�W�F�N�g�o�^
	//�^�C�g���I�u�W�F�N�g�쐬
	CObjGamerule* obj = new CObjGamerule();//�^�C�g���I�u�W�F�N�g�쐬
	Objs::InsertObj(obj, OBJ_GAMERULE, 10);//��l���I�u�W�F�N�g�o�^

	
}

//�Q�[�����C�����s�����\�b�h
void CSceneGamerule::Scene()
{

}