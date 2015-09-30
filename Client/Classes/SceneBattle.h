#pragma once
#include <string>
#include <vector>
#include "cocos2d.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"
#include "Chessboard.h"
#include "ChessboardPosition.h"
#include "SceneMenu.h"
#include "Effects.h"
#include "Card.h"

USING_NS_CC;

extern bool g_bTest;
class CLayerChessboard;
enum PlayerState;

void ChangeState(PlayerState newState);

enum PlayerState
{
	PS_Wait,				//�Է��Ļغϣ����ɲ���
	PS_WaitingOperate,		//�ȴ�ѡ��λ���߿�Ƭ
	PS_SelectUnitBehavior,	//ѡ�񹥻����ƶ�����
	PS_SelectUnit,			//ָ����λ
	PS_WaitMoveAnimateEnd,	//�ȴ��ƶ���������
	PS_WaitAttackAnimateEnd,//�ȴ�������������
	PS_SelectAttackTarget,	//ָ������Ŀ��
	PS_SelectMovePosition,	//ָ���ƶ�λ��
	PS_SelectSkill,			//ѡ��ʹ�õļ���
	PS_RunningSkill,		//ִ�м�����
	PS_WaitSelectCell,		//�Զ����ܵĵȴ�ѡ��Ŀ��״̬
};

class CSceneBattle : public cocos2d::Scene
{
public:
	const float cardWidth = 420;
	const float cardHeight = 590;
	const float panelCardWidth = 800;
	const float panelCardHeight = 180;
	const float cardScale = panelCardHeight / cardHeight;

	static CSceneBattle *pSceneBattle;
	static CSceneBattle *getInstance()
	{
		if (pSceneBattle == NULL)
			pSceneBattle = new CSceneBattle;
		return pSceneBattle;
	}
	//static cocos2d::Scene* createScene();
	virtual bool init() override;
	CREATE_FUNC(CSceneBattle);

	CLayerChessboard *chessboard;
	Layer *layerBattleScene;
	Layer *layerShade;
	Node *nodeBackGround;
	Node *nodePauseMenu;
	Node *nodeAbandonedCards;
	ui::Layout *panelCards;
	ui::Text *textCardDescribe;
	ui::Text *textRoundCountdown;
	ui::Text *textTotalRound;
	ui::ScrollView *scrollViewAbandonedCards;

	ui::Button *buttonAbandonedCards;
	ui::Button *buttonSwitch;
	ui::Button *buttonEndTurn;
	ui::Button *buttonGiveUp;

	Node *nodeHandCards;
	Node *nodeSummonPool;

	enum EScene{
		sceneBattle,
		scenePauseMenu,
		sceneAbandonedCards,
	}currentScene;

	//�ж�
	void UnitAttack();
	//Ͷ���ͽ����غ�
	void OnButtonGiveUp();
	void OnButtonEndTurn();
	//��ʱ��
	void UpdateRoundCountdown(float t);
	//����Ƭ��ʾ��panelCard�У��¼���Ŀ�Ƭ�����Ҷ�
	void AddHandCards(int cardID);
	void AddSummonPool(int cardID);
	//���ƶ�
	void AddAbandonedCards(int cardID);
	void OnButtonAbandonedCards();
	void AbandonedCardsRetuen();
	//�л��ٻ��غ�����
	bool bHandCards;	//true:handCards	false:summonPool
	void OnButtonSwitch();
	//PauseMenu Button
	void OnButtonReturnMainMenu();
	void OnButtonContinue();
	//
	int totalRound;
	void AddTotalRound();
	//�غϵ���ʱ
	float roundRestTime;
	int timeCount;
	void RoundCountdown(float n);
	//ս������

	void StartYourTurn();
	void EndYourTurn();
	void SelectUnit();
	void SelectPosition();

	PlayerState playerState;
private:
	//ɾ�����������֮���summonPool����handCards�еĿ�Ƭ��������
	void _RedrawCards(Node *node);

	//vector<CSKill> _vecOnRoundStart;
};

////��card���Ϊfather��child���޸�Ϊָ���Ĵ�С
//void ShowCard(Card *card, Rect rect, Node *father);
//void ShowCard(Card *card, Point position, float scale, Node *father);
//���ؿ�ͼ���ļ���
////��ID����card��Sprite
//Sprite *CreateCardSprite(int cardID);
