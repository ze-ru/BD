//使用するヘッダーファイル
#include "GameL\DrawTexture.h"
#include "GameL\WinInputs.h"
#include "GameL\SceneManager.h"
#include"GameL\SceneObjManager.h"
#include"GameL\HitBoxManager.h"

#include "GameHead.h"
#include "Block.h"
#include"GameL/Audio.h"

//使用するネームスペース
using namespace GameL;

CObjBlock::CObjBlock(int map[11][300],int mapnum)
{
	//マップデータをコピー
	memcpy(m_map, map, sizeof(int)*(11* 300));
	map_num = mapnum;
}
//イニシャライズ
void CObjBlock::Init()
{
	m_scroll = 0.0f;
	dead_flag = false;
	m_time = 0;
	bossflag = false;
	count = 0;
	musicflag = false;
}
//アクション
void CObjBlock::Action()
{
	//主人公の位置情報を取得
	CObjHero*hero = (CObjHero*)Objs::GetObj(OBJ_HERO);
	float hx = hero->GetX();
	float hy = hero->GetY();

	//後方スクロールライン
	if (hx < 200)
	{
		hero->SetX(200);//主人公はラインを超えないようにする
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
			count++;

			//WolkEnemy作成
			if (count >= 1&&count<=3)
			{			
				CObjWolkEnemy*objW = new CObjWolkEnemy(lx*64.0f, i*64.0f - 64.0f);
				Objs::InsertObj(objW, OBJ_WOLKENEMY, 15);
			}

			//ShieldEnemy作成
			if (count == 4)
			{				
				CObjShieldEnemy*objs = new CObjShieldEnemy(lx*64.0f, i*64.0f - 64.0f);
				Objs::InsertObj(objs, OBJ_SHIELDENEMY, 15);
				count = 0;
			}
			//敵出現場所を0にする
			m_map[i][lx] = 0;
		}

		//FlyEnemy作成
		if (m_map[i][lx] == 7)
		{
			CObjFlyEnemy*objF = new CObjFlyEnemy(lx*64.0f, i*64.0f);
			Objs::InsertObj(objF, OBJ_FLYENEMY, 15);

			//敵出現場所を0にする
			m_map[i][lx] = 0;
		}

		//LockEnemy作成
		if (m_map[i][lx] == 6)
		{				
			CObjLockEnemy*objeL = new CObjLockEnemy(lx*64.0f, i*64.0f-64.0f);
			Objs::InsertObj(objeL, OBJ_LOCKENEMY, 15);

			//敵出現場所を0にする
			m_map[i][lx] = 0;
		}

		//switch作成
		if (m_map[i][lx] == 9)
		{
			CObjSwitch*objS = new CObjSwitch(lx*64.0f, i*64.0f - 64.0f);
			Objs::InsertObj(objS, OBJ_SWITCH, 15);
				
			//敵出現場所を0にする
			m_map[i][lx] = 0;
		}

		//BossBlock作成
		if (m_map[i][lx] == 14)
		{
			CObjBossBlock*objB = new CObjBossBlock(lx*64.0f, i*64.0f - 64.0f,map_num);
			Objs::InsertObj(objB, OBJ_BOSSBLOCK, 2);

			//敵出現場所を0にする
			m_map[i][lx] = 0;
		}

		//Heal作成
		if (m_map[i][lx] == 18)
		{
			CObjHeal*objHeal = new CObjHeal(lx*64.0f, i*64.0f - 64.0f);
			Objs::InsertObj(objHeal, OBJ_HEAL, 15);

			//敵出現場所を0にする
			m_map[i][lx] = 0;
		}

		//Assault作成
		if (m_map[i][lx] == 19)
		{
			CObjAssault*objW = new CObjAssault(lx*64.0f, i*64.0f - 64.0f);
			Objs::InsertObj(objW, OBJ_ASSAULT, 15);

			//敵出現場所を0にする
			m_map[i][lx] = 0;
		}

		//Rifle作成
		if (m_map[i][lx] == 20)
		{
			CObjRifle*objL = new CObjRifle(lx*64.0f, i*64.0f - 64.0f);
			Objs::InsertObj(objL, OBJ_RIFLE, 15);

			//敵出現場所を0にする
			m_map[i][lx] = 0;
		}

		//laser作成
		if (m_map[i][lx] == 21)
		{
			CObjlaser*objl = new CObjlaser(lx*64.0f, i*64.0f - 64.0f);
			Objs::InsertObj(objl, OBJ_LASER, 15);

			//敵出現場所を0にする
			m_map[i][lx] = 0;
		}

		//LockEnemy2作成
		if (m_map[i][lx] == 22)
		{			
			CObjLockEnemy2*objeL2 = new CObjLockEnemy2(lx*64.0f, i*64.0f-64.0f);
			Objs::InsertObj(objeL2, OBJ_LOCKENEMY2, 15);

			//敵出現場所を0にする
			m_map[i][lx] = 0;
		}

		//Boss1作成
		if (m_map[i][lx] == 41)
		{
		 	CObjBoss1*objboss = new CObjBoss1(lx*64.0f, i*64.0f - 64.0f);
			Objs::InsertObj(objboss, OBJ_BOSS1, 15);

			//敵出現場所を0にする
			m_map[i][lx] = 0;
		}		
	}

	//m_mapの全要素にアクセス
	for (int i = 0; i < 11; i++)
	{
		for (int j = 0; j < 300; j++)
		{
			if (m_map[i][j] == 13)
			{
				//BOSSが死んだらゴールブロック出現
				if (dead_flag == true)
				{	
					CObjStage1Clear*sb1 = (CObjStage1Clear*)Objs::GetObj(OBJ_STAGE1CLEAR);//ゲームクリア情報取得
					//ゴールブロックオブジェクト作成
					CObjGoalBlock*objg = new CObjGoalBlock(j*64.0f, i*64.0f - 64.0f);
					Objs::InsertObj(objg, OBJ_GOAL_BLOCK, 2);
					
					m_map[i][j] = 0;
					sb1->Setdead();					
				}
			}
			//音楽フラグ
			if (m_map[i][j] == 42 && map_num == 30&&musicflag == false)
			{
				//Boss2オブジェクト作成
				CObjBoss2*objboss2 = new CObjBoss2(j*64.0f, i*64.0f - 64.0f);
				Objs::InsertObj(objboss2, OBJ_BOSS2, 10);

				m_map[i][j] = 0;
				musicflag = true;

				Audio::Stop(5);//音楽ストップ
				float Volume = Audio::VolumeMaster(-0.0f);//マスターボリュームを下げる
				Audio::Start(4);//音楽スタート				
			}
		}
	}

	//ブロックオブジェクト情報取得
	CObjBlock*block = (CObjBlock*)Objs::GetObj(OBJ_BLOCK);

	//主人公が一定範囲に入ると当たり判定実行
	if ((hero->GetX() - block->GetScroll()) > 17920 && map_num == 8 && bossflag == false)
	{
		bossflag = true;
	}
	if (bossflag == true)
	{
		if (m_time < 150)
			m_time++;
	}
	if (m_time == 150)
	{
		map_num = 30;
		musicflag = false;
	}
	if (musicflag == false)
	{
		if (map_num == 0)
		{
			musicflag = true;
			float Volume = Audio::VolumeMaster(-0.0f);//マスターボリュームを下げる
			Audio::Start(2);//音楽スタート
		}
		if (map_num == 8)
		{
			musicflag = true;
			float Volume = Audio::VolumeMaster(-0.0f);//マスターボリュームを下げる
			Audio::Start(5);//音楽スタート
		}
	}	
}

