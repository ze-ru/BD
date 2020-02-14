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
	flag = false;

	//音楽情報の読み込み
	Audio::LoadAudio(1, L"switch.wav", SOUND_TYPE::EFFECT);

	//当たり判定用のHitBoxを作成
	Hits::SetHitBox(this,m_sx,m_sy, 64, 64, ELEMENT_ENEMY, OBJ_SWITCH, 1);
}

//アクション
void CObjSwitch::Action()
{
	//オブジェクト情報を取得
	CObjBlock*block = (CObjBlock*)Objs::GetObj(OBJ_BLOCK);//ブロックオブジェクト情報を取得
	
	//自身のHitBoxを持ってくる
	CHitBox* hit = Hits::GetHitBox(this);
	hit->SetPos(m_sx + block->GetScroll(), m_sy);

	//スイッチのバーが右向きかつ、剣で攻撃されると
	if (hit->CheckElementHit(ELEMENT_ATTACK)==true&&flag==false)
	{
		float Volume = Audio::Volume(10.0f,1);//ボリュームを上げる
		Audio::Start(1);//音楽スタート
		flag = true;//スイッチを左右反転させる
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

	//表示位置の設定
	src.m_top = 0.0f;
	src.m_left = 256.0f;
	src.m_right = 320.0f;
	src.m_bottom = 64.0f;

	//ブロック情報を持ってくる
	CObjBlock*block = (CObjBlock*)Objs::GetObj(OBJ_BLOCK);

	//表示位置の設定
	if (flag == false)
	{		
		dst.m_top = m_sy;
		dst.m_left = m_sx + block->GetScroll();
		dst.m_right = dst.m_left + 64.0f;
		dst.m_bottom = 64.0f + m_sy;
	}
	if (flag == true)//左右反転スイッチを描画
	{
		dst.m_top = m_sy;
		dst.m_left = m_sx + block->GetScroll() + 64.0f;
		dst.m_right = dst.m_left-64.0f;
		dst.m_bottom = 64.0f + m_sy;	
	}

	//描画
	Draw::Draw(0, &src, &dst, c, 0.0f);
}