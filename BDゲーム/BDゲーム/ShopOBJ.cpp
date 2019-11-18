//�g�p����w�b�_�[�t�@�C��
#include "GameL\DrawTexture.h"
#include "GameL\WinInputs.h"
#include "GameL\SceneManager.h"
#include"GameL\SceneObjManager.h"
#include"GameL\HitBoxManager.h"

#include "GameHead.h"
#include "ShopOBJ.h"


CObjShopOBJ::CObjShopOBJ(float x, float y)
{
	px = x;
	py = y;
}

void CObjShopOBJ::Init()
{
	Hits::SetHitBox(this, px, py, 128, 128, ELEMENT_SHOP, OBJ_SHOPOBJ, 1);
}

//�A�N�V����
void CObjShopOBJ::Action()
{
	CObjHero*objh = (CObjHero*)Objs::GetObj(OBJ_HERO);
	CObjBlock*pb = (CObjBlock*)Objs::GetObj(OBJ_BLOCK);
	CHitBox*hit = Hits::GetHitBox(this);
	if (hit->CheckElementHit(ELEMENT_PLAYER))
	{
		if (Input::GetVKey(VK_UP) == true)
		{
			Scene::SetScene(new CSceneShop());
		}
	}
	hit->SetPos(px + pb->GetScroll(), py);
}

//�h���[
void CObjShopOBJ::Draw()
{
	//�`��J���[���
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src;//�`�挳�؂���ʒu
	RECT_F dst;//�`���\���ʒu

	
	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 128.0f;
	src.m_bottom = 128.0f;
	CObjBlock*pb = (CObjBlock*)Objs::GetObj(OBJ_BLOCK);

	//�\���ʒu�̐ݒ�
	dst.m_top = py;
	dst.m_left = px+pb->GetScroll();
	dst.m_right = px+128.0f+pb->GetScroll();
	dst.m_bottom = py+128.0f;



	//�`��
	Draw::Draw(15, &src, &dst, c, 0.0f);

	
}