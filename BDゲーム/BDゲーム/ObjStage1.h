#pragma once
#include"GameL\SceneObjManager.h"
using namespace GameL;

class CObjStage1 :public CObj
{

private:
	
	int map_flag;
	int map_num;
	bool flag;
	int score;
	int time;

	int m_time;

	bool bossflag;
public:
	CObjStage1(int mapdata,int map_num);
	~CObjStage1() {};
	void Init();
	void Action();
	void Draw();
	void Getscore(int num) { score += num; }
	int Getmapnum() { return map_num; }
	int Getmapflag() { return map_flag; }
};