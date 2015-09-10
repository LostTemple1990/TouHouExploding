#include "GameHall.h"
#include "MainMenu.h"
#include "CPVPMode.h"

CGameHall *CGameHall::pGameHall = NULL;

bool CGameHall::init()
{
	Layer::init();
	//selectedRoom = NULL;
	auto gameHallMenuNode = CSLoader::createNode("GameHall.csb");
	addChild(gameHallMenuNode);
	setVisible(false);

	auto buttonGameGallJoinGame = gameHallMenuNode->getChildByName<ui::Button *>("Button_JoinGame");
	buttonGameGallJoinGame->addClickEventListener(CC_CALLBACK_0(CGameHall::OnButtonJoinGame, this));
	auto buttonGameGallReturn = gameHallMenuNode->getChildByName<ui::Button *>("Button_ReturnMainMenu");
	buttonGameGallReturn->addClickEventListener(CC_CALLBACK_0(CGameHall::OnButtonReturn, this));

	roomList = gameHallMenuNode->getChildByName<ui::ListView *>("ListView_RoomList");
	return true;
}

CGameHall::CGameHall()
{
}


CGameHall::~CGameHall()
{
}

void CGameHall::Enter()
{
	setVisible(true);
	CSceneMenu::currentScene = getInstance();
}

void CGameHall::OnButtonReturn()
{
	//�������˵�
	if (CSceneMenu::currentScene != getInstance())
		return;
	Leave();
	CMainMenu::getInstance()->Enter();
}

void CGameHall::OnButtonJoinGame()
{
	//���� ������Ϸ����
	if (CSceneMenu::currentScene != getInstance())
		return;
	auto director = Director::getInstance();
	CPVPMode *scene = CPVPMode::create();
	director->replaceScene(scene);
	//
	return;

	//if (selectedRoom == NULL)
	//	return;
	//join selectedRoom
}