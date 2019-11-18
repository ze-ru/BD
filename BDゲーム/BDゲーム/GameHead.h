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
	OBJ_WOLKENEMY,
	OBJ_STAGEUI,
	OBJ_SHOP,
	OBJ_FLYENEMY,
	OBJ_NORMAL_BULLET,
	OBJ_ATTACK,
	OBJ_NO_NAME,
	OBJ_ASSAULT_BULLET,
	OBJ_GAME_OVER,
	OBJ_GAMERULE,
	OBJ_WEAPONSHOP,
	OBJ_STAGE1CLEAR,
	OBJ_STAGE2CLEAR,

	OBJ_STAGESELECT,
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


#include"BossBlock.h"

#include"Hero.h"

#include"LockEnemy.h"
#include"WolkEnemy.h"
#include"FlyEnemy.h"

#include"Block.h"


#include"ObjStage1.h"


#include"ObjTitle.h"
#include"ObjGameOver.h"
#include"StageUi.h"

#include"ObjShop.h"
#include"ObjGamerule.h"

#include"NormalBullet.h"
#include"ObjAttack.h"

#include"AssaultBullet.h"


#include"Objstageselect.h"
#include"ObjStage1Clear.h"
#include"ObjStage2Clear.h"
//------------------------------------------------

//ゲームシーンクラスヘッダ------------------------
#include"SceneStage1.h"


#include"SceneTitle.h"
#include "SceneGameOver.h"
#include"Gamerule.h"
#include "SceneShop.h"
#include"WeaponShop.h"

#include"stageselect.h"

//-----------------------------------------------

//シーンスタートクラス---------------------------
//ゲーム開始時のシーンクラス登録
#define SET_GAME_START  stageselect
//-----------------------------------------------