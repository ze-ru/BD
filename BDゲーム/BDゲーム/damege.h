#pragma once
//使用ヘッダー
#include"GameL\SceneObjManager.h"
//使用ネームスペース
using namespace GameL;

//オブジェクト：主人公
class CObjDamege :public CObj
{
public:
	CObjDamege(int dm,float x,float y);
	~CObjDamege() {};
	void Init();
	void Action();
	void Draw();
private:
	int dam;
	int hit_time;
	float m_px;
	float m_py;
	int size;

};