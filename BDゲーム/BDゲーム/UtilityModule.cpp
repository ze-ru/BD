//使用するヘッダー
#include"GameHead.h"
#include"UtilityModule.h"
#include<math.h>
#include"GameL\DrawTexture.h"

//使用するネームスペース
using namespace GameL;
bool UnitVec(float*vx, float*vy)
{
	return true;
}

//---CheckWindow関数
//引数１ float pos_x   :領域外かどうかを調べるｘ位置
//引数２ float pos_y   :領域外かどうかを調べるｙ位置
//引数３ float window_x:領域のtop位置
//引数４ float window_y:領域のleft位置
//引数５ float window_w:領域のright位置
//引数６ float window_h:領域のbottom位置
//戻り値 bool          :true=領域内 false=領域外
//内容
//領域内かどうかを調べる位置pos_(x,y)がwindow_(x,y,w,h)の内か外かを調べる
bool CheckWindow(float pos_x, float pos_y,
	float window_x, float window_y, float window_w, float window_h)
{
	//領域チェック
	if (pos_x < window_x)
	{
		return false;//領域外
	}
	if (pos_x > window_w)
	{
		return false;//領域外
	}
	if (pos_y < window_y)
	{
		return false;//領域外
	}
	if (pos_y > window_h)
	{
		return false;//領域外
	}

	return true;//領域内
}
//---GetAtan2Angle関数
//引数１ float w  :幅
//引数２ float h  :高さ
//戻り値 float    :角度（0°～360°）
//内容
//高さと幅から直角三角形があると仮定してその角度を求める。
float GetAtan2Angle(float w, float h)
{
	//atan２で角度を求める
	float r=atan2(h, w)*180.0f / 3.14f;

	//-180°～-0°を180°～360°に変換
	if (r < 0)
	{
		r = 360 - abs(r);
	}

	return r;

}
//---GetBulletEffec関数
//引数１	int*	ani;着弾アニメーション
//引数２	int*	ani_time;着弾アニメーション間隔タイム
//引数３	bool	del;削除チェック（true=着弾エフェクト　false=通常の弾丸
//引数４	int		timing;間隔区間
//戻り値RECT_F　eff;描画するRECT
//delで弾丸のRECTや着弾のeffectのRECT（アニメーションのRECT）を返す
RECT_F GetBulletEffec(int*ani, int*ani_time, bool del, int timing)
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
			{32,0,32,64},
		{32,32,64,64},
		{32,64,96,64},
		{32,96,128,64},
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