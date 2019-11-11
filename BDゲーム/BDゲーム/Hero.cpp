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
	hit_flag = true;
	m_attack = false;
	m_dead = 0.0f;
	m_y_flag = false;
	m_y_num = 0;
	m_dead_flag = false;
	//当たり判定用のHitBoxを作成
	Hits::SetHitBox(this, m_px, m_py, 64, 64, ELEMENT_PLAYER, OBJ_HERO, 1);
}

//アクション
void CObjHero::Action()
{
	//ブロックとの当たり判定実行
	CObjBlock*pb = (CObjBlock*)Objs::GetObj(OBJ_BLOCK);
	CObjBlock2*pb2 = (CObjBlock2*)Objs::GetObj(OBJ_BLOCK2);
	if (pb->Getmap1() == 0)
	{
		pb->BlockHit(&m_px, &m_py, true,
			&m_hit_up, &m_hit_down, &m_hit_left, &m_hit_right,
			&m_vx, &m_vy);
	}
	if (pb2->Getmap2() == 0)
	{
		pb2->BlockHit2(&m_px, &m_py, true,
			&m_hit_up, &m_hit_down, &m_hit_left, &m_hit_right,
			&m_vx, &m_vy);
	}
	if (m_y_num >= 50&&m_y_flag==false)
	{
		if (m_y_num < 100)
		{
			m_y_num = 50;
		}
		m_vx = 2.0f*m_posture;
		m_y_flag = true;
	}
	if (m_dead_flag == true)
	{
		if (m_hp >= 50)
		{
			m_time2++;
			if (m_time2 > 10 && m_time2 < 20)
			{
				m_dead += 1.0f;
			}
			if (m_time2 > 50)
			{
				this->SetStatus(false);
				Hits::DeleteHitBox(this);

				Scene::SetScene(new CSceneGameOver());

			}
		}
	}
	if (m_dead_flag == false)
	{
		CHitBox* hit = Hits::GetHitBox(this);
		if (m_y_flag==true)
		{
			
			m_y_num--;
			
			//自由落下運動

			m_vy += 5.0 / (20.0f);
			
			
			if (m_y_num >40) {
				if (m_posture == 0.0f)
					m_vx -= 0.2f;
				if (m_posture == 1.0f)
					m_vx += 0.2f;
			}

			

		

			m_px += m_vx;
			m_py += m_vy;
			//HitBoxの位置の変更
			hit->SetPos(m_px, m_py);

			
			if (m_y_num < 0)
			{
				m_y_num = 0;
				m_y_flag = false;
			}

		}
		if (m_y_flag == false)
		{

			if (m_attack == true)
			{
				if (Input::GetVKey('X'))
				{
					CObjAttack*obja = new CObjAttack(m_px, m_py);
					Objs::InsertObj(obja, OBJ_ATTACK, 10);
					m_attack = false;
				}
			}
			if (m_attack == false)
			{
				m_time1++;
				if (m_time1 > 30)
				{
					m_time1 = 0;
					m_attack = true;
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
				if (m_hit_down == true || (hit->CheckElementHit(ELEMENT_ENEMY)==true))
				{
					if (m_vy >= 0)
						m_vy = -10.5;

				}
			}



			//キーの入力方向
			if (Input::GetVKey(VK_RIGHT) == true)//右
			{
				m_vx = +4.0f;
				m_posture = 0.0f;
				m_ani_time += 1;

				flag = false;
			}

			else if (Input::GetVKey(VK_LEFT) == true)//左
			{
				m_vx = -4.0f;
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
				if (m_ani_time > 6)
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
			m_vy += 5.0 / (20.0f);

			//ブロックとの当たり判定実行
			

			//自身のHitBoxを持ってくる


			//敵と当たっているか確認
			if (hit->CheckObjNameHit(OBJ_WOLKENEMY) != nullptr)
			{
				//主人公が敵とどの角度で当たってるか確認
				HIT_DATA** hit_data;

				if (hit_flag == true)
				{
					hit_data = hit->SearchObjNameHit(OBJ_WOLKENEMY);
					hit_flag = false;

					for (int i = 0; i < hit->GetCount(); i++)
					{

						//敵の左右に当たったら
						if (hit_data[i] != NULL)
						{
							float r = hit_data[i]->r;
							if ((r < 45 && r >= 0) || r > 315)
							{
								m_vx = -1.2f;//左に移動
							}
							if (r > 135 && r < 225)
							{
								m_vx = +1.2f;//右に移動
							}
							if (r >= 225 && r < 315)
							{
								//敵の移動方向を主人公の位置に加算
								m_px += ((CObjWolkEnemy*)hit_data[i]->o)->GetVx();
								
								
								//後方スクロールライン
								if (m_px < 80)
								{
									if (pb->Getmap1() == 0)
										pb->SetScroll(pb->GetScroll() - 5.0);
									if (pb2->Getmap2() == 0)
										pb2->SetScroll(pb2->GetScroll() - 5.0);
								}

								//前方スクロールライン
								if (m_px > 300)
								{
									m_px = 300;
									if (pb->Getmap1() == 0)
									pb->SetScroll(pb->GetScroll() - 5.0);
									if (pb2->Getmap2() == 0)
										pb2->SetScroll(pb2->GetScroll() - 5.0);
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
				}
				if (hit_flag == false)
					hit_flag = true;

			}
			if (hit->CheckObjNameHit(OBJ_LOCKENEMY) != nullptr)
			{
				HIT_DATA** hit_data;
				if (hit_flag == true)
				{
					hit_data = hit->SearchObjNameHit(OBJ_LOCKENEMY);
					hit_flag = false;


					for (int i = 0; i < hit->GetCount(); i++)
					{

						//敵の左右に当たったら
						if (hit_data[i] != NULL)
						{
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
								
								
								//後方スクロールライン
								if (m_px < 80)
								{
									
									if (pb->Getmap1() == 0)
										pb->SetScroll(pb->GetScroll() - 5.0);
									if (pb2->Getmap2() == 0)
										pb2->SetScroll(pb2->GetScroll() - 5.0);
									
								}

								//前方スクロールライン
								if (m_px > 300)
								{
									m_px = 300;
									if (pb->Getmap1() == 0)
										pb->SetScroll(pb->GetScroll() - 5.0);
									if (pb2->Getmap2() == 0)
										pb2->SetScroll(pb2->GetScroll() - 5.0);
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
				}
				if (hit_flag == false)
					hit_flag = true;
			}
			if (hit->CheckObjNameHit(OBJ_FLYENEMY) != nullptr)
			{
				HIT_DATA** hit_data;
				if (hit_flag == true)
				{
					hit_data = hit->SearchObjNameHit(OBJ_FLYENEMY);
					hit_flag = false;


					for (int i = 0; i < hit->GetCount(); i++)
					{

						//敵の左右に当たったら
						if (hit_data[i] != NULL)
						{
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

								

								//後方スクロールライン
								if (m_px < 80)
								{
									if (pb->Getmap1() == 0)
										pb->SetScroll(pb->GetScroll() - 5.0);
									if (pb2->Getmap2() == 0)
										pb2->SetScroll(pb2->GetScroll() - 5.0);
								}

								//前方スクロールライン
								if (m_px > 300)
								{
									m_px = 300;
									if (pb->Getmap1() == 0)
										pb->SetScroll(pb->GetScroll() - 5.0);
									if (pb2->Getmap2() == 0)
										pb2->SetScroll(pb2->GetScroll() - 5.0);
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
				}
				if (hit_flag == false)
					hit_flag = true;
			}
			if (hit->CheckObjNameHit(OBJ_NORMAL_BULLET) != nullptr)
			{
				HIT_DATA** hit_data;
				hit_data = hit->SearchObjNameHit(OBJ_NORMAL_BULLET);
				m_hp += 5;
				m_y_num += 50;
			}
			if (hit->CheckObjNameHit(OBJ_ASSAULT_BULLET) != nullptr)
			{
				HIT_DATA** hit_data;
				hit_data = hit->SearchObjNameHit(OBJ_ASSAULT_BULLET);
				m_hp += 2;
				m_y_num += 10;
			}

			//位置の更新
			m_px += m_vx;
			m_py += m_vy;


			//HitBoxの位置の変更
			hit->SetPos(m_px, m_py);


			if (m_py < 0)
			{
				m_py += 0.5f;
			}
			if (m_hp >= 50)
			{
				m_dead_flag = true;
			}

		}
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
	
	if (m_hit_down == false && m_vy < 1)
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
	Draw::Draw(1, &src, &dst, c, m_dead);

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

