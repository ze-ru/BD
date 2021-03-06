#pragma once

//オブジェクトネーム------------------------------
enum OBJ_NAME
{
	OBJ_SWITCH,
	OBJ_BOSSBLOCK,

	OBJ_HERO,
	OBJ_BLOCK,
	OBJ_STAGE1,
	OBJ_TITLE,
	OBJ_LOCKENEMY,
	OBJ_LOCKENEMY2,
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
	OBJ_LASER_BULLET,
	OBJ_SHOT_BULLET,
	OBJ_SELECTBACK,
	OBJ_GAMERULE2,
	OBJ_HEROSHOTGUN,
	OBJ_HERO_SHOTBULLET,
	//オブジェクト名無し(禁止)
	//ゲームで使うオブジェクトの名前
	//OBJ_○○と表記
	
};
//------------------------------------------------

//当たり判定属性----------------------------------
enum HIT_ELEMENTS
{
	ELEMENT_NULL,//属性無し 全ての属性と当たり判定が実行される
	//以下　同じ属性同士では当たり判定は実行されない
	//属性は追加可能だが、デバック時の色は初期設定分しか無い
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
	ELEMENT_LASERBULLET,
	ELEMENT_SHIELD,
	ELEMENT_SHOTBULLET,
	
};
//------------------------------------------------

//------------------------------------------------
//セーブ＆ロードとシーン間のやり取りするデータ
struct UserData
{
	int mSeveData;	//サンプルセーブデータ
	
};
//------------------------------------------------


//ゲーム内で使用されるグローバル変数・定数・列挙--



//------------------------------------------------
//ゲーム内で使用するクラスヘッダ------------------


//------------------------------------------------

//ゲームシーンオブジェクトヘッダ------------------
#include"Switch.h"
#include"BossEnemy.h"

#include"BossBlock.h"
#include"ShopOBJ.h"
#include"Hero.h"
#include"HeroAssultBullet.h"
#include"LockEnemy.h"
#include"LockEnemy2.h"
#include"WolkEnemy.h"
#include"FlyEnemy.h"
#include"Boss1.h"
#include"Boss2.h"
#include"Block.h"
#include"GoalBlock.h"
#include"explosion.h"

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
#include"ObjGamerule2.h"

#include"NormalBullet.h"
#include"ObjAttack.h"

#include"AssaultBullet.h"
#include"Assault.h"
#include"LaserBullet.h"
#include"laser.h"
#include"Rifle.h"

#include"Shield.h"
#include"ShotGun.h"

#include"Objstageselect.h"
#include"ObjStage1Clear.h"
#include"ObjStage2Clear.h"
#include"ObjSelectBack.h"
#include"HeroShotBullet.h"
#include"HeroShotGun.h"
//------------------------------------------------

//ゲームシーンクラスヘッダ------------------------
#include"SceneStage1.h"


#include"SceneTitle.h"
#include "SceneGameOver.h"
#include"Gamerule.h"
#include"ObjGamerule2.h"
#include "SceneShop.h"
#include"WeaponShop.h"
#include"SceneGameClear.h"
#include"stageselect.h"

//-----------------------------------------------

//シーンスタートクラス---------------------------
//ゲーム開始時のシーンクラス登録
#define SET_GAME_START  CSceneTitle
//-----------------------------------------------