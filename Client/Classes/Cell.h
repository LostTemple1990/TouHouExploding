#pragma once

#include "cocostudio/CocoStudio.h"
#include "ChessboardPosition.h"
#include "SceneBattle.h"
#include "Chessboard.h"
#include "Unit.h"

//char *GetUnitFileName(char *fileName, int unitID);
class CCell;

class CCell
{
public:
	Point cellPosition;
	ChessboardPosition chessboardPosition;

	CUnit *unit;
	//struct UnitState
	//{
	//	//enum StateType{
	//	//	ST_Moveable,
	//	//	ST_Moved,
	//	//}state;
	//	UnitState() :
	//		lblHP(NULL),
	//		groupType(UG_YOURSELF),
	//		group(NULL),
	//		lblAttribute(NULL),
	//		attributeBackground(NULL),
	//		bMoveable(false),
	//		skillNum(1)
	//	{
	//	}
	//}unitState;

	ChessboardPosition GetCellNum();
	void SetUnit(int unitID, ChessboardPosition postiton);
	void SwapUnit(CCell *cell);
	//��Ч
	void MoveWithPath(std::list<ChessboardPosition> &listMovePath);

	static ActionInterval *Moveable();									//δ�ƶ��ĵ�λ
	static ActionInterval *Moved();										//���ƶ��ĵ�λ
	//static Action *Normal();											//ͨ��״̬
	static ActionInterval *Blink(Point position);						//��˸��ĳ��
	static ActionInterval *BeAttacked();								//
	static ActionInterval *MoveToPosition(ChessboardPosition position);

	Sprite *backGround;
	
	CCell();
	~CCell();
protected:
	const float _attributeBorderWidth = 5;
};
