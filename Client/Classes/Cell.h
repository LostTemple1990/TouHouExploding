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
	struct UnitState
	{
		Label *lblHP;
		Sprite *camp;
		Label *lblAttribute;
		DrawNode *attributeBackground;
		UnitState(){
			lblHP = NULL;
			camp = NULL;
			attributeBackground = NULL;
			lblAttribute = NULL;
		}
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
	void SetAttributePosition(Point position);
	//��Ч
	void Moveable();					//δ�ƶ��ĵ�λ
	void Moved();						//���ƶ��ĵ�λ
	void Normal();						//ͨ��״̬
	void Blink(Point position);			//��˸��ĳ��
	void MoveTo(Point position);

	Sprite *backGround;
	
	CCell();
	~CCell();
private:
	const float _attributeBorderWidth = 5;
};
