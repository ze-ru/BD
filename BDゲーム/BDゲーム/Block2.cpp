//使用するヘッダーファイル
#include "GameL\DrawTexture.h"
#include "GameL\WinInputs.h"
#include "GameL\SceneManager.h"
#include"GameL\SceneObjManager.h"
#include"GameL\HitBoxManager.h"

#include "GameHead.h"
#include "Block2.h"

//使用するネームスペース
using namespace GameL;

CObjBlock2::CObjBlock2(int map[11][157])
{
	//マップデータをコピー
	memcpy(m_map, map, sizeof(int)*(11 * 157));
}

//イニシャライズ
void CObjBlock2::Init()
{

}

//アクション
void CObjBlock2::Action()
{

}

//ドロー
void CObjBlock2::Draw()
{

}

//BlockDrawMethod関数
//引数1 float x  :リソースの切り取り位置X
//引数2 float y  :リソースの切り取り位置Y
//引数3 RECT_F* dst  :描画位置
//引数4 float c[]  :カラー情報
//ブロックを64×64限定描画用。リソース切り取り位置のみx,yで設定できる
void CObjBlock::BlockDraw(float x, float y, RECT_F *dst, float c[])
{
	RECT_F src;
	src.m_top = y;
	src.m_left = x;
	src.m_right = src.m_left + 64.0f;
	src.m_bottom = src.m_top + 64.0f;
	//描画
	Draw::Draw(0, &src, dst, c, 0.0f);
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
//引数10 int* bt  :下部分判定時特殊なブロックのタイプを返す
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
			if (m_map[i][j] > 0)
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

