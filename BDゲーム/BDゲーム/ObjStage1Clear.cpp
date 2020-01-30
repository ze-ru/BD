//使用するヘッダーファイル
#include"GameL\WinInputs.h"
#include"GameL\SceneManager.h"
#include"GameL\DrawFont.h"

#include"ObjStage1Clear.h"
#include"GameL\UserData.h"

#include"GameHead.h"

//使用するネームスペース
using namespace GameL;

//イニシャライズ
void CObjStage1Clear::Init()
{
	key = false;//キーフラグ
	score = 0;
	deadflag = false;//BOSS撃破フラグ
}

//アクション
void CObjStage1Clear::Action()
{	
	//Bossが死んだらSTAGE CLEAR
	if (deadflag == true)
	{
		key = true;
	}	
}

//ドロー
void CObjStage1Clear::Draw()
{
	//描画カラー情報
	float c[4] = { 1,1,1,1 };
	
	//Bossが死んだらSTAGE CLEARとクリア時のSCOREをゲーム画面に表示
	if (key == true)
	{
		RECT_F src;//描画元切り取り位置
		RECT_F dst;//描画先表示位置
		
		//切り取り位置の設定
		src.m_top = 0.0f;
		src.m_left = 0.0f;
		src.m_right = 800.0f;
		src.m_bottom = 600.0f;

		//ステージクリアオブジェクト作成
		CObjBlock*pb = (CObjBlock*)Objs::GetObj(OBJ_BLOCK);//ブロックオブジェクト登録
		CObjHero*h = (CObjHero*)Objs::GetObj(OBJ_HERO);//主人公オブジェクト登録

		//表示位置の設定
		dst.m_top = 0.0f;
		dst.m_left = 64.0f*288 + pb->GetScroll();
		dst.m_right = dst.m_left+800.0f;
		dst.m_bottom = 600.0f;
		
		//17番目に登録したグラフィックをsrc・dst・cの情報を元に描画
		Draw::Draw(17, &src, &dst, c, 1.0f);
		
		//クリア時のSCOREを表示
		wchar_t str[50];
		swprintf_s(str, L"%d", score);

		//クリア時のSCOREのフォント設定
		Font::StrDraw(str, 64.0f * 296 +pb->GetScroll() , 380, 100, c);
	}
}