#pragma once
#include"GameL\SceneObjManager.h"
using namespace GameL;

class CObjStage1 :public CObj
{
public:
	CObjStage1() {};
	~CObjStage1() {};
	void Init();
	void Action();
	void Draw();
private:
};