//ドロー
void CObjBlock::Draw()
{	
	//描画カラー情報
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };


	RECT_F dst; //描画先表示位置

	//背景表示
	//マップチップによるblock設置
	for (int i = 0; i < 11; i++)
	{
		for (int j = 0; j < 300; j++)
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

				//描画
				//WolkEnemy
				if (m_map[i][j] == 5)
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
				else if (m_map[i][j] == 4)
				{
					BlockDraw(128.0f, 0.0f, &dst, c, map_num);
				}
				//Switch
				else if (m_map[i][j] == 9)
				{
					;
				}
				//Switch
				else if (m_map[i][j] == 10)
				{
					BlockDraw(192.0f, 0.0f, &dst, c, map_num);
				}
				else if (m_map[i][j] == 14)
				{
					;
				}
				else if (m_map[i][j] == 42)
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
	//衝突状態確認用フラグの初期化
	*up = false;
	*down = false;
	*left = false;
	*right = false;

	//m_mapの全要素にアクセス
	for (int i = 0; i < 11; i++)
	{
		for (int j = 0; j < 300; j++)
		{			
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
						//右
						if ((r < 45 && r > 0) || r > 315 )
						{
							*right = true;
							*x = bx + 64.0f + (scroll);
							*vx = -(*vx)*0.1f;
						}
						//左
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
	//m_mapの全要素にアクセス
	for (int i = 0; i < 11; i++)
	{
		for (int j = 0; j < 300; j++)
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

//BlockHit関数:Boss
void CObjBlock::BlockBossHit(float *x, float *y, bool scroll_on, bool *up, bool *down,
	bool *left, bool *right, float *vx, float *vy)
{
	//衝突状態確認用フラグの初期化
	*up = false;
	*down = false;
	*left = false;
	*right = false;

	//m_mapの全要素にアクセス
	for (int i = 0; i < 11; i++)
	{
		for (int j = 0; j < 300; j++)
		{		
			if (m_map[i][j] > 0)
			{
				//要素番号を座標に変更
				float bx = j * 64.0f;
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
						//右
						if ((r < 45 && r > 0) || r > 315)
						{
							*right = true;
							*x = bx + 256.0f + (scroll);
							*vx = -(*vx)*0.1f;
						}
						//左
						else if (r > 135 && r < 225)
						{
							*left = true;
							*x = bx - 256.0f + (scroll);
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
							*y = by + 196.0f;
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

//BlockHit関数 通常弾
void CObjBlock::BulletHit(float *x, float *y, bool scroll_on, bool *up, bool *down,
	bool *left, bool *right)
{
	//衝突状態確認用フラグの初期化
	*up = false;
	*down = false;
	*left = false;
	*right = false;

	//m_mapの全要素にアクセス
	for (int i = 0; i < 11; i++)
	{
		for (int j = 0; j < 300; j++)
		{			
			if (m_map[i][j] > 0)
			{
				//要素番号を座標に変更
				float bx = j * 64.0f;
				float by = i * 64.0f -64.0f;

				bool flag = false;
				//スクロールの影響
				float scroll = scroll_on ? m_scroll : 0;

				//オブジェクトとブロックの当たり判定
				if ((*x + (-scroll) + 24.0f > bx) && (*x + (-scroll) < bx + 24.0f) && (*y + 24.0f > by) && (*y < by+24.0f))
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
						//右
						if ((r < 45 && r > 0) || r > 315)
						{
							*right = true;
						}
						//左
						else if (r > 135 && r < 225)
						{
							*left = true;
						}
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

//BlockHit関数 レーザー
void CObjBlock::LaserHit(float *x, float *y, bool scroll_on, bool *up, bool *down,
	bool *left, bool *right)
{
	//衝突状態確認用フラグの初期化
	*up = false;
	*down = false;
	*left = false;
	*right = false;

	//m_mapの全要素にアクセス
	for (int i = 0; i < 11; i++)
	{
		for (int j = 0; j < 300; j++)
		{		
			if (m_map[i][j] > 0)
			{
				//要素番号を座標に変更
				float bx = j * 64.0f;
				float by = i * 64.0f - 64.0f;
				bool flag = false;

				//スクロールの影響
				float scroll = scroll_on ? m_scroll : 0;

				//オブジェクトとブロックの当たり判定
				if ((*x + (-scroll) + 60.0f > bx) && (*x + (-scroll) < bx + 60.0f) && (*y + 32.0f > by) && (*y < by + 32.0f))
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
						//右
						if ((r < 45 && r > 0) || r > 315)
						{
							*right = true;
						}
						//左
						else if (r > 135 && r < 225)
						{
							*left = true;
						}
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