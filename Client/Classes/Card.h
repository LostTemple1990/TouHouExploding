#pragma once
#include "cocos2d.h"
#include "ui\CocosGUI.h"
#include "cocostudio/CocoStudio.h"
#include "ToolFunc.h"
#include "CardAttribute.h"
USING_NS_CC;

float GetCardViewWidth(Sprite *sprite);
float GetCardViewHeight(Sprite *sprite);
Rect GetCardViewRect(Sprite *sprite,Point father);	//father�Ǹ����������µ��ڴ����е�����

class CUnit;

class CCard : public Sprite, public CCardAttribute
{
public:
	//int ID;				//��Ƭ���

	//int hp;				//HP
	//int motility;		//������
	//int atk;			//������
	//int minAtkRange;	//������Χ��Сֵ
	//int maxAtkRange;	//������Χ���ֵ

	//std::string skill_1_Describe;
	//std::string skill_2_Describe;
	//std::string skill_3_Describe;

	//Sprite *cardSprite;
	//CUnit *cardUnit;

	static CCard *create(int cardID);
	void ShowCard(Rect rect, Node *father);
	void ShowCard(Point position, float scale, Node *father);
	void DelHandCards();

	CCard();
	~CCard();
};

//Sprite *CreateCardSprite(int cardID);