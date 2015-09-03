#pragma once
#include "CSceneBattle.h"
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

	void StartYourTurn();
	void EndYourTurn();
	void SelectUnit();
	void SelectPosition();
};