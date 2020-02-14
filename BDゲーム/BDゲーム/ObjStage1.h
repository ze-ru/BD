#pragma once
//使用するヘッダー
#include"GameL\SceneObjManager.h"

//使用するネームスペース
using namespace GameL;

//オブジェクト:ステージ
class CObjStage1 :public CObj
{
private:
	
	int map_flag;
	int map_num;
	bool flag;
	int score;
	
	int m_time;

	bool bossflag;
public:
	CObjStage1(int mapdata,int map_num);
	~CObjStage1() {};
	void Init();//イニシャライズ
	void Action();//アクション
	void Draw();//ドロー

	void Getscore(int num) { score += num; }
	int Getmapnum() { return map_num; }
	int Getmapflag() { return map_flag; }
};