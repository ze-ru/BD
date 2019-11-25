//使用するヘッダーファイル
#include "GameL\DrawTexture.h"
#include "GameL\WinInputs.h"
#include "GameL\SceneManager.h"
#include"GameL\SceneObjManager.h"
#include"GameL\HitBoxManager.h"

#include "GameHead.h"
#include "Block.h"

//使用するネームスペース
using namespace GameL;

CObjBlock::CObjBlock(int map[11][157],int mapnum)
{
	//マップデータをコピー
	memcpy(m_map, map, sizeof(int)*(11* 157));
	map_num = mapnum;
}
//イニシャライズ
void CObjBlock::Init()
{
	m_scroll = 0.0f;
	dead_flag = false;
}
//アクション
void CObjBlock::Action()
{
	//主人公の位置を取得
	
		CObjHero*hero = (CObjHero*)Objs::GetObj(OBJ_HERO);


		float hx = hero->GetX();
		float hy = hero->GetY();

		//後方スクロールライン
		if (hx < 80)
		{
			hero->SetX(80);//主人公はラインを超えないようにする
			m_scroll -= hero->GetVX();//主人公が本来動くべき分の値をm_scrollに加える
		
		}

		//前方スクロールライン
		if (hx > 300)
		{
			hero->SetX(300);
			m_scroll -= hero->GetVX();
		
		}

		//敵出現ライン
		//主人公の位置＋500を敵出現ラインに
		float line = hx + (-m_scroll) + 515;

		//敵出現ラインを要素番号化
		int lx = ((int)line) / 64;
		
		//敵出現ラインの列を検索
		for (int i = 0; i < 11; i++)
		{
			if (m_map[i][lx] == 5)
			{
				CObjWolkEnemy*objW = new CObjWolkEnemy(lx*64.0f, i*64.0f-64.0f);
				Objs::InsertObj(objW, OBJ_WOLKENEMY, 15);
				
				//敵出現場所を0にする
				m_map[i][lx] = 0;
			}
			if (m_map[i][lx] == 7)
			{
				CObjFlyEnemy*objF = new CObjFlyEnemy(lx*64.0f, i*64.0f);
				Objs::InsertObj(objF, OBJ_FLYENEMY, 15);

				//敵出現場所を0にする
				m_map[i][lx] = 0;
			}
			if (m_map[i][lx] == 6)
			{
				
				CObjLockEnemy*objeL = new CObjLockEnemy(lx*64.0f, i*64.0f-64.0f);
				Objs::InsertObj(objeL, OBJ_LOCKENEMY, 15);
				m_map[i][lx] = 0;
			}

			//switch作成
			if (m_map[i][lx] == 9)
			{
				CObjSwitch*objS = new CObjSwitch(lx*64.0f, i*64.0f - 64.0f);
				Objs::InsertObj(objS, OBJ_SWITCH, 15);
				m_map[i][lx] = 0;
			}

			//BossBlock作成
			if (m_map[i][lx] == 14)
			{
				CObjBossBlock*objB = new CObjBossBlock(lx*64.0f, i*64.0f - 64.0f,map_num);
				Objs::InsertObj(objB, OBJ_BOSSBLOCK, 2);
				m_map[i][lx] = 0;
			}

			if (m_map[i][lx] == 20)
			{
				CObjShopOBJ*objshop = new CObjShopOBJ(lx*64.0f, i*64.0f - 64.0f);
				Objs::InsertObj(objshop, OBJ_SHOPOBJ, 2);
				m_map[i][lx] = 0;
			}

			if (m_map[i][lx] == 41)
			{
			 	CObjBoss1*objboss = new CObjBoss1(lx*64.0f, i*64.0f - 64.0f);
				Objs::InsertObj(objboss, OBJ_BOSS1, 15);
				m_map[i][lx] = 0;
			}
			if (m_map[i][lx] == 42)
			{
				CObjBoss2*objboss2 = new CObjBoss2(lx*64.0f, i*64.0f - 64.0f);
				Objs::InsertObj(objboss2, OBJ_BOSS2, 15);
				m_map[i][lx] = 0;
			}
			
			


		}

		for (int i = 0; i < 11; i++)
		{
			for (int j = 0; j < 157; j++)
			{
				if (m_map[i][j] == 13)
				{
					if (dead_flag == true)
					{
						CObjStage1Clear*sb1 = (CObjStage1Clear*)Objs::GetObj(OBJ_STAGE1CLEAR);
						CObjGoalBlock*objg = new CObjGoalBlock(j*64.0f, i*64.0f - 64.0f);
						Objs::InsertObj(objg, OBJ_GOAL_BLOCK, 2);
						
						m_map[i][j] = 0;
						dead_flag = 0;
						sb1->Setdead();
						
					}
				}
			}
		}
	
}
//ドロー
void CObjBlock::Draw()
{
	
		//描画カラー情報
		float c[4] = { 1.0f,1.0f,1.0f,1.0f };

		RECT_F src; //描画元切り取り位置
		RECT_F dst; //描画先表示位置

		//背景表示


		//マップチップによるblock設置

		for (int i = 0; i < 11; i++)
		{
			for (int j = 0; j < 157; j++)
			{
				if (m_map[i][j] > 0)
				{
					//要素番号を座標に追加
					float bx = i * 64.0f;
					float by = i * 64.0f;
					//表示位置の設定
					dst.m_top = i * 64.0f - 64.0f;
					dst.m_left = j * 64.0f + m_scroll;
					dst.m_right = dst.m_left + 64.0f;
					dst.m_bottom = dst.m_top + 64.0f;


					if (m_map[i][j] == 5)//WolkEnemy
					{
						;
					}
					else if (m_map[i][j] == 2)
					{
						BlockDraw(64.0f, 0.0f, &dst, c,map_num);
					}
					else if (m_map[i][j] == 3)
					{
						BlockDraw(128.0f, 0.0f, &dst, c,map_num);
					}
					else if (m_map[i][j] == 9)//Switch
					{
						;
					}
					else if (m_map[i][j] == 14)
					{
						;
					}
					else
					{
						//描画
						BlockDraw(0.0f, 0.0f, &dst, c,map_num);

					}

				}
			}
		}
	
}

