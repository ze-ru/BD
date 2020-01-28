//使用するヘッダーファイル
#include"GameL\DrawTexture.h"
#include"GameL\WinInputs.h"
#include"GameL\SceneManager.h"
#include"GameL\HitBoxManager.h"

#include"GameHead.h"
#include"Assault.h"

using namespace GameL;
//コンストラクタ
CObjAssault::CObjAssault(float x, float y)
{
	m_px = x;
	m_py = y;
}
//イニシャライズ
void CObjAssault::Init()
{
	//HitBox作成
	Hits::SetHitBox(this, m_px, m_py, 64, 64, ELEMENT_ASSAULT, OBJ_ASSAULT, 1);
}
//アクション
void CObjAssault::Action()
{
	CHitBox* hit = Hits::GetHitBox(this);//HitBox情報を持ってくる
	CObjBlock*pb = (CObjBlock*)Objs::GetObj(OBJ_BLOCK);//ブロック情報を持ってくる

	//プレイヤーとの当たり判定
	if (hit->CheckElementHit(ELEMENT_PLAYER) == true)
	{
		if (Input::GetVKey(VK_UP) == true)
		{
			CObjHero*h = (CObjHero*)Objs::GetObj(OBJ_HERO);//主人公情報を持ってくる
			if (h->GetWeapon() == 1)
				h->Setbulletnums(30);//同じ武器番号の時弾丸を増やす
			else
				h->Setbulletnum(30);//異なる武器番号の時弾丸を３０発にする
			h->SetWeapon(1);
			
			this->SetStatus(false);//自身に削除命令を出す
			Hits::DeleteHitBox(this);//保有するHitBoxに削除する
		}
	}
	//HitBox更新
	hit->SetPos(m_px + pb->GetScroll(), m_py);
}
//ドロー
void CObjAssault::Draw()
{
	//色情報　RED　GREEN　BULE　alpha(透過情報）
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src;//描画元切り取り位置
	RECT_F dst;//描画先表示位置

	//描画元切り取り位置
	src.m_top = 0.0f;
	src.m_left = 192.0f;
	src.m_right = 256.0f;
	src.m_bottom = 64.0f;


	CObjBlock*block = (CObjBlock*)Objs::GetObj(OBJ_BLOCK);
	//描画先表示位置
	dst.m_top = m_py;
	dst.m_left = m_px + block->GetScroll();
	dst.m_right = dst.m_left+64.0f;
	dst.m_bottom = 64.0f + m_py;


	//描画
	Draw::Draw(19, &src, &dst, c, 0.0f);
}
