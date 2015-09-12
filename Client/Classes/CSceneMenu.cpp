#include "CSceneMenu.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"
#include "CTutorialMode.h"
#include "CPVPMode.h"
#include "CCard.h"

#include "MainMenu.h"
#include "Config.h"
#include "GameHall.h"
#include "CardsGallery.h"
#include "CardDetail.h"
#include "Staff.h"
#include "Tutorial.h"

USING_NS_CC;

using namespace cocostudio::timeline;
CLayerMenu *CSceneMenu::currentScene = NULL;
CSceneMenu *CSceneMenu::pSceneMenu = NULL;

//Scene* CSceneMenu::createScene()
//{
//	//// 'scene' is an autorelease object
//	//auto scene = CSceneMenu::create();
//	//
//	//// 'layer' is an autorelease object
//	//auto layer = Layer::create();
//
//	//// add layer as a child to scene
//	//scene->addChild(layer);
//
//	//// return the scene
//	//return scene;
//}

// on "init" you need to initialize your instance
bool CSceneMenu::init()
{
	CMainMenu::getInstance()->Enter();

	addChild(CMainMenu::getInstance());
	addChild(CGameHall::getInstance());
	addChild(CCardsGallery::getInstance());
	addChild(CCardDetail::getInstance());
	addChild(CConfig::getInstance());
	addChild(CStaff::getInstance());
	addChild(CTutorial::getInstance());

	//esc��
	auto listener = EventListenerKeyboard::create();
	listener->onKeyReleased = [this](EventKeyboard::KeyCode keyCode, Event *event)
	{
		//������ESC
		if (keyCode == EventKeyboard::KeyCode::KEY_ESCAPE)
		{
			currentScene->OnButtonReturn();
			//switch (currentScene)
			//{
			//case sceneMainMenu:
			//	exit(0);
			//	break;
			//case sceneConfig:
			//	OnButtonConfigReturn();
			//	break;
			//case sceneGallery:
			//	OnButtonGalleryReturn();
			//	break;
			//case sceneGameHall:
			//	OnButtonGameHallReturn();
			//	break;
			//case sceneTutorial:
			//	OnButtonTutorialReturn();
			//	break;
			//case sceneStaff:
			//	OnButtonStaffReturn();
			//	break;
			//}
			log("%s", "esc");
		}
	};
	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);
	//
	//����¼�
	auto listenerMouse = EventListenerMouse::create();
	//�����
	listenerMouse->onMouseDown = [this](Event *event)
	{
		//EventMouse *eventMouse = ;

		currentScene->OnMouseDown((EventMouse *)event);
		//if (sceneGameHall == currentScene)
		//{
		//	log("MouseDown");
		//}else if (sceneCardDetail == currentScene){
		//	/////
		//}
	};
	//������
	listenerMouse->onMouseScroll = [this](Event *event)
	{
		currentScene->OnMouseScroll((EventMouse *)event);
		//switch (currentScene)
		//{
		//case sceneGameHall:
		//{
		//}
		//	break;
		//case sceneTutorial:
		//{
		//	log("%s %f", "MouseScroll", eventMouse->getScrollY());
		//}
		//	break;
		//default:
		//	break;
		//}
	};
	//����ƶ�
	listenerMouse->onMouseMove = [](Event *event)
	{
		currentScene->OnMouseMove((EventMouse *)event);
		//log("%s %f %f", "MouseMove", eventMouse->getCursorX(), eventMouse->getCursorY());
	};
	//currentScene
	currentScene = CMainMenu::getInstance();
	//test
	for (int i = 0; i < 100; ++i)
	{
		char num[10];
		CGameHall::getInstance()->AddRoomList(std::string(_itoa(i, num, 10)), "RoomName", "PlayerName");
	}
	//
	_eventDispatcher->addEventListenerWithSceneGraphPriority(listenerMouse, this);
	return true;
}


//
//void CSceneMenu::OnButtonConfigReturn()
//{
//	//�������˵�
//	if (currentScene != sceneConfig)
//		return;
//	layerMainMenu->setVisible(true);
//	layerConfig->setVisible(false);
//	currentScene = sceneMainMenu;
//}
//
//void CSceneMenu::OnButtonConfigTutorial()
//{
//	////�����ý������̳̽���
//	if (currentScene != sceneConfig)
//		return;
//	CTutorialMode *tutorial = CTutorialMode::create();
//	tutorial->startTutorial();
//	//layerTutorial->setVisible(true);
//	//layerConfig->setVisible(false);
//	currentScene = sceneTutorial;
//}

//void CSceneMenu::OnButtonConfigStaff()
//{
//	//�����ý������Staff����
//	if (currentScene != sceneConfig)
//		return;
//	layerConfig->setVisible(false);
//	layerStaff->setVisible(true);
//	currentScene = sceneStaff;
//}

//void CSceneMenu::OnButtonTutorialReturn()
//{
//	//�ӽ̳̽��淵�����ý���
//	if (currentScene != sceneTutorial)
//		return;
//	scrollViewTutorial->jumpToTop();
//
//	layerTutorial->setVisible(false);
//	layerConfig->setVisible(true);
//	currentScene = sceneConfig;
//}
//
//void CSceneMenu::OnButtonStaffReturn()
//{
//	//��Staff���淵�����ý���
//	if (currentScene != sceneStaff)
//		return;
//	layerStaff->setVisible(false);
//	layerConfig->setVisible(true);
//	currentScene = sceneConfig;
//}
//
//
//
//void CSceneMenu::ReturnCardGallery()
//{
//	layerCardDetail->setVisible(false);
//	layerCardsGallery->setVisible(true);
//	currentScene = sceneGallery;
//}
//
