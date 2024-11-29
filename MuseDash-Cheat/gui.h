#pragma once
struct  menu_t
{
	bool showgui = true;
	bool UnlockDLC = false;
	bool GodMode = true;
	bool GlobalSpeed = false;
	bool HundredPercentAccuracy = true;
	bool PreventUploadScore = false;
	bool PerfectAttack = false;

	float GlobalSpeed_value = 2.0f;



	//TaskStageTarget
	int m_EnergyCount= 100000;
	int m_MusicCount= 100000;
	int m_HitCount= 100000;
	int m_LongPressCount= 100000;
	int m_MaxCombo= 100000;
	int m_Score= 100000;
	int m_Block=0; 
	int m_Blood= 100000;
	int m_LongPressHitCount= 100000;
	int m_HitEnemy= 100000;
	int m_BossNearHit= 100000;
	int m_HurtMiss=0; 
	int m_MissCombo=0; 
	int m_Recover= 100000;
	int m_MaxDamage= 100000;
	int m_Damage= 100000;
	int m_HideNote= 100000;
	int m_RedPoint= 100000;
	int m_BluePoint= 100000;
	int m_MissResult=0; 
	int m_CoolResult=0; 
	int m_GreatResult=0; 
	int m_PerfectResult=100000; 
	int m_JumpOverResult= 100000;
	int m_FeverResult= 100000;
};
extern menu_t menu;