//使用ヘッダーファイル
#include"GameL\DrawTexture.h"
#include"GameL\WinInputs.h"
#include"GameL\SceneManager.h"
#include"GameL\HitBoxManager.h"

#include"damege.h"
#include"Hero.h"
#include"GameHead.h"

//使用ネームスペース
using namespace GameL;

//コンストラクタ
CObjDamege::CObjDamege(int dm, float x, float y)
{
	dam = dm;
	m_px = x;
	m_py = y;
}

//イニシャライズ
void CObjDamege::Init()
{
	size = 0;
	hit_time = 0;

	//当たり判定
	Hits::SetHitBox(this, m_px, m_py, 0, 0, ELEMENT_BLUE, OBJ_DAMEGE, 1);
}

//アクション
void CObjDamege::Action()
{

}

//ドロー
void CObjDamege::Draw()
{	
	//オブジェクト情報を取得
	CObjBlock*pb = (CObjBlock*)Objs::GetObj(OBJ_BLOCK);//ブロックオブジェクト情報取得

	//敵にダメージを与えたらダメージを表示する
	//描画カラー情報
	float c[4] = { 1.0f,0.0f,0.0f,1.0f };
	
	size++;
	hit_time++;

	//ダメージ表示
	wchar_t str2[50];
	if (hit_time < 50)
	{
		swprintf_s(str2, L"%d", dam);
		Font::StrDraw(str2, m_px + pb->GetScroll() - 20.0f, m_py - size, 25, c);//フォント設定
	}
	if (hit_time > 50)
	{
		this->SetStatus(false);//自身に削除命令を出す
		Hits::DeleteHitBox(this);//保有するHitBoxに削除する
	}
}