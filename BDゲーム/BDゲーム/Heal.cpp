//使用するヘッダーファイル
#include"GameL\WinInputs.h"
#include"GameL\SceneManager.h"
#include"GameL\DrawFont.h"
#include"GameL\HitBoxManager.h"

#include"Heal.h"
#include"GameL\UserData.h"

#include"GameHead.h"

//使用するネームスペース
using namespace GameL;

//コンストラクタ
CObjHeal::CObjHeal(float x, float y)
{
	m_px = x;//位置X
	m_py = y;//位置Y
}

//イニシャライズ
void CObjHeal::Init()
{
	//主人公のHPを20回復させる
	hp = 20;
	
	//当たり判定用HitBoxを作成
	Hits::SetHitBox(this, m_px, m_py, 64, 64, ELEMENT_RED, OBJ_HEAL, 1);
}

//アクション
void CObjHeal::Action()
{
	//オブジェクト情報を取得
	CObjBlock*pb = (CObjBlock*)Objs::GetObj(OBJ_BLOCK);//ブロックオブジェクト情報取得
	CObjHero*hero = (CObjHero*)Objs::GetObj(OBJ_HERO);//主人公オブジェクト情報取得

	//HitBoxの内容を更新
	CHitBox* hit = Hits::GetHitBox(this);//作成したHitBox更新用の入り口を取り出す	
	//主人公と接触したらHPを回復、HealBlock削除
	if (hit->CheckElementHit(ELEMENT_PLAYER) == true)
	{
		hero->SetHP(hp);//主人公のHPを回復
		this->SetStatus(false);//自身に削除命令を出す
		Hits::DeleteHitBox(this);//保有するHitBoxに削除する
	}
	hit->SetPos(m_px + pb->GetScroll(), m_py);//入り口から新しい位置情報に置き換える
}

//ドロー
void CObjHeal::Draw()
{
	//描画カラー情報
	float c[4] = { 1,1,1,1 };
	
	RECT_F src;//描画元切り取り位置
	RECT_F dst;//描画先表示位置

	//切り取り位置の設定
	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 64.0f;
	src.m_bottom = 64.0f;

	//ブロック情報を持ってくる
	CObjBlock*block = (CObjBlock*)Objs::GetObj(OBJ_BLOCK);
		
	//表示位置の設定
	dst.m_top = m_py;
	dst.m_left = m_px + block->GetScroll();
	dst.m_right = dst.m_left + 64.0f;
	dst.m_bottom = 64.0f + m_py;

	//描画
	Draw::Draw(21, &src, &dst, c, 0.0f);	
}