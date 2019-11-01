#pragma once
#include"GameL\SceneObjManager.h"
using namespace GameL;

class CObjStage1 :public CObj
{

private:
	bool flag = false;
public:
	CObjStage1() {};
	~CObjStage1() {};
	void Init();
	void Action();
	void Draw();

	

};