#include "MainMenu.h"
#include "Config.h"
#include "GameHall.h"
#include "CardsGallery.h"

CMainMenu *CMainMenu::pMainMenu = NULL;

bool CMainMenu::init()
{
	Layer::init();
	//
	auto nodeMainMenu = CSLoader::createNode("MainScene.csb");
	//��Ӱ�ťclick�¼��Ĳ�׽
	auto buttonStart = nodeMainMenu->getChildByName<ui::Button *>("Button_StartGame");
	buttonStart->addClickEventListener(CC_CALLBACK_0(CMainMenu::OnButtonStart, this));
	auto buttonGallery = nodeMainMenu->getChildByName<ui::Button *>("Button_CardsGallery");
	buttonGallery->addClickEventListener(CC_CALLBACK_0(CMainMenu::OnButtonGallery, this));
	auto buttonConfig = nodeMainMenu->getChildByName<ui::Button *>("Button_Config");
	buttonConfig->addClickEventListener(CC_CALLBACK_0(CMainMenu::OnButtonConfig, this));
	auto buttonExit = nodeMainMenu->getChildByName<ui::Button *>("Button_Exit");
	buttonExit->addClickEventListener(CC_CALLBACK_0(CMainMenu::OnButtonReturn, this));

	addChild(nodeMainMenu);
	//
	setVisible(false);
}

void CMainMenu::Enter()
{
	setVisible(true);
	CSceneMenu::currentScene = getInstance();
}

void CMainMenu::OnButtonReturn()
{
	//�˳���Ϸ
	if (CSceneMenu::currentScene != getInstance())
		return;
	exit(0);
}

void CMainMenu::OnButtonStart()
{
	//������Ϸ����
	if (CSceneMenu::currentScene != getInstance())
		return;
	Leave();
	CGameHall::getInstance()->Enter();
}
void CMainMenu::OnButtonGallery()
{
	//���뿨�����
	if (CSceneMenu::currentScene != getInstance())
		return;
	Leave();
	CCardsGallery::getInstance()->Enter();
}
void CMainMenu::OnButtonConfig()
{
	//�������ò˵�
	if (CSceneMenu::currentScene != getInstance())
		return;
	Leave();
	CConfig::getInstance()->Enter();
}