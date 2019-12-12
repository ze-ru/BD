//使用するヘッダーファイル

#include"GameL\DrawTexture.h"
#include"explosion.h"

using namespace GameL;


RECT_F GetBulletEffect(int *ani, int *ani_time, bool del, int timing)
{
	//返すRECT情報
	RECT_F rect;

	//ブラグで通常弾丸か着弾アニメーション処理分岐
	if (del == true)
	{
		//着弾アニメーション
		//リソース着弾アニメーション位置
		RECT_F ani_src[4] =
		{
			{64,0,64,128},
			{64,64,128,128},
			{64,128,192,128},
			{64,256,256,128},
		};
		//アニメーションのコマ間隔
		if (*ani_time > timing)
		{
			*ani += 1;//アニメーションのコマを1つ進める
			*ani_time = 0;
		}
		else
		{
			*ani_time += 1;
		}
		rect = ani_src[*ani];//アニメーションのRECT配列からm_ani番目のRECT情報を渡す
	}
	else
	{
		//弾丸アニメーション無し
		//リソースは弾丸位置
		RECT_F bullet = { 0.0f,96.0f,126.0f,32.0f };
		rect = bullet;
	}
	return rect;
}