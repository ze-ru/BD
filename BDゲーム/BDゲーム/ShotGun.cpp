#include"GameL\DrawTexture.h"
#include"GameL\WinInputs.h"
#include"GameL\SceneManager.h"
#include"GameL\HitBoxManager.h"

#include"GameHead.h"
#include"ShotGun.h"
#include"GameL\Audio.h"
#include<math.h>

using namespace GameL;

CObjShotBullet::CObjShotBullet(float x, float y,int r)
{
	m_px = x;//X座標の場所
	m_py = y;//Y座標の場所
	r_rad = r;//角度
}
void CObjShotBullet::Init()
{

	m_vx = cosf(3.14 / 180 * r_rad);//cosの角度を計算
	m_vy = sinf(3.14 / 180 * r_rad);//sinの角度を計算
	UnitVec(&m_vx, &m_vy);//正規化
	m_time = 0;//時間の初期化

	m_hit_up = false;//上の当たり判定
	m_hit_down = false;//下の当たり判定
	m_hit_left = false;//左の当たり判定
	m_hit_right = false;//右の当たり判定
	m_count = 0;//弾の数をカウント
	m_v = 1.0f;//弾の速度
	dm = 3;//ダメージ値
	Audio::Start(7);
	Hits::SetHitBox(this, m_px, m_py, 24, 16, ELEMENT_ENEMY_BULLET, OBJ_SHOT_BULLET, 1);//ヒットボックス作成
}
void CObjShotBullet::Action()
{
	m_time++;
	CObjBlock*block = (CObjBlock*)Objs::GetObj(OBJ_BLOCK);//ブロックの情報を取得
	CObjHero*objh = (CObjHero*)Objs::GetObj(OBJ_HERO);//主人子の情報を取得
	CHitBox*hit = Hits::GetHitBox(this);//ヒットボックスの情報を取得

	//位置の更新
	m_px += m_vx * m_v;
	m_py += m_vy * m_v;

	//ヒットボックスの位置更新
	hit->SetPos(m_px + block->GetScroll(), m_py);

	if (m_time > 50)
	{
		this->SetStatus(false);//自身に削除命令を出す
		Hits::DeleteHitBox(this);//保有するHitBoxに削除する
	}
	//ブロックとの当たり判定
	block->BulletHit(&m_px, &m_py, false, &m_hit_up, &m_hit_down,
		&m_hit_left, &m_hit_right);

	//主人公に弾が当たった場合弾を消す
	if (m_hit_up == true || m_hit_down == true || m_hit_left == true || m_hit_right == true)
	{
		Audio::Stop(7);
		this->SetStatus(false);//自身に削除命令を出す
		Hits::DeleteHitBox(this);//保有するHitBoxに削除する
	}

	//主人公に弾が当たった場合、主人公にダメージを与える
	if (hit->CheckElementHit(ELEMENT_PLAYER) == true)
	{
		if (objh->GetYflag() == false)
			objh->SetDamege(dm);
		if (objh->GetX() + 32 - block->GetScroll() > m_px)
			objh->SetHitflag(true);
		if (objh->GetX() + 32 - block->GetScroll() < m_px)
			objh->SetHitflag(false);
		Audio::Start(13);
		Audio::Stop(7);
		this->SetStatus(false);//自身に削除命令を出す
		Hits::DeleteHitBox(this);//保有するHitBoxに削除する
		Audio::Stop(13);
	}

}
void CObjShotBullet::Draw()
{
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src;
	RECT_F dst;

	src.m_top = 0.0f;
	src.m_left = 88.0f;
	src.m_right = 112.0f;
	src.m_bottom = 16.0f;


	CObjBlock*block = (CObjBlock*)Objs::GetObj(OBJ_BLOCK);
	//
	dst.m_top = m_py + 4.0f;
	dst.m_left = m_px + block->GetScroll();
	dst.m_right = dst.m_left + 24.0f;
	dst.m_bottom = 20.0f + m_py;


	//
	Draw::Draw(4, &src, &dst, c, 0.0f);
}