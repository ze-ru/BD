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

	if(objh->GetFlag()==false)
		m_posture = 0.0f;//右向き0.0f 左向き1.0f
	if (objh->GetFlag() == true)
		m_posture = 1.0f;//右向き0.0f 左向き1.0f
	m_px = objh->GetX()-32.0f+96.0f-96.0f*m_posture;
	m_py = objh->GetY();
	m_vx = objh->GetVX();//移動ベクトル
	m_vy = objh->GetVY();
	
	
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
	dm = 15;
	hit_flag = false;

	m_attack = false;
	Hits::SetHitBox(this, m_px+m_vx, m_py+m_vy, 32, 63, ELEMENT_ATTACK, OBJ_HERO, 1);

}

//アクション
void CObjAttack::Action()
{
	//自身のHitBoxを持ってくる
	CHitBox* hit = Hits::GetHitBox(this);

	

	//敵と当たっているか確認
	
	
	if (hit->CheckObjNameHit(OBJ_WOLKENEMY) != nullptr&&hit_flag==false)
	{
		hit_flag = true;
		CObjWolkEnemy*we = (CObjWolkEnemy*)Objs::GetObj(OBJ_WOLKENEMY);
		we->SetDamege(dm);
		
		CObjDamege*dm = new CObjDamege(15,we->GetX(), we->GetY());
		Objs::InsertObj(dm, OBJ_DAMEGE, 20);
	}
	if (hit->CheckObjNameHit(OBJ_LOCKENEMY) != nullptr&&hit_flag == false)
	{
		hit_flag = true;
		CObjLockEnemy*le = (CObjLockEnemy*)Objs::GetObj(OBJ_LOCKENEMY);
		le->SetDamege(dm);
		CObjDamege*dm = new CObjDamege(15, le->GetX(), le->GetY());
		Objs::InsertObj(dm, OBJ_DAMEGE, 20);
	}
	if (hit->CheckObjNameHit(OBJ_FLYENEMY) != nullptr&&hit_flag == false)
	{
		hit_flag = true;
		CObjFlyEnemy*fe = (CObjFlyEnemy*)Objs::GetObj(OBJ_FLYENEMY);
		fe->SetDamege(dm);
		CObjDamege*dm = new CObjDamege(15, fe->GetX(), fe->GetY());
		Objs::InsertObj(dm, OBJ_DAMEGE, 20);
	}
	if (hit->CheckObjNameHit(OBJ_BOSS1) != nullptr&&hit_flag == false)
	{
		hit_flag = true;
		CObjBoss1*b1 = (CObjBoss1*)Objs::GetObj(OBJ_BOSS1);
		b1->SetDamege(dm);
		CObjDamege*dm = new CObjDamege(15, b1->GetX(), b1->GetY());
		Objs::InsertObj(dm, OBJ_DAMEGE, 20);
	}
	if (hit->CheckObjNameHit(OBJ_BOSS2) != nullptr&&hit_flag == false)
	{
		hit_flag = true;
		CObjBoss2*b2 = (CObjBoss2*)Objs::GetObj(OBJ_BOSS2);
		b2->SetDamege(dm);
		CObjDamege*dm = new CObjDamege(15, b2->GetX(), b2->GetY());
		Objs::InsertObj(dm, OBJ_DAMEGE, 20);
	}
	//HitBoxの位置の変更
	hit->SetPos(m_px, m_py);
		m_time1++;
	if (m_time1==8)
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
	src.m_left = 64.0f*7.0f;
	src.m_right = src.m_left+32.0f;
	src.m_bottom = m_time1*8;

	dst.m_top = 0.0f + m_py;
	dst.m_left = 32.0f*m_posture+ m_px;
	dst.m_right = 32.0f-32.0f*m_posture+m_px;
	dst.m_bottom = m_time1*8 + m_py;

	//描画
	Draw::Draw(2, &src, &dst, c, 0.0f);
}