#include "Skill.h"
extern std::mutex mutexSkill;

bool SkillOperate::g_bRunningSkill = false;

bool CSkill::RunSkill()
{
	SkillOperate::mutexSkill.lock();
	if (!g_bRunningSkill)
	{
		//initState
		g_bClickDialogButton = false;
		//
		std::thread thrSkill(&CSkill::OnSkillStart, this);
		thrSkill.detach();
	}
	else{
		SkillOperate::mutexSkill.unlock();
		return true;
	}
	SkillOperate::mutexSkill.unlock();
	return false;
}

void CSkill_1::OnSkillStart()
{
	auto unit = SelectUnit();
	bool b = ChessboardDialog(WStrToUTF8(L"�Ƿ�֧��1B�Ըõ�λ��ɶ����2���˺���"));
	NormalDamage(unit, 2);
	g_bRunningSkill = false;
}
