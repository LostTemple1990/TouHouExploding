#include "Card.h"
//#include "SceneBattle.h"

//void CardSprite::ShowCard(Point point)
//{
//	sprite->setPosition(point);
//}

CCard::CCard()
{
}

CCard::~CCard()
{
}


float GetCardViewWidth(Sprite *sprite)
{
	float scale = sprite->getScale();
	float width = sprite->getTexture()->getPixelsWide();
	return width*scale;
}

float GetCardViewHeight(Sprite *sprite)
{
	float scale = sprite->getScale();
	float height = sprite->getTexture()->getPixelsHigh();
	return height*scale;
}

Rect GetCardViewRect(Sprite *sprite, Point father)
{
	float scale = sprite->getScale();
	Rect rect = sprite->getTextureRect();
	rect.size = rect.size * scale;
	rect.origin = father + sprite->getPosition();
	rect.origin.x -= sprite->getAnchorPoint().x * GetCardViewWidth(sprite);
	rect.origin.y -= sprite->getAnchorPoint().y * GetCardViewHeight(sprite);
	return rect;
}

CCard *CCard::create(int cardID)
{
	CCard *card = new CCard;
	card->Sprite::initWithFile(GetCardFileName(cardID));
	//card->cardSprite = Sprite::create(GetCardFileName(fileName, cardID));

	card->ID = cardID;
	switch (cardID)
	{
	case 1:	//��������
		card->hp = 9;
		card->atk = 2;
		card->motility = 2;
		card->minAtkRange = 1;
		card->maxAtkRange = 3;

		card->vecSkillAttribute.push_back(L"�����ӡ:ѡ����Χ��Χ2��һ����λ����ɢ����Ĭ�õ�λ������Զ���֧��1b�Ըõ�λ���2�˺���");
		card->vecSkillAttribute.push_back(L"��Ļ���:�������Ǽ����غ��ڣ����μ�����Χ��Χ2�ڵ����е�λ�ܵ��ķǽ����˺���1��");

		//card->skill_1_Describe = "�����ӡ:ѡ����Χ��Χ2��һ����λ����ɢ����Ĭ�õ�λ������Զ���֧��1b�Ըõ�λ���2�˺���";
		//card->skill_2_Describe = "��Ļ���:�������Ǽ����غ��ڣ����μ�����Χ��Χ2�ڵ����е�λ�ܵ��ķǽ����˺���1��";
		break;
	default:
		break;
	}

	return card;
}

void CCard::ShowCard(Rect rect, Node *father)
{
	Rect rectCard = getTextureRect();
	float scale = MIN(rect.size.width / rectCard.size.width, rect.size.height / rectCard.size.height);
	ShowCard(rectCard.origin, scale, father);
}

void CCard::ShowCard(Point position, float scale, Node *father)
{
	setPosition(position);
	setScale(scale);
	father->addChild(this);
}

void CCard::DelHandCards()
{

}


//Sprite *CreateCardSprite(int cardID)
//{
//	char buf[20];
//	return Sprite::create(GetCardFileName(buf, cardID));
//}

//void Card::SetCardSize(Size size)
//{
//
//}
//
//void SetCardPosition(Point position)
//{
//
//}
