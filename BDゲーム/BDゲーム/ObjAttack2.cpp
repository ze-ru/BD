//使用ヘッダーファイル
#include"GameL\DrawTexture.h"
#include"GameL\WinInputs.h"
#include"GameL\SceneManager.h"
#include"GameL\HitBoxManager.h"

#include"GameHead.h"
#include"ObjAttack2.h"

//使用ネームスペース
using namespace GameL;


CObjAttack2::CObjAttack2(float x, float y)
{
	m_px = x;
	m_py = y;
}
//イニシャライズ
void CObjAttack2::Init()
{
	CObjHero2*objh2 = (CObjHero2*)Objs::GetObj(OBJ_HERO2);

	if (objh2->GetFlag2() == false)
		m_posture = 0.0f;//右向き0.0f 左向き1.0f
	if (objh2->GetFlag2() == true)
		m_posture = 1.0f;//右向き0.0f 左向き1.0f
	m_px = objh2->GetX2() - 32.0f + 96.0f - 96.0f*m_posture;
	m_py = objh2->GetY2();
	m_vx = objh2->GetVX2();//移動ベクトル
	m_vy = objh2->GetVY2();


	m_ani_time = 0;
	m_ani_frame = 1;

	m_hp = 0.0f;
	m_time1 = 0;
	m_time2 = 1;
	m_time3 = 0;

	//blockとの衝突状態確認用
	m_hit_up = false;
	m_hit_down = false;
	m_hit_left = false;
	m_hit_right = false;

	m_attack = false;
	Hits::SetHitBox(this, m_px + m_vx, m_py + m_vy, 32, 63, ELEMENT_ATTACK, OBJ_HERO2, 1);

}

//アクション
void CObjAttack2::Action()
{
	//自身のHitBoxを持ってくる
	CHitBox* hit = Hits::GetHitBox(this);

	//敵と当たっているか確認

	if (hit->CheckElementHit(ELEMENT_ENEMY))
	{
		this->SetStatus(false);//自身に削除命令を出す
		Hits::DeleteHitBox(this);//保有するHitBoxに削除する
	}

	//HitBoxの位置の変更
	hit->SetPos(m_px, m_py);
	m_time1++;
	if (m_time1 == 16)
	{
		this->SetStatus(false);//自身に削除命令を出す
		Hits::DeleteHitBox(this);//保有するHitBoxに削除する
	}
}

//ドロー
void CObjAttack2::Draw()
{
	//描画カラー情報
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src;//描画元切り取り位置
	RECT_F dst;//描画先表示位置
	src.m_top = 0.0f;
	src.m_left = 64.0f*7.0f;
	src.m_right = src.m_left + 32.0f;
	src.m_bottom = m_time1 * 4;

	dst.m_top = 0.0f + m_py;
	dst.m_left = 32.0f*m_posture + m_px;
	dst.m_right = 32.0f - 32.0f*m_posture + m_px;
	dst.m_bottom = m_time1 * 4 + m_py;

	//描画
	Draw::Draw(1, &src, &dst, c, 0.0f);
}