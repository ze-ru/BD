//使用するヘッダーファイル
#include"GameL\DrawTexture.h"
#include"GameL\WinInputs.h"
#include"GameL\SceneManager.h"
#include"GameL\DrawFont.h"
#include"GameL\Audio.h"

#include"ObjStage1.h"
#include"GameHead.h"

//使用するネームスペース
using namespace GameL;

//コンストラクタ
CObjStage1::CObjStage1(int mapdata,int mapnum)
{
	map_flag = mapdata;
	map_num = mapnum;
}

//イニシャライズ
void CObjStage1::Init()
{
	flag = true;
	score = 0;
	
	bossflag = false;

	m_time = 0;
}

//アクション
void CObjStage1::Action()
{

	//Tキー入力でステージセレクト画面
	if (Input::GetVKey('T') == true)
	{
		Scene::SetScene(new stageselect());
	}

	//オブジェクト情報を取得
	CObjHero*hero = (CObjHero*)Objs::GetObj(OBJ_HERO);//主人公オブジェクト情報を取得
	CObjBlock*block = (CObjBlock*)Objs::GetObj(OBJ_BLOCK);//ブロックオブジェクト情報を取得

	//主人公が一定範囲に入ると当たり判定実行
	if ((hero->GetX() - block->GetScroll()) > 17920 && map_flag == 12 && bossflag == false)
	{
		bossflag = true;
		map_flag = 10;
	}
	if (bossflag == true)
	{
		if (m_time < 150)
			m_time++;
	}
	if (m_time == 150)
	{
		map_flag = 13;
	}	
}

//ドロー
void CObjStage1::Draw()
{
	//描画カラー情報
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };
	
	RECT_F src;//描画元切り取り位置
	RECT_F dst;//描画先表示位置

	//map_flagの番号のグラフィックの切り取り位置の設定
	if (map_flag == 11)
	{
		src.m_top = 0.0f;
		src.m_left = 0.0f;
		src.m_right = 800.0f;
		src.m_bottom = 600.0f;
	}
	if (map_flag == 12)
	{
		src.m_top = 0.0f;
		src.m_left = 0.0f;
		src.m_right = 640.0f;
		src.m_bottom = 480.0f;
	}
	if (map_flag == 13)
	{
		src.m_top = 0.0f;
		src.m_left = 0.0f;
		src.m_right = 640.0f;
		src.m_bottom = 640.0f;
	}

	//表示位置の設定
	dst.m_top = 0.0f;
	dst.m_left = 0.0f;
	dst.m_right = 800.0f;
	dst.m_bottom = 600.0f;

	//map_flagの番号に登録したグラフィックをsrc・dst・cの情報を元に描画
	Draw::Draw(map_flag, &src, &dst, c, 0.0f);
}