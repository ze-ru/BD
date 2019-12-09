#pragma once

//�I�u�W�F�N�g�l�[��------------------------------
enum OBJ_NAME
{
	OBJ_SWITCH,
	OBJ_BOSSBLOCK,

	OBJ_HERO,
	OBJ_BLOCK,
	OBJ_STAGE1,
	OBJ_TITLE,
	OBJ_LOCKENEMY,
	OBJ_WOLKENEMY,
	OBJ_STAGEUI,
	OBJ_SHOP,
	OBJ_FLYENEMY,
	OBJ_NORMAL_BULLET,
	OBJ_ATTACK,
	OBJ_NO_NAME,
	OBJ_BOSS1,
	OBJ_ASSAULT_BULLET,
	OBJ_GAME_OVER,
	OBJ_GAMERULE,
	OBJ_WEAPONSHOP,
	OBJ_STAGE1CLEAR,
	OBJ_STAGE2CLEAR,
	OBJ_SHOPOBJ,
	OBJ_STAGESELECT,
	OBJ_BOSS2,
	OBJ_HEROASSULTBULLET,
	OBJ_GOAL_BLOCK,
	OBJ_DAMEGE,
	OBJ_HEAL,
	OBJ_ASSAULT,
	OBJ_SWORD,
	OBJ_RIFLE,
	OBJ_HERONORMALBULLET,
	OBJ_LASER,
	OBJ_BOSSENEMY,
	OBJ_SHIELDENEMY,
	OBJ_SHIELD,
	//�I�u�W�F�N�g������(�֎~)
	//�Q�[���Ŏg���I�u�W�F�N�g�̖��O
	//OBJ_�����ƕ\�L
	
};
//------------------------------------------------

//�����蔻�葮��----------------------------------
enum HIT_ELEMENTS
{
	ELEMENT_NULL,//�������� �S�Ă̑����Ɠ����蔻�肪���s�����
	//�ȉ��@�����������m�ł͓����蔻��͎��s����Ȃ�
	//�����͒ǉ��\�����A�f�o�b�N���̐F�͏����ݒ蕪��������
	ELEMENT_PLAYER,
	ELEMENT_ENEMY,
	ELEMENT_BULLET,
	ELEMENT_ITEM,
	ELEMENT_MAGIC,
	ELEMENT_FIELD,
	ELEMENT_RED,
	ELEMENT_GREEN,
	ELEMENT_BLUE,
	ELEMENT_BLACK,
	ELEMENT_WHITE,
	ELEMENT_BLOCK,
	ELEMENT_ATTACK,
	ELEMENT_SHOP,
	ELEMENT_HEROASSULTBULLET,
	ELEMENT_ENEMY_BULLET,
	ELEMENT_ASSAULT,
	ELEMENT_HERONORMALBULLET,
	ELEMENT_BOSS2,
};
//------------------------------------------------

//------------------------------------------------
//�Z�[�u�����[�h�ƃV�[���Ԃ̂���肷��f�[�^
struct UserData
{
	int mSeveData;	//�T���v���Z�[�u�f�[�^
	
};
//------------------------------------------------


//�Q�[�����Ŏg�p�����O���[�o���ϐ��E�萔�E��--



//------------------------------------------------
//�Q�[�����Ŏg�p����N���X�w�b�_------------------


//------------------------------------------------

//�Q�[���V�[���I�u�W�F�N�g�w�b�_------------------
#include"Switch.h"
#include"BossEnemy.h"

#include"BossBlock.h"
#include"ShopOBJ.h"
#include"Hero.h"
#include"HeroAssultBullet.h"
#include"LockEnemy.h"
#include"WolkEnemy.h"
#include"FlyEnemy.h"
#include"Boss1.h"
#include"Boss2.h"
#include"Block.h"
#include"GoalBlock.h"

#include"ShieldEnemy.h"

#include"ObjStage1.h"
#include"damege.h"
#include"Heal.h"
#include"HeroNormalBullet.h"
#include"ObjTitle.h"
#include"ObjGameOver.h"
#include"StageUi.h"

#include"ObjShop.h"
#include"ObjGamerule.h"

#include"NormalBullet.h"
#include"ObjAttack.h"

#include"AssaultBullet.h"
#include"Assault.h"
#include"laser.h"
#include"Rifle.h"

#include"Shield.h"


#include"Objstageselect.h"
#include"ObjStage1Clear.h"
#include"ObjStage2Clear.h"
//------------------------------------------------

//�Q�[���V�[���N���X�w�b�_------------------------
#include"SceneStage1.h"


#include"SceneTitle.h"
#include "SceneGameOver.h"
#include"Gamerule.h"
#include "SceneShop.h"
#include"WeaponShop.h"
#include"SceneGameClear.h"
#include"stageselect.h"

//-----------------------------------------------

//�V�[���X�^�[�g�N���X---------------------------
//�Q�[���J�n���̃V�[���N���X�o�^
#define SET_GAME_START  CSceneTitle
//-----------------------------------------------