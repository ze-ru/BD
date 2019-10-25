//使用ヘッダーファイル
#include"GameL\DrawTexture.h"
#include"GameL\WinInputs.h"
#include"GameL\SceneManager.h"

#include"GameHead.h"
#include "StageUi.h"

//使用ネームスペース
using namespace GameL;

//イニシャライズ
void CObjStageUi::Init()
{
	m_hp = 0;
	m_ani_time = 0;
	m_ani_frame = 0;
}

//アクション
void CObjStageUi::Action()
{
	if (m_hp <50) 
	{
		m_ani_time++;
	}
	if (m_ani_time == 5)
	{
		m_ani_frame++;
		m_ani_time = 0;
	}
	if (m_ani_frame == 9)
	{
		m_hp++;
		m_ani_frame = 0;
	}
	if (m_hp >= 50)
	{
		//Scene::SetScene(new CSceneGameOver());
	}

}

//ドロー
void CObjStageUi::Draw()
{
	//描画カラー情報
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src;//描画元切り取り位置
	RECT_F dst;//描画先表示位置

	//切り取り位置の設定
	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 128.0f;
	src.m_bottom = 24.0f;
	

	//表示位置の設定
	dst.m_top = 0.0f;
	dst.m_left = 0.0f;
	dst.m_right = 128.0f;
	dst.m_bottom = 24.0f;

	

	//描画
	Draw::Draw(5, &src, &dst, c, 0.0f);

	src.m_top = 2.0f;
	src.m_left = 128.0f;
	src.m_right = 130.0f;
	src.m_bottom = 22.0f;

	
		dst.m_top = 2.0f;
		dst.m_left = 2.0f;
		dst.m_right = 128.0f-m_hp*2.5f;
		dst.m_bottom = 22.0f;

		Draw::Draw(5, &src, &dst, c, 0.0f);
	
	

}