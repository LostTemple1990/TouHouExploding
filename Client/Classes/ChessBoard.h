#pragma once

#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"
#include "Cell.h"
#include "Card.h"
#include "SceneBattle.h"
#include "FloatingWindow.h"
#include "Skill.h"
#define CHESSBOARD_MAX_X 12
#define CHESSBOARD_MAX_Y 8
using namespace std;

enum PlayerState;
class ChessboardPosition;
class CCell;

extern mutex mutexSkill;
extern CCell *g_cellSkillTarget;
const int g_floatingWindowZOrder = 100;

class CLayerChessboard : public Layer
{
public:
	virtual bool init() override;
	CREATE_FUNC(CLayerChessboard);
	static CLayerChessboard *pChessboard;
	static CLayerChessboard *getInstance()
	{
		static CLayerChessboard *pChessboard = NULL;
		if (pChessboard == NULL)
			pChessboard = CLayerChessboard::create();
		return pChessboard;
	}
	virtual void update(float delta) override;

	bool startRecordMovePath;
	list<ChessboardPosition> listMovePath;
	PlayerState playerState;
	CCell *selectedCell;
	//
	void SetUnit(int unitID, int x, int y);
	void ShowMapCell(Sprite *sprite, int x, int y);
	void ShowAtkRange(ChessboardPosition position, int range);
	void ShowMovableRange(ChessboardPosition position, int range);
	void ShowSelectCell(int x, int y);
	void ShowAtkCell(ChessboardPosition position);
	void DelUnit(ChessboardPosition position);
	Point GetChessboardPosition(ChessboardPosition position);
	void GetCellNum(ChessboardPosition &position, Point cursor);

	CCell *GetCell(ChessboardPosition position);
	void ChangeUnitPosition(int x1, int y1, int x2, int y2);
	void ShowAttribut(float dt);

	bool GetPositionOnChessboard(int &x, int &y, Point mouse);
	void ClearBackGround();							//�������ָ���ԭʼ״̬
	//���
	void OnMouseMove(Point cursorPosition);
	
	Point prevPointCursor;
	int prevLeftButtonDownX, prevLeftButtonDownY;
		//prevRightMouseDownX, prevRightMouseDownY;
	int prevCursorChessboardX = -1, prevCursorChessboardY = -1;
	bool leftButtonDown, rightButtonDown;			//�ϴΰ������ĸ���
	void OnClickCell(int x, int y);
	void SelectOperateUnit(ChessboardPosition position);
	//ѡ��λ����ж���ť
	ui::Button *buttonMove;
	ui::Button *buttonAttack;
	ui::Button *buttonSkill;
	void ShowOperateButton();
	void HideOperateButton();
	void OnButtonMove();
	void OnButtonAttack();
	void OnButtonSkill();
	ui::Button *buttonSkill_1;
	ui::Button *buttonSkill_2;
	void OnButtonSkill_1();
	void OnButtonSkill_2();
	void ShowSelectUnitSkillList();
	void HideSelectUnitSkillList();
	void ShowSkillDescribe(float dt);
	void HideSkillDescribe();
	void SetSkillDescribePosition(Point point);
	void HoverSkillButton(Point cursorPosition);
	//��¼�ƶ�·��
	void RecordMovePath(ChessboardPosition position);
	//Chessboard�Ի���
	void SetDialogString(string str);
	void SetDialogVisible(bool visible);

	CLayerChessboard();
	~CLayerChessboard();
private:
	int _currentSkillID;
	const float _spacingX = 75, _spacingY = 75;		//���̸��ӵĴ�С
	Point _chessboardPosition;						//�������µ��λ��
	CCell *_currentCell;							//��ǰ������ڵĸ���

	CCell *_cell[8][12];							//������ÿ�����ӵ���Ϣ
	//���ܸ���
	CFloatingWindow _skillDescribe;
	//�Ի���
	Node *_dialogNode;
	ui::Text *_dialogText;
	ui::Button *_dialogYes;
	ui::Button *_dialogNo;
	void _OnButtonDialogYes();
	void _OnButtonDialogNo();
};

Rect GetButtonRect(ui::Button *button);
wstring LineBreak(const wstring &wstr, int n);