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
				battleEnemyManager->m_EnergyCount = menu.m_EnergyCount;          // 能量数量：最大值表示能量充满
				battleEnemyManager->m_MusicCount = menu.m_MusicCount;           // 音乐数量：假设最大音乐数量
				battleEnemyManager->m_HitCount = menu.m_HitCount;             // 命中次数：最大值表示全命中
				battleEnemyManager->m_LongPressCount = menu.m_LongPressCount;       // 长按次数：最大值表示所有长按都完成
				battleEnemyManager->m_MaxCombo = menu.m_MaxCombo;             // 最大连击：最大值表示完美连击
				battleEnemyManager->m_Score = menu.m_Score;                // 得分：最高分表示完美成绩
				battleEnemyManager->m_Block = menu.m_Block;                      // 阻挡次数：最好是 0，表示无阻挡
				battleEnemyManager->m_Blood = menu.m_Blood;                // 血量：最大值表示全血
				battleEnemyManager->m_LongPressHitCount = menu.m_LongPressHitCount;    // 长按命中次数：所有长按命中
				battleEnemyManager->m_HitEnemy = menu.m_HitEnemy;             // 击中敌人次数：假设所有敌人都击中
				battleEnemyManager->m_BossNearHit = menu.m_BossNearHit;          // Boss 近距离命中：全部命中
				battleEnemyManager->m_HurtMiss = menu.m_HurtMiss;                   // 受伤或错失：最好是 0，表示无失误
				battleEnemyManager->m_MissCombo = menu.m_MissCombo;                  // 连击错失次数：最好是 0，表示无中断
				battleEnemyManager->m_Recover = menu.m_Recover;              // 恢复次数：最大值表示最大恢复
				battleEnemyManager->m_MaxDamage = menu.m_MaxDamage;            // 最大伤害：假设理论最大伤害
				battleEnemyManager->m_Damage = menu.m_Damage;               // 总伤害：假设全程高输出
				battleEnemyManager->m_HideNote = menu.m_HideNote;             // 隐藏音符命中：假设所有隐藏音符命中
				battleEnemyManager->m_RedPoint = menu.m_RedPoint;             // 红点数量：假设所有红点都获得
				battleEnemyManager->m_BluePoint = menu.m_BluePoint;            // 蓝点数量：假设所有蓝点都获得

				// 判定结果，表示最好的结果
				battleEnemyManager->m_MissResult = menu.m_MissResult;                 // Miss：最好是 0，无失误
				battleEnemyManager->m_CoolResult = menu.m_CoolResult;                 // Cool：最好是 0，无较低判定
				battleEnemyManager->m_GreatResult = menu.m_GreatResult;                // Great：最好是 0，无中等级判定
				battleEnemyManager->m_PerfectResult = menu.m_PerfectResult;        // Perfect：最大值，所有判定都为完美
				battleEnemyManager->m_JumpOverResult = menu.m_JumpOverResult;       // 跳跃音符：假设全部成功跳跃
				battleEnemyManager->m_FeverResult = menu.m_FeverResult;          // Fever 模式：触发所有可能的 Fever 
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


