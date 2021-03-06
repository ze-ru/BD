//使用ヘッダーファイル
#include"GameL\DrawTexture.h"
#include"GameL\WinInputs.h"
#include"GameL\SceneManager.h"
#include"GameL\HitBoxManager.h"

#include"GameHead.h"
#include"Hero.h"



//使用ネームスペース
using namespace GameL;

CObjHero::CObjHero(int b, int w)
{
	wp = w;
	bullet = b;
}

//イニシャライズ
void CObjHero::Init()
{
	m_px = 100.0f;//位置
	m_py = 350.0f;
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
	bullet_count = 0;
	m_time_bullet = 0;
	
	bulletflag = true;
	m_hit_flag = false;
	m_back_flag = true;//ノックバック用フラグ

	fly = false;
	stop = false;
	wolk = false;

	shotbullet_flag = false;
	shotbullet_time = 0;

	//当たり判定用のHitBoxを作成
	Hits::SetHitBox(this, m_px, m_py, 64, 64, ELEMENT_PLAYER, OBJ_HERO, 1);
	//Hits::SetHitBox(this, m_px + 32, m_py, 32, 64, ELEMENT_PLAYER, OBJ_HERO, 2);
}

//アクション
void CObjHero::Action()
{

	/*if (Input::GetVKey('R') == true)
	{
		bullet+=100;
	}
	if (Input::GetVKey('H') == true)
	{
		m_hp -= 1;
	}*/
	if (m_hp < 0)
	{
		m_hp = 0;
	}
	
	//ブロックとの当たり判定実行
	CObjBlock*pb = (CObjBlock*)Objs::GetObj(OBJ_BLOCK);

	CHitBox* hit = Hits::GetHitBox(this);
	if (m_y_num >= 30&&m_y_flag==false)
	{

		if (hit->CheckObjNameHit(OBJ_WOLKENEMY) != nullptr)
		{
			int enemynum = 1;
			EnemyHit(enemynum);
		}
		if (hit->CheckObjNameHit(OBJ_LOCKENEMY) != nullptr)
		{
			int enemynum = 2;
			EnemyHit(enemynum);
		}
		if (hit->CheckObjNameHit(OBJ_FLYENEMY) != nullptr)
		{
			int enemynum = 3;
			EnemyHit(enemynum);
		}

		//ブロックとの当たり判定実行
		pb->BlockHit(&m_px, &m_py, true,
			&m_hit_up, &m_hit_down, &m_hit_left, &m_hit_right,
			&m_vx, &m_vy);
		
			
		//敵と当たっているか確認
	
		if (m_y_num < 40)
		{
			m_y_num = 30;
		}
		
		m_y_flag = true;
		m_back_flag = true;

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
				CObjStage1*s1 = (CObjStage1*)Objs::GetObj(OBJ_STAGE1);
				Scene::SetScene(new CSceneGameOver(s1->Getmapflag(),s1->Getmapnum()));

			}
		}
	}
	if (m_dead_flag == false)
	{
		//ブロックとの当たり判定実行
		pb->BlockHit(&m_px, &m_py, true,
			&m_hit_up, &m_hit_down, &m_hit_left, &m_hit_right,
			&m_vx, &m_vy);
		
		if (m_y_flag==true)
		{
			
			m_y_num--;
			//自由落下運動
			m_vy += 5.0 / (20.0f);

			if (m_hit_flag == false)
			{
				m_vx = -3.0f;
			}
			if (m_hit_flag == true)
			{
				m_vx = 3.0f;
			}

	
			m_px += m_vx;
			m_py += m_vy;

			//HitBoxの位置の変更
			hit->SetPos(m_px, m_py);

			if (m_y_num <= 0)
			{
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
					Objs::InsertObj(obja, OBJ_ATTACK, 50);
					m_attack = false;
					bulletflag = false;
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
			if (wp == 1)
			{
				if (Input::GetVKey('C') == true)
				{
					if (bulletflag == true)
					{


						if (bullet > 0)
						{
							m_time_bullet++;
							if (m_time_bullet > 10)
							{
								if (flag == false)
								{
									CObjHeroAssultBullet*objhBullet = new CObjHeroAssultBullet(m_px - pb->GetScroll() + 62.0f, m_py);
									Objs::InsertObj(objhBullet, OBJ_HEROASSULTBULLET, 50);
									bullet--;
								}
								if (flag == true)
								{
									CObjHeroAssultBullet*objhBullet = new CObjHeroAssultBullet(m_px - pb->GetScroll() - 2.0f, m_py);
									Objs::InsertObj(objhBullet, OBJ_HEROASSULTBULLET, 50);
									bullet--;
								}

								m_time_bullet = 0;
							}

						}
					}
				}
				else
				{
					m_time_bullet = 10;
				}
			}
			if (wp == 2)
			{
				if (Input::GetVKey('C') == true)
				{
					
					if (bullet > 0)
					{
						
						if (flag == false && bulletflag == true)
						{
							CObjHeroNormalBullet*objhnb = new CObjHeroNormalBullet(m_px - pb->GetScroll() + 62.0f, m_py);
							Objs::InsertObj(objhnb, OBJ_HERONORMALBULLET, 50);

							bullet--;
							bulletflag = false;
						}
						if (flag == true && bulletflag == true)
						{
							CObjHeroNormalBullet*objhnb = new CObjHeroNormalBullet(m_px - pb->GetScroll() - 2.0f, m_py);
							Objs::InsertObj(objhnb, OBJ_HERONORMALBULLET, 50);
							bullet--;
							bulletflag = false;
						}
					}
				}
			}
			if (wp == 3)
			{
				if (Input::GetVKey('C') == true)
				{
					if (bullet > 0)
					{
						if (flag == false && bulletflag == true)
						{
							CObjLaserBullet*objlb = new CObjLaserBullet(m_px - pb->GetScroll() + 62.0f, m_py);
							Objs::InsertObj(objlb, OBJ_LASER_BULLET, 50);
							
							bullet--;
							bulletflag = false;
						}
						if (flag == true && bulletflag == true)
						{
							CObjLaserBullet*objlb = new CObjLaserBullet(m_px - pb->GetScroll() - 96.0f, m_py);
							Objs::InsertObj(objlb, OBJ_LASER_BULLET, 50);
							bullet--;
							bulletflag = false;
						}
					}

				}
			}
			if (wp == 4)
			{
				if (Input::GetVKey('C') == true)
				{
					if (bullet > 0)
					{
						if (flag == false && shotbullet_flag == true)
						{
							for (int r = 330; r < 360; r += 30 / 3)
							{
								//角度iで角度弾丸発射
								CObjHeroShotBullet*objsb = new CObjHeroShotBullet(m_px - pb->GetScroll() + 62.0f, m_py,r);
								Objs::InsertObj(objsb, OBJ_HERO_SHOTBULLET, 50);
							}
							for (int r = 0; r < 30; r += 30 / 3)
							{
								//角度iで角度弾丸発射
								CObjHeroShotBullet*objsb = new CObjHeroShotBullet(m_px - pb->GetScroll() + 62.0f, m_py,r);
								Objs::InsertObj(objsb, OBJ_HERO_SHOTBULLET, 50);
							}
							bullet--;
							shotbullet_flag = false;
						}
						if (flag == true && shotbullet_flag == true)
						{
							for (int r = 150; r <= 210; r += 60 / 6)
							{
								CObjHeroShotBullet*objsb = new CObjHeroShotBullet(m_px - pb->GetScroll() - 10.0f, m_py,r);
								Objs::InsertObj(objsb, OBJ_HERO_SHOTBULLET, 50);
							}
							bullet--;
							shotbullet_flag = false;
							
						}
					}
				}
			}
			

			if (Input::GetVKey('C') == false)
			{
				if (Input::GetVKey('X') == false)
				{
					if (bulletflag == false)
					{
						bulletflag = true;
					}
				}
				
			}
			
			if (m_py > 1000.0f)
			{
				;
			}
			



			//キーの入力方向
			if (Input::GetVKey(VK_RIGHT) == true)//右
			{
				m_vx = +5.0f;
				m_posture = 0.0f;
				m_ani_time += 1;
				/*if (Input::GetVKey('M') == true)
				{
					m_vx = +30;
				}*/
				flag = false;
			}

			else if (Input::GetVKey(VK_LEFT) == true)//左
			{
				m_vx = -5.0f;
				m_posture = 1.0f;
				m_ani_time += 1;
				/*if (Input::GetVKey('M') == true)
				{
					m_vx = -30;
				}*/
				flag = true;
			}

			



			//摩擦
			m_vx += -(m_vx*0.098);

			//自由落下運動
			m_vy += 5.0 / (20.0f);

		
			//敵と当たっているか確認
			if (hit->CheckObjNameHit(OBJ_WOLKENEMY) != nullptr)
			{
				int enemynum = 1;
				EnemyHit(enemynum);
			}
			if (hit->CheckObjNameHit(OBJ_LOCKENEMY) != nullptr)
			{
				int enemynum = 2;
				EnemyHit(enemynum);
			}
			if (hit->CheckObjNameHit(OBJ_FLYENEMY) != nullptr)
			{
				int enemynum = 3;
				EnemyHit(enemynum);
			}
			if (hit->CheckObjNameHit(OBJ_BOSS1) != nullptr)
			{
				int enemynum = 4;
				EnemyHit(enemynum);
			}
			if (hit->CheckObjNameHit(OBJ_SHIELDENEMY) != nullptr)
			{
				int enemynum = 5;
				EnemyHit(enemynum);
			}
			if (hit->CheckObjNameHit(OBJ_SHIELD) != nullptr)
			{
				int enemynum = 6;
				EnemyHit(enemynum);
			}
			if (hit->CheckObjNameHit(OBJ_LOCKENEMY2) != nullptr)
			{
				int enemynum = 7;
				EnemyHit(enemynum);
			}
			if (hit->CheckObjNameHit(OBJ_NORMAL_BULLET) != nullptr)
			{
				HIT_DATA** hit_data;
				hit_data = hit->SearchObjNameHit(OBJ_NORMAL_BULLET);
				m_y_num +=20;
			}
			if (hit->CheckObjNameHit(OBJ_ASSAULT_BULLET) != nullptr)
			{
				HIT_DATA** hit_data;
				hit_data = hit->SearchObjNameHit(OBJ_ASSAULT_BULLET);
				m_y_num +=10 ;
			}
			if (hit->CheckObjNameHit(OBJ_SHOT_BULLET) != nullptr)
			{
				HIT_DATA** hit_data;
				hit_data = hit->SearchObjNameHit(OBJ_ASSAULT_BULLET);
				m_y_num += 10;
			}
			if (hit->CheckObjNameHit(OBJ_SHIELD) != nullptr)
			{
				HIT_DATA** hit_data;
				hit_data = hit->SearchObjNameHit(OBJ_SHIELD);
				m_y_num += 40;
			}
			
			//Spaceキーでジャンプ
			if (Input::GetVKey(' ') == true)
			{
				if (m_hit_down == true)
				{
					if (m_vy >= 0)
						m_vy = -10.5;
				}
				fly = true;
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
				stop = true;
				wolk = false;
				fly = false;
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
			//位置の更新
			m_px += m_vx;
			m_py += m_vy;
			

			//HitBoxの位置の変更
			hit->SetPos(m_px, m_py);


			if (m_py <= 0)
			{
				m_py = 0;
				m_vy = 0.0f;
			}
			if (m_hp >= 50)
			{
				m_dead_flag = true;
			}

		}
	}
	if (shotbullet_flag == false)
	{
		shotbullet_time++;
		if (shotbullet_time > 30)
		{
			shotbullet_flag = true;
			shotbullet_time = 0;
		}
	}
}

//ドロー
void CObjHero::Draw()
{
	CObjBlock*block = (CObjBlock*)Objs::GetObj(OBJ_BLOCK);
	int AniDate[7] =
	{
		0,1,2,3,4,5,6
	};

	//描画カラー情報
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };
	float c2[4] = { 1.0f,0.0f,1.0f,1.0f };

	RECT_F src;//描画元切り取り位置
	RECT_F dst;//描画先表示位置

	//切り取り位置の設定
	//剣
	src.m_top = 0.0f;
	src.m_left = 128.0f;
	src.m_right = 192.0f;
	src.m_bottom = 64.0f;

	if (Input::GetVKey('X') == true && swordcount > -25)
	{
		swordcount--;
		dst.m_top = 10.0f + m_py;
		dst.m_left = ((48.0 - 48.0f)*m_posture) + m_px + 24;
		dst.m_right = (48 - 96.0f*m_posture) + m_px + 24;
		dst.m_bottom = 58.0f + m_py;
		Draw::Draw(19, &src, &dst, c, 60 + swordcount * 4.8f);
	}
	else if (Input::GetVKey('C') == true)
	{


		if (wp == 1)
		{
			src.m_top = 0.0f;
			src.m_left = 192.0f;
			src.m_right = 256.0f;
			src.m_bottom = 64.0f;

			dst.m_top = 10.0f + m_py;
			dst.m_left = ((48.0 - 48.0f)*m_posture) + m_px + 32;
			dst.m_right = (48 - 96.0f*m_posture) + m_px + 32;
			dst.m_bottom = 58.0f + m_py;

			Draw::Draw(19, &src, &dst, c, 0.0f);
		}
		if (wp == 2)
		{
			src.m_top = 0.0f;
			src.m_left = 0.0f;
			src.m_right = 64.0f;
			src.m_bottom = 64.0f;

			dst.m_top = 10.0f + m_py;
			dst.m_left = ((48.0 - 48.0f)*m_posture) + m_px + 32;
			dst.m_right = (48 - 96.0f*m_posture) + m_px + 32;
			dst.m_bottom = 58.0f + m_py;

			Draw::Draw(19, &src, &dst, c, 0.0f);
		}
		if (wp == 3)
		{
			src.m_top = 0.0f;
			src.m_left = 64.0f;
			src.m_right = 128.0f;
			src.m_bottom = 64.0f;

			dst.m_top = 10.0f + m_py;
			dst.m_left = ((48.0 - 48.0f)*m_posture) + m_px + 32;
			dst.m_right = (48 - 96.0f*m_posture) + m_px + 32;
			dst.m_bottom = 58.0f + m_py;

			Draw::Draw(19, &src, &dst, c, 0.0f);
		}
		if (wp == 4)
		{
			src.m_top = 0.0f;
			src.m_left = 320.0f;
			src.m_right = 384.0f;
			src.m_bottom = 64.0f;

			dst.m_top = 10.0f + m_py;
			dst.m_left = ((48.0 - 48.0f)*m_posture) + m_px + 32;
			dst.m_right = (48 - 96.0f*m_posture) + m_px + 32;
			dst.m_bottom = 58.0f + m_py;

			Draw::Draw(19, &src, &dst, c, 0.0f);
		}
	}
	if (wp == 1)
	{


		src.m_top = 0.0f;
		src.m_left = 192.0f;
		src.m_right = 256.0f;
		src.m_bottom = 64.0f;

		//
		dst.m_top = 0.0f;
		dst.m_left = 270.0f;
		dst.m_right = dst.m_left + 96.0f;
		dst.m_bottom = dst.m_top + 64.0f;

		Draw::Draw(19, &src, &dst, c, 0.0f);

	}
	if (wp == 2)
	{
		src.m_top = 0.0f;
		src.m_left = 0.0f;
		src.m_right = 64.0f;
		src.m_bottom = 64.0f;



		//
		dst.m_top = -10.0f;
		dst.m_left = 270.0f;
		dst.m_right = dst.m_left + 96.0f;
		dst.m_bottom = dst.m_top + 64.0f;

		Draw::Draw(19, &src, &dst, c, 0.0f);
	}
		

	if (wp == 3)
	{



		src.m_top = 0.0f;
		src.m_left = 64.0f;
		src.m_right = 128.0f;
		src.m_bottom = 64.0f;



		//
		dst.m_top = -10.0f;
		dst.m_left = 270.0f;
		dst.m_right = dst.m_left + 96.0f;
		dst.m_bottom = dst.m_top + 64.0f;

		Draw::Draw(19, &src, &dst, c, 0.0f);
	}

	if (wp == 4)
	{
		src.m_top = 0.0f;
		src.m_left = 320.0f;
		src.m_right = 384.0f;
		src.m_bottom = 64.0f;

		dst.m_top = -10.0f;
		dst.m_left = 270.0f;
		dst.m_right = dst.m_left + 96.0f;
		dst.m_bottom = dst.m_top + 64.0f;

		Draw::Draw(19, &src, &dst, c, 0.0f);
	}
		

	if (m_hit_down == false && m_vy <= 1&&fly==true)
	{
		src.m_top = 0.0f;
		src.m_left = 0.0f + 5 * 64.0f + 1.0f;
		src.m_right = 64.0f + 5 *64.0f+ 1.0f;
		src.m_bottom = 64.0f;
	}
	else if (m_hit_down == false && m_vy >= 1&&fly==true)
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
	/*else if(m_hit_down==true&&wolk==true)
	{
		src.m_top = 0.0f;
		src.m_left = 0.0f + AniDate[m_ani_frame] * 64.0f + 1.0f;
		src.m_right = src.m_left + 64.0f - 2.0f;
		src.m_bottom = 64.0f;
	}*/
	if (swordcount <= -25 || Input::GetVKey('X') == false)
	{
		swordcount = 0;
	}

	//表示位置の設定
	dst.m_top = 0.0f + m_py;
	dst.m_left = (64.0*m_posture) + m_px;
	dst.m_right = (64-64.0f*m_posture) + m_px;
	dst.m_bottom = 64.0f + m_py;

	//描画
	Draw::Draw(2, &src, &dst, c, m_dead);

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
	dst.m_right = 252.0f - m_hp*5.04f;
	dst.m_bottom = 44.0f;

	Draw::Draw(5, &src, &dst, c, 0.0f);

	

	

	wchar_t str[50];
	if(wp!=0)
	{
		swprintf_s(str, L"弾数：%d", bullet);

		Font::StrDraw(str, 272, 64, 20, c2);
	}
	
	
}

