//使用するヘッダーファイル
#include "GameL\DrawTexture.h"
#include "GameL\WinInputs.h"
#include "GameL\SceneManager.h"
#include"GameL\SceneObjManager.h"

#include "GameHead.h"
#include "Block.h"

//使用するネームスペース
using namespace GameL;

//イニシャライズ
void CObjBlock::Init()
{
	//マップ情報
	int block_data[10][10] =
	{
		{0,0,0,0,0,0,0,0,0,0,},
		{0,0,0,0,0,0,0,1,1,0,},
		{0,0,0,0,0,0,0,0,0,0,},
		{0,0,0,0,0,0,0,0,0,0,},
		{0,0,0,0,0,0,0,0,0,0,},
		{0,0,0,0,0,0,0,0,0,0,},
		{0,0,0,1,1,1,0,0,0,1,},
		{0,0,0,0,0,0,0,0,0,1,},
		{0,0,0,0,0,0,0,0,0,1,},
		{1,1,1,1,1,1,1,1,1,1,},
	};
	//マップデータをコピー
	memcpy(m_map, block_data, sizeof(int)*(10 * 10));
}
//アクション
void CObjBlock::Action()
{
	//主人公の位置を取得
	CObjHero*hero = (CObjHero*)Objs::GetObj(OBJ_HERO);
	float hx = hero->GetX();
	float hy = hero->GetY();

	hero->SetUp(false);
	hero->SetDown(false);
	hero->SetLeft(false);
	hero->SetRight(false);

	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			//m_mapの全要素にアクセス
			if (m_map[i][j] > 0)
			{
				//要素番号を座標に変更
				float x = j * 64.0f;
				float y = i * 64.0f;

				//主人公とブロックの当たり判定
				if ((hx+64.0f>x) && (hx<x+64.0f) && (hy+64.0f>y) && (hy<y+64.0f))
				{
					//上下左右判定

					//vectorの作成
					float vx = hx - x;
					float vy = hy - y;

					//長さを求める
					float len = sqrt(vx * vx + vy * vy);

					//角度を求める
					float r = atan2(vy, vx);
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
							hero->SetRight(true);
							hero->SetX(x + 64.0f);
							hero->SetVX(-hero->GetVX()*0.1f);
						}

						//上
						if (r > 45 && r < 135)
						{
							hero->SetDown(true);
							hero->SetY(y - 64.0f);
							hero->SetVY(0.0f);
						}

						//左
						if (r > 135 & r < 225)
						{
							hero->SetLeft(true);
							hero->SetX(x - 64.0f);
							hero->SetVX(-hero->GetVX()*0.1f);
						}

						//下
						if (r > 225 && r < 315)
						{
							hero->SetUp(true);
							hero->SetY(y + 64.0f);
							if (hero->GetVY() < 0)
							{
								hero->SetVY(0.0f);
							}
						}
				    }
					
					
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
	//切り取り位置の設定
	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = src.m_left + 64.0f;
	src.m_bottom = 64.0f;

	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			if (m_map[i][j] > 0)
			{
				//表示位置の設定
				dst.m_top = i *64.0f;
				dst.m_left = j *64.0f;
				dst.m_right = dst.m_left + 64.0f;
				dst.m_bottom = dst.m_top + 64.0f;

				//描画
				Draw::Draw(0, &src, &dst, c, 0.0f);
			}
		}
	}
	
}