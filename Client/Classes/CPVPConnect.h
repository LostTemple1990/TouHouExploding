#pragma once
#include "CPVPMode.h"
#include <WinSock2.h>
using namespace std;

enum OrderType{
	OT_NULL					= 0,	//�����쳣ʱ��ֵ
	//Global Order
	OT_Common_Inform		= 1,	//֪ͨ
	OT_Common_Reply			= 2,	//�ظ�
	OT_Common_Ask			= 3,	//����
	OT_CS_KeepConnect		= 1004,	//���ӱ���
	OT_SC_LiveCheck			= 2003,	//���ѯ��
	OT_SC_AnnounceChat		= 2004,	//������������
	OT_CS_SendChat			= 1005,	//������������

	//Login
	OT_CS_VersionCheck		= 11001,//ѯ�ʰ汾�Ƿ����
	OT_CS_Login				= 11002,//��½
	OT_CS_AskRoomList		= 21001,//���󷿼��б�

	//Add Room
	OT_CS_JoinRoom			= 21002,//���뷿��
	OT_CS_Ready				= 21003,//׼��
	OT_CS_QuitRoom			= 21004,//�˳�����
	OT_SC_FlashRoomList		= 22001,//ˢ�·����б�
	OT_SC_AnnounceReady		= 22002,//��֪׼��״̬
	OT_SC_Start				= 22003,//��Ϸ��ʼ
	OT_SC_KickingPlayer		= 22004,//�߳�ĳ��

	//Game Init
	OT_SC_BattleGround		= 32001,//ͨ��ս�����
	OT_CS_InitReady			= 31001,//׼�����
	OT_SC_NextStage			= 32002,//������һ�׶�

	OT_SC_StateException	= 32003,//��֪�쳣״̬
	OT_SC_AllInformation	= 32004,//����ȫ��ս����Ϣ
	OT_CS_AskAllInformation = 31002,//����ȫ��ս����Ϣ
	OT_SC_GameEnd			= 32005,//֪ͨ��Ϸ����
	OT_CS_GiveUp			= 31003,//Ͷ��
	//32006
	OT_SC_Event				= 32007,//֪ͨ�¼�

	//Round Start
	OT_SC_NewRoundState		= 42001,//�»غ���Ϣ

	//Round Prepare
	OT_SC_NewState			= 52001,//�µ�ս��״̬��Ϣ

	//Round Operation
	OT_CS_UnitMove			= 61001,//��λ�ƶ�
	OT_CS_UnitAttack		= 61002,//��λ����
	OT_CS_UseCard			= 61003,//ʹ�ÿ���
	OT_CS_UseSkill			= 61004,//ʹ�ü���
	OT_CS_Summon			= 61005,//�ٻ���Ů
	//���� 61006
	OT_CS_EndTurn			= 61007,//�����ж�

	OT_SC_UnitMove			= 62001,//��λ�ƶ�
	OT_SC_UnitAttack		= 62002,//��λ����
	OT_SC_UseCard			= 62003,//ʹ�ÿ���
	OT_SC_UseSkill			= 62004,//ʹ�ü���
	OT_SC_Summon			= 62005,//�ٻ���Ů
	OT_SC_AnnounceEndTurn	= 62006,//�����ж�
	OT_SC_SpecialEvent		= 62007,//�����¼�

	OT_SC_MandatoryEndTurn	= 62008,//ǿ�ƻغϽ���

	//Game End Account
	OT_SC_BattleResult		= 72001,//����ս��
};

struct OrderParam
{
	const char *name;
	rapidjson::Type type;

	OrderParam();
	OrderParam(const char *infName, rapidjson::Type infType)
	{
		type = infType;
		name = infName;
	}
};

extern map<OrderType, vector<OrderParam> > g_mapOrderParam;

class CPVPConnect
{
public:
	static CPVPConnect *pPVPConnect;
	static CPVPConnect *getInstance()
	{
		if (pPVPConnect == NULL)
			pPVPConnect = new CPVPConnect;
		return pPVPConnect;
	}

	sockaddr_in serverAddr;
	SOCKET clientSocket;

	void init();

	//����CS����
		//Global Order
	void KeepConnect();
	void SendChat(const string &msg);
		//Login
	void Login(const string &playerName,const string &passWord);
	void VersionCheck(int version);
	void AskRoomList();
		//RO
	void UnitMove(int unitID, int x, int y);
	void UnitAttack(int unitID, int x, int y);
	void UseCard(int cardID, int x, int y);
	void UseSkill(int skillID, int x, int y);
	void Summon(int unitID, int x, int y);
	void EndTurn();
	//��ȡ��������Ĳ���
		//Global Order
	void ParseAnnounceChat(const string &strJSON, string &playerName, string &msg);
		//Add Room
	void ParseFlashRoomList(const string &strJSON, map<int, pair<string, string> > &vecRoomList);
		//Game Init
	void ParseBattleGround(const string &strJSON);///
	void ParseStateException(const string &strJSON, int &exp);
	void ParseAllInformation(const string &strJSON);///
	void ParseEvent(const string &strJSON);///
		//Round Start
	void ParseNewRoundState(const string &strJSON);///
		//Round Prepare
	void ParseNewState(const string &strJSON);///
		//Round Operation
	void ParseUnitMove(const string &strJSON, int &unitID, int &targetX, int &targetY);
	void ParseUnitAttack(const string &strJSON, int &unitID, int &targetX, int &targetY);
	void ParseUseCard(const string &strJSON, int &cardID, int &targetX, int &targetY);
	void ParseUseSkill(const string &strJSON, int &skillID, int &targetX, int &targetY);
	void ParseSummon(const string &strJSON, int &unitID);
	void ParseSpecialEvent(const string &strJSON);///
		//Game End Account
	void ParseBattleResult(const string &strJSON);///

	////��ȡSC����
	//string liveCheck();
	//string announceChat();
	//	//Add Room
	//string flashRoomList();
	//string AnnounceReady();
	//string Start();
	//string KickingPlayer();
	//	//Game Init
	//string battleGround();////
	//string nextStage();

	//string stageException();
	//string allInformation();
	//string gameEnd();
	//string event();
	//	//Round Start
	//string newRoundState();
	//	//Round Prepare
	//string newState();
	//	//Round Operation
	//string unitMove();
	//string unitAttack();
	//string useCard();
	//string useSkill();
	//string summon();
	//string announceEndTurn();
	//string specialEvent();
	//	//Game End Account
	//string mandatoryEndTurn();

	//�����������
	OrderType GetOrderType(const string &strJSON);
	//����Json��order֮��Ĳ�������ȫ������ȫ�������ʱ˳�����еĲ�����ָ�룬����NULL��β��
	void Parse(const string &strJSON, OrderType order, ...);

	CPVPConnect();
	~CPVPConnect();
private:
	void _SendToServer(string str);
	int _NowOrderID;	//��ǰ��ָ����

	//����Json��order֮��Ĳ�������ȫ������ȫ�������ʱ˳�����еĲ�����ָ�룬����NULL��β��
	string _MakeJsonString(OrderType order, ...);
};

