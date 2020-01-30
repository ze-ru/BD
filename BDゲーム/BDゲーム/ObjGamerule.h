#pragma once
//使用するヘッダー
#include "GameL\SceneObjManager.h"

//使用するネームスペース
using namespace GameL;

//オブジェクト:タイトル
class CObjGamerule :public CObj
{
public:
	CObjGamerule() {};
	~CObjGamerule() {};
	void Init();   //イニシャライズ
	void Action(); //アクション
	void Draw();   //ドロー
private:
	int m_time;    //画面切り替えの時間管理
	int m_frame;   //画面切り替えのフラグ
};