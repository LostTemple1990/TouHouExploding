#pragma once
#include "SceneBattle.h"
#include "PVPConnect.h"
#include "Effects.h"

/*
	��սģʽ
*/

class CPVPMode : public CSceneBattle
{
public:
	virtual bool init() override;
	CREATE_FUNC(CPVPMode);


	CPVPMode();
	~CPVPMode();
};