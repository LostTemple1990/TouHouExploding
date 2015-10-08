#include "CardAttribute.h"

map < int, CCardAttribute * > CCardAttribute::mapCardAttribute;

void CCardAttribute::InitMapCardAttribute(int cardID)
{
	if (mapCardAttribute.find(cardID) != mapCardAttribute.end()) return;

	switch (cardID)
	{
	case 1:
	{
		auto attribute = new CCardAttribute;
		attribute->hp = 9;
		attribute->atk = 2;
		attribute->motility = 2;
		attribute->minAtkRange = 1;
		attribute->maxAtkRange = 3;

		attribute->vecSkillAttribute.push_back(L"�����ӡ:ѡ����Χ��Χ2��һ����λ����ɢ����Ĭ�õ�λ������Զ���֧��1b�Ըõ�λ���2�˺���");
		attribute->vecSkillAttribute.push_back(L"��Ļ���:�������Ǽ����غ��ڣ����μ�����Χ��Χ2�ڵ����е�λ�ܵ��ķǽ����˺���1��");

		mapCardAttribute.insert(make_pair(cardID, attribute));
	}
		break;
	default:
		break;
	}
}