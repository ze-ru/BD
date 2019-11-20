#pragma once
#include"GameL\SceneObjManager.h"
using namespace GameL;

class CObjStage1 :public CObj
{

private:
	
	int map_flag;
	bool flag;
	int score;
	int time;
public:
	CObjStage1(int mapdata);
	~CObjStage1() {};
	void Init();
	void Action();
	void Draw();
	void Getscore(int num) { score += num; }

	

};