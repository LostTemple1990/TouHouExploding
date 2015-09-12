#pragma once

#include "cocostudio/CocoStudio.h"

char *GetUnitFileName(char *fileName, int unitID);

enum UnitCamp
{
	UC_YOURSELF,
	UC_ENEMY,
};

class CCell
{
public:
	Point cellPosition;

	Sprite *unit;
	void SetUnit(int unitID, Point postiton);
	void DelUnit();
	struct
	{
		Label *lblHP;
		DrawNode *camp;
		Label *lblAttribute;
	}unitState;
	//��λ���Ͻǵ�HP��ʾ
	void SetHP(int HP);
	void SetHPVisable(bool visable);
	//��λ���Ͻǵ���Ӫ��ʾ
	void SetCamp(UnitCamp campType);
	void SetCampVisable(bool visable);
	//�����ͣʱ������������
	void SetAttribute(std::string attribute);
	void SetAttributeVisable(bool visable);
	//��Ч
	void Moveable();					//δ�ƶ��ĵ�λ
	void Moved();						//���ƶ��ĵ�λ
	void Normal();						//ͨ��״̬
	void Blink(Point position);			//��˸��ĳ��
	void MoveTo(Point position);

	Sprite *backGround;
	
	CCell();
	~CCell();
};
