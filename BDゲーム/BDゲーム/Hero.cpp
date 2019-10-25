//使用ヘッダーファイル
#include"GameL\DrawTexture.h"
#include"GameL\WinInputs.h"
#include"GameL\SceneManager.h"
#include"GameL\HitBoxManager.h"

#include"GameHead.h"
#include"Hero.h"

//使用ネームスペース
using namespace GameL;

//イニシャライズ
void CObjHero::Init()
{
	m_px = 100.0f;//位置
	m_py = 0.0f;
	m_vx = 0.0f;//移動ベクトル
	m_vy = 0.0f;
	m_posture = 0.0f;//右向き0.0f 左向き1.0f

	m_ani_time = 0;
	m_ani_frame = 1;

	//blockとの衝突状態確認用
	m_hit_up = false;
	m_hit_down = false;
	m_hit_left = false;
	m_hit_right = false;

	//当たり判定用のHitBoxを作成
	Hits::SetHitBox(this, m_px, m_py, 64, 64, ELEMENT_PLAYER, OBJ_HERO, 1);
}

//アクション
void CObjHero::Action()
{
	//Spaceキーでジャンプ
	if (Input::GetVKey(' ') == true)
	{
		if (m_hit_down == true)
		{
			if(m_py>0)
			m_vy = -12;
		}
	}

	//キーの入力方向
	if (Input::GetVKey(VK_RIGHT) == true)//右
	{
		m_vx =+4.0f;
		m_posture = 0.0f;
		m_ani_time += 1;
	}

	else if (Input::GetVKey(VK_LEFT) == true)//左
	{
		m_vx =-4.0f;
		m_posture = 1.0f;
		m_ani_time += 1;
	}

	else
	{
		m_ani_frame = 0;
		m_ani_time = 0;
	}

	if (m_ani_time > 6)
	{
		m_ani_frame += 1;
		m_ani_time = 0;
	}

	

	if (m_ani_frame == 4)
	{
		m_ani_frame = 0;
	}

	//摩擦
	m_vx += -(m_vx*0.098);

	//自由落下運動
	m_vy += 5.0/(20.0f);

	//ブロックとの当たり判定実行
	CObjBlock*pb = (CObjBlock*)Objs::GetObj(OBJ_BLOCK);
	pb->BlockHit(&m_px, &m_py, true,
		&m_hit_up, &m_hit_down, &m_hit_left, &m_hit_right,
		&m_vx, &m_vy);

	//自身のHitBoxを持ってくる
	CHitBox* hit = Hits::GetHitBox(this);

	//敵と当たっているか確認
	if (hit->CheckObjNameHit(OBJ_WOLKENEMY)!=nullptr)
	{
		//主人公が敵とどの角度で当たってるか確認
		HIT_DATA** hit_data;
		hit_data = hit->SearchObjNameHit(OBJ_WOLKENEMY);

		//敵の左右に当たったら
		float r = hit_data[0]->r;
		if ((r < 45 && r >= 0) || r > 315)
		{
			m_vx = -5.0f;//左に移動
		}
		if (r > 135 && r < 225)
		{
			m_vx = +5.0f;//右に移動
		}
		if (r >= 225 && r < 315)
		{
			//敵の移動方向を主人公の位置に加算
			m_px += ((CObjWolkEnemy*)hit_data[0]->o) -> GetVx();

			CObjBlock*b=(CObjBlock*)Objs::GetObj(OBJ_BLOCK);

			if (m_vy <= -1.0f)
			{

			}
			else
			{
				m_vy = 0.0f;//ベクトルを0にする
				m_hit_down = true;//地面に当たっている判定にする
			}
		}
	}

	//位置の更新
	m_px += m_vx;
	m_py += m_vy;

	//HitBoxの位置の変更
	hit->SetPos(m_px, m_py);

	//開始位置から左に行かない処理
	if (m_px < 0)
	{
		m_px = 0;
	}

	if (m_py < 0)
	{
		m_vy += 0.5f;
	}
}

//ドロー
void CObjHero::Draw()
{
	int AniDate[4] =
	{
		1,2,3,4,
	};

	//描画カラー情報
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src;//描画元切り取り位置
	RECT_F dst;//描画先表示位置

	//切り取り位置の設定
	src.m_top = 0.0f;
	src.m_left = 0.0f + AniDate[m_ani_frame] * 64.0f+1.0f;
	src.m_right = src.m_left+64.0f-2.0f;
	src.m_bottom = 64.0f;

	//表示位置の設定
	dst.m_top = 0.0f + m_py;
	dst.m_left = (64.0*m_posture) + m_px;
	dst.m_right = (64-64.0f*m_posture) + m_px;
	dst.m_bottom = 64.0f + m_py;

	//描画
	Draw::Draw(1, &src, &dst, c, 0.0f);

}