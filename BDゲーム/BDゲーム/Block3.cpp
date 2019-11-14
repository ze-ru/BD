//使用するヘッダーファイル
#include "GameL\DrawTexture.h"
#include "GameL\WinInputs.h"
#include "GameL\SceneManager.h"
#include"GameL\SceneObjManager.h"
#include"GameL\HitBoxManager.h"

#include "GameHead.h"
#include "Block3.h"


//使用するネームスペース
using namespace GameL;

CObjBlock3::CObjBlock3(int map3[11][156])
{
	//マップデータをコピー
	memcpy(m_map3, map3, sizeof(int)*(11 * 156));
}

//イニシャライズ
void CObjBlock3::Init()
{
	m_scroll = 0.0f;

}

//アクション
void CObjBlock3::Action()
{
	if (m_map3[0][0] == 0)
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
		float line = hx + (-m_scroll) + 500;

		//敵出現ラインを要素番号化
		int lx = ((int)line) / 64;

		//敵出現ラインの列を検索
		for (int i = 0; i < 11; i++)
		{
			if (m_map3[i][lx] == 5)
			{
				CObjWolkEnemy*objW = new CObjWolkEnemy(lx*64.0f, i*63.0f);
				Objs::InsertObj(objW, OBJ_WOLKENEMY, 15);

				//敵出現場所を0にする
				m_map3[i][lx] = 0;
			}
		}
	}
}

//ドロー
void CObjBlock3::Draw()
{
	//描画カラー情報
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src; //描画元切り取り位置
	RECT_F dst; //描画先表示位置

	//マップチップによるblock設置
	for (int i = 0; i < 11; i++)
	{
		for (int j = 0; j < 156; j++)
		{
			if (m_map3[i][j] > 0 && m_map3[i][j] != 5)
			{
				//要素番号を座標に追加
				float bx = i * 64.0f;
				float by = i * 64.0f;
				//表示位置の設定
				dst.m_top = i * 64.0f - 64.0f;
				dst.m_left = j * 64.0f + m_scroll;
				dst.m_right = dst.m_left + 64.0f;
				dst.m_bottom = dst.m_top + 64.0f;

				if (m_map3[i][j] == 2)
				{
					BlockDraw3(64.0f, 0.0f, &dst, c);
				}
				else if (m_map3[i][j] == 3)
				{
					BlockDraw3(128.0f, 0.0f, &dst, c);
				}
				else
				{
					//描画
					BlockDraw3(0.0f, 0.0f, &dst, c);
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
void CObjBlock3::BlockDraw3(float x, float y, RECT_F *dst, float c[])
{
	RECT_F src;
	src.m_top = y;
	src.m_left = x;
	src.m_right = src.m_left + 64.0f;
	src.m_bottom = src.m_top + 64.0f;
	//描画
	Draw::Draw(9, &src, dst, c, 0.0f);
}



void CObjBlock3::BlockHit3(float *x, float *y, bool scroll_on, bool *up, bool *down,
	bool *left, bool *right, float *vx, float *vy)
{

	*up = false;
	*down = false;
	*left = false;
	*right = false;



	for (int i = 0; i < 11; i++)
	{
		for (int j = 0; j < 156; j++)
		{
			//m_mapの全要素にアクセス
			if (m_map3[i][j] > 0)
			{
				//要素番号を座標に変更
				float bx = j * 64.0f;
				float by = i * 64.0f - 64.0f;

				//スクロールの影響
				float scroll = scroll_on ? m_scroll : 0;

				//オブジェクトとブロックの当たり判定
				if ((*x + (-scroll) + 64.0f > bx) && (*x + (-scroll) < bx + 64.0f) && (*y + 64.0f > by) && (*y < by + 64.0f))
				{
					//上下左右判定

					//vectorの作成
					float rvx = (*x + (-scroll)) - bx;
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
							*x = bx + 64.0f + (scroll);
							*vx = -(*vx)*0.1f;
						}

						//上
						if (r > 45 && r < 135)
						{
							*down = true;
							*y = by - 64.0f;


							*vy = 0.0f;
						}

						//左
						if (r > 135 && r < 225)
						{
							*left = true;
							*x = bx - 64.0f + (scroll);
							*vx = -(*vx)*0.1f;
						}

						//下
						if (r > 225 && r < 315)
						{
							*up = true;
							*y = by + 64.0f;
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