void CObjHero::EnemyHit(int enemynum)
{
	CHitBox* hit = Hits::GetHitBox(this);
	CObjBlock*pb = (CObjBlock*)Objs::GetObj(OBJ_BLOCK);
	//主人公が敵とどの角度で当たってるか確認
	HIT_DATA** hit_data=NULL;

	if (hit_flag == true)
	{
		if (enemynum == 1)
			hit_data = hit->SearchObjNameHit(OBJ_WOLKENEMY);
		else if (enemynum == 2)
			hit_data = hit->SearchObjNameHit(OBJ_LOCKENEMY);
		else if (enemynum == 3)
			hit_data = hit->SearchObjNameHit(OBJ_FLYENEMY);
		else if (enemynum == 4)
			hit_data = hit->SearchObjNameHit(OBJ_BOSS1);
		else if (enemynum == 5)
			hit_data = hit->SearchObjNameHit(OBJ_SHIELDENEMY);
		else if (enemynum == 6)
			hit_data = hit->SearchObjNameHit(OBJ_SHIELD);
		else if (enemynum == 7)
			hit_data = hit->SearchObjNameHit(OBJ_LOCKENEMY2);

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
					if(enemynum==1)
						m_px += ((CObjWolkEnemy*)hit_data[i]->o)->GetVx();
					if (enemynum == 4)
						m_px += ((CObjBoss1*)hit_data[i]->o)->GetVx();
					


					//後方スクロールライン
					if (m_px < 80)
					{

						pb->SetScroll(pb->GetScroll() - 5.0);
					}

					//前方スクロールライン
					if (m_px > 300)
					{
						m_px = 300;
						
						pb->SetScroll(pb->GetScroll() - 5.0);
						
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