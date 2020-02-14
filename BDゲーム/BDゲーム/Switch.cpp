//使用するヘッダーファイル
#include"GameL\WinInputs.h"
#include"GameL\SceneManager.h"
#include"GameL\DrawTexture.h"
#include"GameL\HitBoxManager.h"
#include"GameL\Audio.h"

#include"Switch.h"
#include"GameHead.h"

//使用するネームスペース
using namespace GameL;

//コンストラクタ
CObjSwitch::CObjSwitch(float x, float y)
{
	m_sx = x;
	m_sy = y;
}

//イニシャライズ
void CObjSwitch::Init()
{
	m_hit_up = false;
	m_hit_down = false;
	m_hit_left = false;
	m_hit_right = false;

	flag = false;

	//音楽情報の読み込み
	Audio::LoadAudio(1, L"switch.wav", SOUND_TYPE::EFFECT);

	//当たり判定用HitBoxを作成
	Hits::SetHitBox(this,m_sx,m_sy, 64, 64, ELEMENT_ENEMY, OBJ_SWITCH, 1);
}

//アクション
void CObjSwitch::Action()
{
	//ブロックオブジェクト情報を取得
	CObjBlock*block = (CObjBlock*)Objs::GetObj(OBJ_BLOCK);

	//Switch削除test
	//自身のHitBoxを持ってくる
	CHitBox* hit = Hits::GetHitBox(this);
	hit->SetPos(m_sx + block->GetScroll(), m_sy);

	if (hit->CheckElementHit(ELEMENT_ATTACK)==true&&flag==false)
	{
		float Volume = Audio::Volume(10.0f,1);//ボリュームを上げる
		Audio::Start(1);//音楽スタート
		flag = true;
	}
	block->SetBlock(flag);
}

//ドロー
void CObjSwitch::Draw()
{
	//描画カラー情報
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src;//描画元切り取り位置
	RECT_F dst;//描画先表示位置

	//切り取り位置の設定
	src.m_top = 0.0f;
	src.m_left = 256.0f;
	src.m_right = 320.0f;
	src.m_bottom = 64.0f;

	//ブロック情報を持ってくる
	CObjBlock*block = (CObjBlock*)Objs::GetObj(OBJ_BLOCK);
	if (flag == false)
	{
		//表示位置の設定
		dst.m_top = m_sy;
		dst.m_left = m_sx + block->GetScroll();
		dst.m_right = dst.m_left + 64.0f;
		dst.m_bottom = 64.0f + m_sy;
	}
	if (flag == true)
	{
		//表示位置の設定
		dst.m_top = m_sy;
		dst.m_left = m_sx + block->GetScroll() + 64.0f;
		dst.m_right = dst.m_left-64.0f;
		dst.m_bottom = 64.0f + m_sy;
	}

	//描画
	Draw::Draw(0, &src, &dst, c, 0.0f);
}