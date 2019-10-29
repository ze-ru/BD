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
	m_py = 550.0f;
	m_vx = 0.0f;//移動ベクトル
	m_vy = 0.0f;
	m_posture = 0.0f;//右向き0.0f 左向き1.0f

	m_ani_time = 0;
	m_ani_frame = 1;

	m_hp = 0.0f;
	m_time1 = 0;
	m_time2 = 0;

	flag = false;//false=右向き true=左向き

	//blockとの衝突状態確認用
	m_hit_up = false;
	m_hit_down = false;
	m_hit_left = false;
	m_hit_right = false;

	m_attack = false;

	//当たり判定用のHitBoxを作成
	Hits::SetHitBox(this, m_px, m_py, 48, 64, ELEMENT_PLAYER, OBJ_HERO, 1);
}

//アクション
void CObjHero::Action()
{
	m_time1++;
	if (m_time1 > 5)
	{
		m_attack = true;
		m_time1 = 0;
	}

	if (m_attack == true)
	{
		if (Input::GetVKey('X'))
		{
			m_time2 += 1;
			CObjAttack*objat = (CObjAttack*)Objs::GetObj(OBJ_ATTACK);
			CObjAttack*obja = new CObjAttack(m_px, m_py);
			Objs::InsertObj(obja, OBJ_ATTACK, 10);
		}
		
		if (m_time2 >=1)
		{
			m_attack = false;
			m_time2 = 0;
		}
	}
	
	//落下時
	if (m_py > 1000.0f)
	{
		;
	}

	//Spaceキーでジャンプ
	if (Input::GetVKey(' ') == true)
	{
		if (m_hit_down == true)
		{
			if(m_vy>=0)
			m_vy = -12;
			
		}
	}
	
	

	//キーの入力方向
	if (Input::GetVKey(VK_RIGHT) == true)//右
	{
		m_vx =+4.0f;
		m_posture = 0.0f;
		m_ani_time += 1;

		flag = false;
	}

	else if (Input::GetVKey(VK_LEFT) == true)//左
	{
		m_vx =-4.0f;
		m_posture = 1.0f;
		m_ani_time += 1;

		flag = true;
	}

	

	if (Input::GetVKey(VK_LEFT) == false && Input::GetVKey(VK_RIGHT) == false && m_hit_down == true)
	{
		m_ani_time++;
		if (m_ani_time < 40)
		{
			m_ani_frame = 0;
		}
		if (m_ani_time > 80)
		{
			m_ani_frame = 1;
		}
		if (m_ani_time > 120)
		{
			m_ani_time = 0;
		}
	}
	if (Input::GetVKey(VK_LEFT) == true || Input::GetVKey(VK_RIGHT) == true)
	{
		if (m_ani_time>6)
		{
			m_ani_frame += 1;
			m_ani_time = 0;
		}
		
	}
	
	
	if (m_ani_frame == 5)
	{
		m_ani_frame = 2;
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
		

		for (int i = 0; i < hit->GetCount(); i++)
		{

			//敵の左右に当たったら
			float r = hit_data[i]->r;
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
				m_px += ((CObjWolkEnemy*)hit_data[i]->o)->GetVx();

				CObjBlock*b = (CObjBlock*)Objs::GetObj(OBJ_BLOCK);

				//後方スクロールライン
				if (m_px < 80)
				{
					m_px = 80;//主人公はラインを超えないようにする
					b->SetScroll(b->GetScroll() - 5.0);
				}

				//前方スクロールライン
				if (m_px > 300)
				{
					m_px = 300;
					b->SetScroll(b->GetScroll() - 5.0);
				}

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

		
	}
	if (hit->CheckObjNameHit(OBJ_LOCKENEMY) != nullptr)
	{
		HIT_DATA** hit_data;
		hit_data = hit->SearchObjNameHit(OBJ_LOCKENEMY);
	

		for (int i = 0; i < hit->GetCount(); i++)
		{

			//敵の左右に当たったら
			float r = hit_data[i]->r;
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
			

				CObjBlock*b = (CObjBlock*)Objs::GetObj(OBJ_BLOCK);

				//後方スクロールライン
				if (m_px < 80)
				{
					m_px = 80;//主人公はラインを超えないようにする
					b->SetScroll(b->GetScroll() - 5.0);
				}

				//前方スクロールライン
				if (m_px > 300)
				{
					m_px = 300;
					b->SetScroll(b->GetScroll() - 5.0);
				}

				if (m_vy <= -1.0f)
				{
					;
				}
				else
				{
					m_vy = 0.0f;//ベクトルを0にする
					m_hit_down = true;//地面に当たっている判定にする
				}
			}
		}
		

		
		
	}
	if (hit->CheckObjNameHit(OBJ_NORMAL_BULLET) != nullptr)
	{

		HIT_DATA** hit_data;
		hit_data = hit->SearchObjNameHit(OBJ_NORMAL_BULLET);
		m_hp += 5;
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
		m_py += 0.5f;
	}

	if (m_hp == 50)
	{
		this->SetStatus(false);
		Hits::DeleteHitBox(this);

		Scene::SetScene(new CSceneGameOver());
	}
	
}

//ドロー
void CObjHero::Draw()
{
	int AniDate[7] =
	{
		0,1,2,3,4,5,6
	};

	//描画カラー情報
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src;//描画元切り取り位置
	RECT_F dst;//描画先表示位置

	//切り取り位置の設定
	
	if (m_hit_down == false && m_vy < 0)
	{
		src.m_top = 0.0f;
		src.m_left = 0.0f + 5 * 64.0f + 1.0f;
		src.m_right = 64.0f + 5 *64.0f+ 1.0f;
		src.m_bottom = 64.0f;
	}
	else if (m_hit_down == false && m_vy >=1)
	{
		src.m_top = 0.0f;
		src.m_left = 0.0f + 6 * 64.0f + 1.0f;
		src.m_right = 64.0f + 6 * 64.0f + 1.0f;
		src.m_bottom = 64.0f;
	}
	else
	{
		src.m_top = 0.0f;
		src.m_left = 0.0f + AniDate[m_ani_frame] * 64.0f + 1.0f;
		src.m_right = src.m_left + 64.0f - 2.0f;
		src.m_bottom = 64.0f;
	}


	//表示位置の設定
	dst.m_top = 0.0f + m_py;
	dst.m_left = (64.0*m_posture) + m_px;
	dst.m_right = (64-64.0f*m_posture) + m_px;
	dst.m_bottom = 64.0f + m_py;

	//描画
	Draw::Draw(1, &src, &dst, c, 0.0f);

	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 128.0f;
	src.m_bottom = 24.0f;


	//表示位置の設定
	dst.m_top = 0.0f;
	dst.m_left = 0.0f;
	dst.m_right = 256.0f;
	dst.m_bottom = 48.0f;



	//描画
	Draw::Draw(5, &src, &dst, c, 0.0f);

	src.m_top = 2.0f;
	src.m_left = 128.0f;
	src.m_right = 129.0f;
	src.m_bottom = 22.0f;


	dst.m_top = 4.0f;
	dst.m_left = 4.0f;
	dst.m_right = 256.0f - m_hp*5.0f;
	dst.m_bottom = 44.0f;

	Draw::Draw(5, &src, &dst, c, 0.0f);

}