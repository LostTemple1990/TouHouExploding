#pragma once
#include <vector>
#include <map>
using namespace std;

class CCardAttribute
{
public:
	static map < int, CCardAttribute * > mapCardAttribute;
	static void InitMapCardAttribute(int cardID);

	int ID;				//��Ƭ���

	int hp;				//HP
	int motility;		//������
	int atk;			//������
	int minAtkRange;	//������Χ��Сֵ
	int maxAtkRange;	//������Χ���ֵ

	vector<wstring> vecSkillAttribute;
};