//BlockDrawMethod関数
//引数1 float x  :リソースの切り取り位置X
//引数2 float y  :リソースの切り取り位置Y
//引数3 RECT_F* dst  :描画位置
//引数4 float c[]  :カラー情報
//ブロックを64×64限定描画用。リソース切り取り位置のみx,yで設定できる
void CObjBlock::BlockDraw(float x, float y, RECT_F *dst, float c[],int num)
{
	RECT_F src;
	src.m_top = y;
	src.m_left = x;
	src.m_right = src.m_left + 64.0f;
	src.m_bottom = src.m_top + 64.0f;
	//描画
	Draw::Draw(num, &src, dst, c, 0.0f);
}

//BlockHit関数
//引数1 float*x  :判定を行うobjectのX位置
//引数2 float*y  :判定を行うobjectのY位置
//引数3 bool scroll_on  :判定を行うobjectはスクロールの影響を与えるかどうか(true=与える　false=与えない)
//引数4 bool* up  :上下左右判定の上部分にあたっているかどうかを返す
//引数5 bool*　down  :上下左右判定の下部分にあたっているかどうかを返す
//引数6 bool* left  :上下左右判定の左部分にあたっているかどうかを返す
//引数7 bool* right  :上下左右判定の右部分にあたっているかどうかを返す
//引数8 float* vx  :左右判定時の反発による移動方向・力の値に変えて返す
//引数9 float* vy  :上下判定時による自由落下運動の移動方向・力の値に変えて返す
//判定を行うobjectとブロック64×64限定で、当たり判定と上下左右判定を行う
//その結果は引数4～10に返す
void CObjBlock::BlockHit(float *x, float *y, bool scroll_on, bool *up, bool *down,
	bool *left, bool *right, float *vx, float *vy)
{
	*up = false;
	*down = false;
	*left = false;
	*right = false;


	for (int i = 0; i < 11; i++)
	{
		for (int j = 0; j < 157; j++)
		{
			//m_mapの全要素にアクセス
			if (m_map[i][j] > 0 && m_map[i][j]!=14)
			{
				//要素番号を座標に変更
				float bx = j * 64.0f;
				float by = i * 64.0f - 64.0f;
				bool flag = false;
				//スクロールの影響
				float scroll = scroll_on ? m_scroll : 0;

				//オブジェクトとブロックの当たり判定
				if ((*x + (-scroll) + 64.0f > bx) && (*x + (-scroll) < bx + 64.0f) && (*y + 64.0f > by) && (*y < by + 64.0f))
				{
					//上下左右判定

					//vectorの作成
					float rvx = (*x  -scroll) - bx;
					float rvy = *y - by;

					//長さを求める
					float len = sqrt(rvx * rvx + rvy * rvy);

					//角度を求める
					float r = atan2(rvy, rvx);
					r = r * 180.0f / 3.14f;

					if (r <= 0.0f)
						r = abs(r);
					else
						r = 360.0f - abs(r);

					//lenがある一定の長さより短い場合判定に入る
					if (len < 88.0f)
					{
						//角度で上下左右を判定
					
						 if ((r < 45 && r > 0) || r > 315 )
						{
							*right = true;
							*x = bx + 64.0f + (scroll);
							*vx = -(*vx)*0.1f;

						}

						else if (r > 135 && r < 225 )
						{
							*left = true;
							*x = bx - 64.0f + (scroll);
							*vx = -(*vx)*0.1f;
								
						}
						
						
						//上
						else if (r > 45 && r < 135)
						{
							*down = true;
							*y = by - 64.0f;
							*vy = 0.0f;
							
							
						}
						
						//下
						else if (r > 225 && r < 315)
						{
						 	*up = true;
							*y = by + 64.0f;
							if (*vy < 0)
							{
								*vy = 0.0f;
							}

							
						}
						if (flag == false)
						{
							flag = true;
						}
					}
				}
			}
		}
	}

}

