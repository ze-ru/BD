//使用するヘッダーファイル
#include"GameL\DrawTexture.h"
#include"GameL\WinInputs.h"
#include"GameL\SceneManager.h"
#include"GameL\HitBoxManager.h"

#include"GameHead.h"
#include"AssaultBullet.h"
#include"GameL\Audio.h"

using namespace GameL;
//コンストラクタ
CObjAssaultBullet::CObjAssaultBullet(float x, float y)
{
	m_px = x;//位置X
	m_py = y;//位置Y
}
//イニシャライズ
void CObjAssaultBullet::Init()
{
	m_vx = 0.0f;//X軸の加速度
	m_vy = 0.0f;//Y軸の加速度
	m_time = 0;//弾の消去タイミング管理用

	m_hit_up = false;//当たり判定：上
	m_hit_down = false;//当たり判定：下
	m_hit_left = false;//当たり判定：左
	m_hit_right = false;//当たり判定：右
	m_count = 0;//一度だけ弾丸の方向をとるためのカウント
	dm = 2;//ダメージ数
	Audio::Start(7);//発射音
	Hits::SetHitBox(this, m_px, m_py, 24, 16, ELEMENT_ENEMY_BULLET, OBJ_ASSAULT_BULLET, 1);//当たり判定作成
}
//アクション
void CObjAssaultBullet::Action()
{

	m_time++;
	if (m_time == 5)//m_timeが５になったら発射音を止める
		Audio::Stop(7);

	CObjBlock*block = (CObjBlock*)Objs::GetObj(OBJ_BLOCK);//ブロック情報を持ってくる
	CObjHero*objh = (CObjHero*)Objs::GetObj(OBJ_HERO);//主人公の情報を持ってくる
	CHitBox*hit = Hits::GetHitBox(this);//HitBoxの情報を持ってくる

	if(m_count!=1)//一度だけ数値を足す
		m_count++;

	if (m_count == 1)//主人公の位置と比べて向きを決める
	{
		m_vx = (objh->GetX()+32 - m_px- block->GetScroll());
		m_vy = (objh->GetY() - m_py);
		m_count++;
	}

	UnitVec(&m_vx, &m_vy);//正規化

	if (hit->CheckElementHit(ELEMENT_PLAYER) == true)//主人公との当たり判定
	{
		if (objh->GetYflag() == false)//よろけ状態ではない場合
			objh->SetDamege(dm);
		if (objh->GetX() + 32 - block->GetScroll() > m_px)//弾丸より主人公の位置が左の時
			objh->SetHitflag(true);//当たっている方向を右にする
		if (objh->GetX() + 32 - block->GetScroll() < m_px)//弾丸より主人公の位置が右の時
			objh->SetHitflag(false);//当たっている方向を左にする
		Audio::Start(13);
		Audio::Stop(7);
		this->SetStatus(false);//自身に削除命令を出す
		Hits::DeleteHitBox(this);//保有するHitBoxに削除する
		Audio::Stop(13);
	}
	if (hit->CheckElementHit(ELEMENT_ATTACK) == true)//主人公の剣攻撃に当たると弾丸を削除する。
	{
		Audio::Stop(7);
		this->SetStatus(false);//自身に削除命令を出す
		Hits::DeleteHitBox(this);//保有するHitBoxに削除する
	}
	
	if (hit->CheckObjNameHit(OBJ_WOLKENEMY) != nullptr)//歩行敵に当たった時
	{
		Audio::Stop(7);
		this->SetStatus(false);//自身に削除命令を出す
		Hits::DeleteHitBox(this);//保有するHitBoxに削除する
	}
	if (hit->CheckObjNameHit(OBJ_SHIELDENEMY) != nullptr)//盾を持つ敵に当たった時
	{
		Audio::Stop(7);
		this->SetStatus(false);//自身に削除命令を出す
		Hits::DeleteHitBox(this);//保有するHitBoxに削除する
	}
	if (hit->CheckObjNameHit(OBJ_SHIELD) != nullptr)//盾に当たった時
	{
		Audio::Stop(7);
		this->SetStatus(false);//自身に削除命令を出す
		Hits::DeleteHitBox(this);//保有するHitBoxに削除する
	}
	if (hit->CheckObjNameHit(OBJ_LOCKENEMY) != nullptr)//砲台に当たった時
	{
		Audio::Stop(7);
		this->SetStatus(false);//自身に削除命令を出す
		Hits::DeleteHitBox(this);//保有するHitBoxに削除する
	}
	//位置の更新
	m_px += m_vx;
	m_py += m_vy;
	//HitBoxの更新
	hit->SetPos(m_px + block->GetScroll(), m_py);
	
	//時間経過で弾丸を削除する
	if (m_time > 150)
	{
		Audio::Stop(7);
		this->SetStatus(false);//自身に削除命令を出す
		Hits::DeleteHitBox(this);//保有するHitBoxに削除する
	}
	//ブロックとの当たり判定
	block->BulletHit(&m_px, &m_py, false, &m_hit_up, &m_hit_down,
		&m_hit_left, &m_hit_right);
	//当たっている場合
	if (m_hit_up == true || m_hit_down == true || m_hit_left == true || m_hit_right == true)
	{
		Audio::Stop(7);
		this->SetStatus(false);//自身に削除命令を出す
		Hits::DeleteHitBox(this);//保有するHitBoxに削除する
	}

}
//ドロー
void CObjAssaultBullet::Draw()
{
	//色情報　RED　GREEN　BULE　alpha(透過情報）
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src;//描画元切り取り位置
	RECT_F dst;//描画先表示位置

	//描画元切り取り位置
	src.m_top = 0.0f;
	src.m_left = 88.0f;
	src.m_right = 112.0f;
	src.m_bottom = 16.0f;


	CObjBlock*block = (CObjBlock*)Objs::GetObj(OBJ_BLOCK);//ブロックの情報を持ってくる

	//描画先表示位置
	dst.m_top = m_py + 4.0f;
	dst.m_left = m_px + block->GetScroll();
	dst.m_right = dst.m_left + 24.0f;
	dst.m_bottom = 20.0f + m_py;


	//描画
	Draw::Draw(4, &src, &dst, c, 0.0f);
}

//正規化関数
//vx :X軸の加速度
//vy :Y軸の加速度
//与えられた値を正規化する
bool UnitVec(float *vx, float *vy)
{
	float r = 0.0f;
	r = (*vx)*(*vx) + (*vy)*(*vy);
	r = sqrt(r);

	if (r == 0.0f)
	{
		return false;
	}
	else
	{
		(*vx) = 5.0f / r * (*vx);
		(*vy) = 5.0f / r * (*vy);
	}
	return true;
}