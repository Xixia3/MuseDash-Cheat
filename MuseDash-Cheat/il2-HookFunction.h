#include"il2-functions.h"
#include"il2-types.h"
#include"HookManager.h"
#include"includes.h"



Il2CppArray* example;
extern bool sethp ;
extern bool GameFinish ;
extern bool ModifyToPerfectScore;

Il2CppString* md5;
namespace Hook
{
	bool UnlockAllDLC(__int64 a1)
	{
		if (menu.UnlockDLC)
		{
			return true;
		}
		return CALL_ORIGIN(UnlockAllDLC, a1);
	}

	float GetAccuracy(__int64 a1)
	{
		if(menu.HundredPercentAccuracy)return 1;
		else return CALL_ORIGIN(GetAccuracy, a1);
	}
	void GetAllMusicUids( __int64 object, Il2CppArray* Array, bool clear)
	{
		example = Array;
		return CALL_ORIGIN(GetAllMusicUids, object, Array, clear);
	}
	void UploadScore(__int64 object, Il2CppString* musicUid, int musicDifficulty, Il2CppString* roleUid, Il2CppString* elfinUid, int hp, int score, float accuracy, int combo, Il2CppString* evaluate, int miss, Il2CppString* stageInfoMd5)
	{
	     if(menu.PreventUploadScore)return;
		CALL_ORIGIN(UploadScore,object, musicUid, musicDifficulty, roleUid, elfinUid, hp, score, accuracy, combo, evaluate, miss, stageInfoMd5);
	}
	void AttackScore(__int64 object, int idx, int result, __int64 tno)
	{
		if (menu.PerfectAttack)
		{
			result = 4;
		}
		CALL_ORIGIN(AttackScore, object, idx, result, tno);
	}

}
namespace GameUpdate
{
	__int64  LevelUpdate(__int64 a1)
	{
	/*	if (sethp)
		{
			app::BattleRoleAttributeComponent_AddHp(app::BattleRoleAttributeComponent_get_instance(), 1000);
			sethp = false;
		}*/
		if (GameFinish)
		{
			if (*(int*)app::StageBattleComponent_obj)
			{
				app::End(app::get_instance(*(void**)app::StageBattleComponent_obj));
			}
			GameFinish = false;
		}
		if (ModifyToPerfectScore)
		{
			TaskStageTarget* battleEnemyManager = (TaskStageTarget*)app::get_instance(*(void**)app::TaskStageTarget_obj);
			if (battleEnemyManager)
			{
				battleEnemyManager->m_EnergyCount = menu.m_EnergyCount;          // �������������ֵ��ʾ��������
				battleEnemyManager->m_MusicCount = menu.m_MusicCount;           // �������������������������
				battleEnemyManager->m_HitCount = menu.m_HitCount;             // ���д��������ֵ��ʾȫ����
				battleEnemyManager->m_LongPressCount = menu.m_LongPressCount;       // �������������ֵ��ʾ���г��������
				battleEnemyManager->m_MaxCombo = menu.m_MaxCombo;             // ������������ֵ��ʾ��������
				battleEnemyManager->m_Score = menu.m_Score;                // �÷֣���߷ֱ�ʾ�����ɼ�
				battleEnemyManager->m_Block = menu.m_Block;                      // �赲����������� 0����ʾ���赲
				battleEnemyManager->m_Blood = menu.m_Blood;                // Ѫ�������ֵ��ʾȫѪ
				battleEnemyManager->m_LongPressHitCount = menu.m_LongPressHitCount;    // �������д��������г�������
				battleEnemyManager->m_HitEnemy = menu.m_HitEnemy;             // ���е��˴������������е��˶�����
				battleEnemyManager->m_BossNearHit = menu.m_BossNearHit;          // Boss ���������У�ȫ������
				battleEnemyManager->m_HurtMiss = menu.m_HurtMiss;                   // ���˻��ʧ������� 0����ʾ��ʧ��
				battleEnemyManager->m_MissCombo = menu.m_MissCombo;                  // ������ʧ����������� 0����ʾ���ж�
				battleEnemyManager->m_Recover = menu.m_Recover;              // �ָ����������ֵ��ʾ���ָ�
				battleEnemyManager->m_MaxDamage = menu.m_MaxDamage;            // ����˺���������������˺�
				battleEnemyManager->m_Damage = menu.m_Damage;               // ���˺�������ȫ�̸����
				battleEnemyManager->m_HideNote = menu.m_HideNote;             // �����������У���������������������
				battleEnemyManager->m_RedPoint = menu.m_RedPoint;             // ����������������к�㶼���
				battleEnemyManager->m_BluePoint = menu.m_BluePoint;            // ���������������������㶼���

				// �ж��������ʾ��õĽ��
				battleEnemyManager->m_MissResult = menu.m_MissResult;                 // Miss������� 0����ʧ��
				battleEnemyManager->m_CoolResult = menu.m_CoolResult;                 // Cool������� 0���޽ϵ��ж�
				battleEnemyManager->m_GreatResult = menu.m_GreatResult;                // Great������� 0�����еȼ��ж�
				battleEnemyManager->m_PerfectResult = menu.m_PerfectResult;        // Perfect�����ֵ�������ж���Ϊ����
				battleEnemyManager->m_JumpOverResult = menu.m_JumpOverResult;       // ��Ծ����������ȫ���ɹ���Ծ
				battleEnemyManager->m_FeverResult = menu.m_FeverResult;          // Fever ģʽ���������п��ܵ� Fever 
			}
		}
		return CALL_ORIGIN(LevelUpdate, a1);

	}
	float FPSUpdate()
	{
		if(menu.GlobalSpeed) *(float*)(*(__int64*)(app::timeScale_base)+0xFC)=menu.GlobalSpeed_value;
		return CALL_ORIGIN(FPSUpdate);
	}
}