void CObjBlock::SetBlock(int flag)
{
	for (int i = 0; i < 11; i++)
	{
		for (int j = 0; j < 157; j++)
		{
			if (flag == 1)
			{
				if (m_map[i][j] == 4)
				{
					m_map[i][j] = 0;
				}
			}
		}
	}

}

void CObjBlock::BlockBossHit(float *x, float *y, bool scroll_on, bool *up, bool *down,
	bool *left, bool *right, float *vx, float *vy)
{
	*up = false;
	*down = false;
	*left = false;
	*right = false;



	for (int i = 0; i < 11; i++)
	{
		for (int j = 0; j < 157; j++)
		{
			//m_mapの全要素にアクセス
			if (m_map[i][j] > 0)
			{
				//要素番号を座標に変更
				float bx = j * 64.0f ;
				float by = i * 64.0f - 192.0f;
				bool flag = false;
				//スクロールの影響
				float scroll = scroll_on ? m_scroll : 0;

				//オブジェクトとブロックの当たり判定
				if ((*x + (-scroll) + 256.0f > bx) && (*x + (-scroll) < bx + 256.0f) && (*y + 192.0f > by) && (*y < by + 192.0f))
				{
					//上下左右判定

					//vectorの作成
					float rvx = (*x - scroll) - bx;
					float rvy = *y - by;

					//長さを求める
					float len = sqrt(rvx * rvx + rvy * rvy);

					//角度を求める
					float r = atan2(rvy, rvx);
					r = r * 180.0f / 3.14f;

					if (r <= 0.0f)
						r = abs(r);
					else
						r = 360.0f - abs(r);

					//lenがある一定の長さより短い場合判定に入る
					if (len < 88.0f)
					{
						//角度で上下左右を判定

						if ((r < 45 && r > 0) || r > 315)
						{
							*right = true;
							*x = bx + 256.0f + (scroll);
							*vx = -(*vx)*0.1f;

						}
						else if (r > 135 && r < 225)
						{
							*left = true;
							*x = bx - 256.0f + (scroll);
							*vx = -(*vx)*0.1f;

						}

						//}
						//上
						else if (r > 45 && r < 135)
						{
							*down = true;
							*y = by - 64.0f;


							*vy = 0.0f;
						}

						//下
						else if (r > 225 && r < 315)
						{
							*up = true;
							*y = by + 192.0f;
							if (*vy < 0)
							{
								*vy = 0.0f;
							}
						}
					
					}
				}
			}
		}
	}

}

void CObjBlock::BulletHit(float *x, float *y, bool scroll_on, bool *up, bool *down,
	bool *left, bool *right)
{
	*up = false;
	*down = false;
	*left = false;
	*right = false;



	for (int i = 0; i < 11; i++)
	{
		for (int j = 0; j < 157; j++)
		{
			//m_mapの全要素にアクセス
			if (m_map[i][j] > 0)
			{
				//要素番号を座標に変更
				float bx = j * 64.0f;
				float by = i * 64.0f - 64.0f;
				bool flag = false;
				//スクロールの影響
				float scroll = scroll_on ? m_scroll : 0;

				//オブジェクトとブロックの当たり判定
				if ((*x + (-scroll) + 32.0f > bx) && (*x + (-scroll) < bx + 32.0f) && (*y + 24.0f > by) && (*y < by + 24.0f))
				{
					//上下左右判定

					//vectorの作成
					float rvx = (*x - scroll) - bx;
					float rvy = *y - by;

					//長さを求める
					float len = sqrt(rvx * rvx + rvy * rvy);

					//角度を求める
					float r = atan2(rvy, rvx);
					r = r * 180.0f / 3.14f;

					if (r <= 0.0f)
						r = abs(r);
					else
						r = 360.0f - abs(r);

					//lenがある一定の長さより短い場合判定に入る
					if (len < 88.0f)
					{
						//角度で上下左右を判定

						if ((r < 45 && r > 0) || r > 315)
						{
							*right = true;


						}
						else if (r > 135 && r < 225)
						{
							*left = true;


						}

						//}
						//上
						else if (r > 45 && r < 135)
						{
							*down = true;

						}

						//下
						else if (r > 225 && r < 315)
						{
							*up = true;

						}

					}
				}
			}
		}
	}

}