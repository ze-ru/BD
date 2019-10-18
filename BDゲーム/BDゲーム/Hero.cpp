//使用ヘッダーファイル
#include"GameL\DrawTexture.h"
#include"GameL\WinInputs.h"
#include"GameL\SceneManager.h"

#include"GameHead.h"
#include"Hero.h"

//使用ネームスペース
using namespace GameL;

//イニシャライズ
void CObjHero::Init()
{
	m_px = 0.0f;//位置
	m_py = 0.0f;
	m_vx = 0.0f;//移動ベクトル
	m_vy = 0.0f;
	m_posture = 0.0f;//右向き0.0f 左向き1.0f

	m_ani_time = 0;
	m_ani_frame = 1;
}

//アクション
void CObjHero::Action()
{
	//移動ベクトルの破棄
	m_vy = 0.0f;

	//キーの入力方向
	if (Input::GetVKey(VK_RIGHT) == true)//右
	{
		m_vx =+1.2f;
		m_posture = 0.0f;
		m_ani_time += 1;
	}

	else if (Input::GetVKey(VK_LEFT) == true)//左
	{
		m_vx =-1.2f;
		m_posture = 1.0f;
		m_ani_time += 1;
	}

	else
	{
		m_ani_frame = 1;
		m_ani_time = 0;
	}

	if (m_ani_time > 2)
	{
		m_ani_frame += 1;
		
	}

	if (m_ani_frame == 3)
	{
		m_ani_frame = 3;
	}

	if (m_ani_frame == 4)
	{
		m_ani_frame = 0;
	}

	//摩擦
	m_vx += -(m_vx*0.098);

	//位置の更新
	m_px += m_vx;
	m_py += m_vy;
}

//ドロー
void CObjHero::Draw()
{
	int AniDate[4] =
	{
		1,2,3,0,
	};

	//描画カラー情報
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src;//描画元切り取り位置
	RECT_F dst;//描画先表示位置

	//切り取り位置の設定
	src.m_top = 0.0f;
	src.m_left = 0.0f + AniDate[m_ani_frame] * 64;
	src.m_right = 64.0f + AniDate[m_ani_frame]*64;
	src.m_bottom = 64.0f;

	//表示位置の設定
	dst.m_top = 0.0f + m_py;
	dst.m_left = (64.0*m_posture) + m_px;
	dst.m_right = (64-64.0f*m_posture) + m_px;
	dst.m_bottom = 64.0f + m_py;

	//描画
	Draw::Draw(0, &src, &dst, c, 0.0f);

}