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
};

char *GetCardFileName(char *fileName, int cardID);
