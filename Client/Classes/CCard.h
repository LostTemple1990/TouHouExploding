#pragma once
#include "cocos2d.h"
#include "ui\CocosGUI.h"
#include "cocostudio/CocoStudio.h"
USING_NS_CC;

float GetCardViewWidth(Sprite *sprite);
float GetCardViewHeight(Sprite *sprite);
Rect GetCardViewRect(Sprite *sprite,Point father);	//father�Ǹ����������µ��ڴ����е�����

class CCard : public Sprite
{
public:
	int ID;			//��Ƭ���

	int hp;			//HP
	int motility;	//������
	int atk;		//������
	int atkRange;	//������Χ

	static CCard *create(int cardID);
	void ShowCard(Rect rect, Node *father);
	void ShowCard(Point position, float scale, Node *father);
	void DelHandCards();
	//void SetCardSize(Size size);
	//void SetCardPosition(Point position);
};

//class CardSprite
//{
//public:
//	Sprite *sprite;
//
//	void ShowCard(Point point);
//	void SetCardScale(float scale);
//
//	static CardSprite *create(const char *fileName);
//	//���ؿ�Ƭ���ź������
//	Rect GetCardViewRect();
//	float GetCardViewWidth();
//	float GetCardViewHeight();
//};