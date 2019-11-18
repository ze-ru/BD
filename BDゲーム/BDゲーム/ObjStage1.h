#pragma once
#include"GameL\SceneObjManager.h"
using namespace GameL;

class CObjStage1 :public CObj
{

private:
	
	int map_flag;
	bool flag;
public:
	CObjStage1(int mapdata);
	~CObjStage1() {};
	void Init();
	void Action();
	void Draw();

	

};