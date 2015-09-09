#pragma once
#include "cocos2d.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"
#include "CLayerChessBoard.h"

USING_NS_CC;

std::string WStrToUTF8(const std::wstring& src);
extern bool gbTest;

class CSceneBattle : public cocos2d::Scene
{
public:
	const float cardWidth = 420;
	const float cardHeight = 590;
	const float panelCardWidth = 900;
	const float panelCardHeight = 220;
	const float cardScale = panelCardHeight / cardHeight;

	static cocos2d::Scene* createScene();
	virtual bool init() override;
	CREATE_FUNC(CSceneBattle);

	CLayerChessBoard *chessBoard;
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
private:
	//ɾ�����������֮���summonPool����handCards�еĿ�Ƭ��������
	void _RedrawCards(Node *node);	
};

////��card���Ϊfather��child���޸�Ϊָ���Ĵ�С
//void ShowCard(Card *card, Rect rect, Node *father);
//void ShowCard(Card *card, Point position, float scale, Node *father);
//���ؿ�ͼ���ļ���
char *GetCardFileName(char *fileName, int cardID);
////��ID����card��Sprite
//Sprite *CreateCardSprite(int cardID);