//使用ヘッダーファイル
#include"GameL\DrawTexture.h"
#include"GameL\WinInputs.h"
#include"GameL\SceneManager.h"
#include"GameL\HitBoxManager.h"

#include"GameHead.h"
#include"ObjAttack.h"

//使用ネームスペース
using namespace GameL;


CObjAttack::CObjAttack(float x, float y)
{
	m_px = x;
	m_py = y;
}
//イニシャライズ
void CObjAttack::Init()
{
	CObjHero*objh = (CObjHero*)Objs::GetObj(OBJ_HERO);

	m_px = objh->GetX() + 64.0f;
	m_py = objh->GetY();
	m_vx = objh->GetVX();//移動ベクトル
	m_vy = objh->GetVY();
	m_posture = 0.0f;//右向き0.0f 左向き1.0f
	
	m_ani_time = 0;
	m_ani_frame = 1;

	m_hp = 0.0f;
	m_time1 = 0;
	m_time2 = 1;
	flag = false;
	//blockとの衝突状態確認用
	m_hit_up = false;
	m_hit_down = false;
	m_hit_left = false;
	m_hit_right = false;

	m_attack = false;
	Hits::SetHitBox(this, m_px+m_vx,m_py+m_vy, 32, 64, ELEMENT_ATTACK, OBJ_HERO, 1);
}

//アクション
void CObjAttack::Action()
{
	CObjHero*objh = (CObjHero*)Objs::GetObj(OBJ_HERO);
	
	
	m_time1++;

	if (objh->GetFlag(flag) == false)
	{
		m_time2 = 1;
	}
	if (objh->GetFlag(flag) == true)
	{
		m_time2 = -1;
	}

	m_vx = objh->GetVX();
	
	//自身のHitBoxを持ってくる
	CHitBox* hit = Hits::GetHitBox(this);

	//敵と当たっているか確認
	if (hit->CheckObjNameHit(OBJ_WOLKENEMY) != nullptr)
	{
		//主人公が敵とどの角度で当たってるか確認
		
		this->SetStatus(false);//自身に削除命令を出す
		Hits::DeleteHitBox(this);//保有するHitBoxに削除する
	}
	if (hit->CheckObjNameHit(OBJ_LOCKENEMY) != nullptr)
	{
		
		this->SetStatus(false);//自身に削除命令を出す
		Hits::DeleteHitBox(this);//保有するHitBoxに削除する
	}
	if (hit->CheckObjNameHit(OBJ_NORMAL_BULLET) != nullptr)
	{
		this->SetStatus(false);//自身に削除命令を出す
		Hits::DeleteHitBox(this);//保有するHitBoxに削除する
	}

	//位置の更新
	m_px +=(m_time2*m_vx);
	m_py = objh->GetY();

	//HitBoxの位置の変更
	hit->SetPos(m_px, m_py);

	if (m_time1 == 8)
	{

	}
	
	if (m_time1== 8)
	{
		this->SetStatus(false);//自身に削除命令を出す
		Hits::DeleteHitBox(this);//保有するHitBoxに削除する
		m_time1 = 0;
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
	src.m_left = 64.0f*7.0f;
	src.m_right = src.m_left+64.0f;
	src.m_bottom = m_time1*8;

	dst.m_top = 0.0f + m_py;
	dst.m_left = 32.0f-32.0f* m_time2 + m_px * m_time2;
	dst.m_right = 32.0f + 32.0f* m_time2 +m_px * m_time2;
	dst.m_bottom = m_time1*8 + m_py;

	//描画
	Draw::Draw(1, &src, &dst, c, 0.0f);
}