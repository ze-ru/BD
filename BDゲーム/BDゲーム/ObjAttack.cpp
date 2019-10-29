//使用ヘッダーファイル
#include"GameL\DrawTexture.h"
#include"GameL\WinInputs.h"
#include"GameL\SceneManager.h"
#include"GameL\HitBoxManager.h"

#include"GameHead.h"
#include"ObjAttack.h"

//使用ネームスペース
using namespace GameL;

//イニシャライズ
void CObjAttack::Init()
{
	CObjHero*objh = (CObjHero*)Objs::GetObj(OBJ_HERO);

	m_px = 60.0f+objh->GetX();//位置
	m_py = 0.0f+objh->GetY();
	m_vx = 0.0f;//移動ベクトル
	m_vy = 0.0f;
	m_posture = 0.0f;//右向き0.0f 左向き1.0f

	m_ani_time = 0;
	m_ani_frame = 1;

	m_hp = 0.0f;
	m_time1 = 0;
	m_time2 = 1;

	//blockとの衝突状態確認用
	m_hit_up = false;
	m_hit_down = false;
	m_hit_left = false;
	m_hit_right = false;

	m_attack = false;
	Hits::SetHitBox(this, m_px*m_time2, m_py, 32, 64, ELEMENT_ATTACK, OBJ_HERO, 1);
}

//アクション
void CObjAttack::Action()
{
	m_time1++;
	if (m_px > 0)
	{
		m_time2 = 1;
	}
	else
	{
		m_time2 = -1;
	}
	
	//自身のHitBoxを持ってくる
	CHitBox* hit = Hits::GetHitBox(this);

	//敵と当たっているか確認
	if (hit->CheckObjNameHit(OBJ_WOLKENEMY) != nullptr)
	{
		//主人公が敵とどの角度で当たってるか確認
		HIT_DATA** hit_data;
		hit_data = hit->SearchObjNameHit(OBJ_WOLKENEMY);
	}
	if (hit->CheckObjNameHit(OBJ_LOCKENEMY) != nullptr)
	{
		HIT_DATA** hit_data;
		hit_data = hit->SearchObjNameHit(OBJ_LOCKENEMY);
	}
	if (hit->CheckObjNameHit(OBJ_NORMAL_BULLET) != nullptr)
	{

		HIT_DATA** hit_data;
		hit_data = hit->SearchObjNameHit(OBJ_NORMAL_BULLET);
		
	}

	//位置の更新
	m_px += m_vx;
	m_py += m_vy;

	//HitBoxの位置の変更
	hit->SetPos(m_px, m_py);


	if (m_time1 > 5)
	{
		this->SetStatus(false);//自身に削除命令を出す
		Hits::DeleteHitBox(this);//保有するHitBoxに削除する
	}
}

//ドロー
void CObjAttack::Draw()
{
	

	//描画カラー情報
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src;//描画元切り取り位置
	RECT_F dst;//描画先表示位置
	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 32.0f;
	src.m_bottom = 32.0f;

	dst.m_top = 0.0f + m_py;
	dst.m_left = (32.0*m_posture) + m_px*m_time2;
	dst.m_right = (32 - 32.0f*m_posture) + m_px*m_time2;
	dst.m_bottom = 32.0f + m_py;

	//描画
	Draw::Draw(1, &src, &dst, c, 0.0f);
}