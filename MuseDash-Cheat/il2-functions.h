#pragma once
#include <cstdint>
#include<Windows.h>
#include "il2-types.h"
#include <string>
#define DO_APP_FUNC(ca, r, n, p) inline r (*n) p = (r (*) p)((bAddr) ? (bAddr + ca) : 0)
#define DO_UNI_FUNC(ca, r, n, p) inline r (*n) p = (r (*) p)((unityAddr) ? (unityAddr + ca) : 0)

inline HMODULE hBase = GetModuleHandleA("GameAssembly.dll");
inline uint64_t bAddr = (uint64_t)hBase;
inline HMODULE unityBase = GetModuleHandleA("UnityPlayer.dll");
inline uint64_t unityAddr = (uint64_t)unityBase;
namespace app
{
	DO_APP_FUNC(0xC1D940, bool, UnlockDLC, (__int64 a1));
	DO_APP_FUNC(0x1454C40, __int64, Update, (__int64 a1));

	DO_APP_FUNC(0x152C520, __int64, get_girlManager, ());//获取角色对象
    DO_APP_FUNC(0x1C08B30, __int64, get_instance, (void* object));//获取类的实例
	DO_APP_FUNC(0x127D988, __int64, IsHurt, ());//是否受伤

	//BattleEnemyManager
	DO_APP_FUNC(0x380D450, void, BattleEnemyManager_obj, ());//敌人管理
	DO_APP_FUNC(0x1587300,void, CreateBattleEnemy,(__int64 object,int idx));//创建敌人

	//BattleRoleAttributeComponent
	DO_APP_FUNC(0x15887A0, void, BattleRoleAttributeComponent_AddHp, (__int64 object, int value));//增加血量
	DO_APP_FUNC(0x158A500, void, BattleRoleAttributeComponent_Hurt, (__int64 object,int hurtValue, bool isAir));//受伤
	DO_APP_FUNC(0x158B250, __int64, BattleRoleAttributeComponent_get_instance, ()); 
	DO_APP_FUNC(0x365570,int, GetHp,(__int64 obj));//获取血量
	DO_APP_FUNC(0x158A3D0, int, GetHpMax, ());//获取最大血量
	DO_APP_FUNC(0x158B300,void, set_Hp,(__int64 obj,int value));//设置血量
	DO_APP_FUNC(0x1588D50,void, AttackScore, (__int64 object, int idx, int result, __int64 tno));//攻击分数





	//AbstractGirlManager
	DO_APP_FUNC(0x128E290, void, AbstractGirlManager_get_instance, ());//获取AbstractGirlManager实例


	//BattleHelper
	DO_APP_FUNC(0x1441E50, void, GameFinish, ());//结束游戏(单纯退出)


	//StatisticsManager
	DO_APP_FUNC(0x380D0F8, void, StatisticsManager_obj, ());// StatisticsManager类
	DO_APP_FUNC(0x150B180, void, OnBattleEnd, (_int64 a1, bool fail));//游戏结束(统计)
	DO_APP_FUNC(0x150C910, void, UploadScore, (__int64 object, Il2CppString* musicUid, int musicDifficulty, Il2CppString* roleUid, Il2CppString* elfinUid, int hp, int score, float accuracy, int combo, Il2CppString* evaluate, int miss, Il2CppString* stageInfoMd5));

	//TaskStageTarget
	DO_APP_FUNC(0x380D418,void, TaskStageTarget_obj, ());//TaskStageTarget类
	DO_APP_FUNC(0x1591960,float, GetAccuracy,(__int64 a1));//获取准zz确度
	DO_APP_FUNC(0x1591430, void, AddScore, (__int64 a1, int value, int id, __int64 noteType, bool isAir, float time));//增加分数
	DO_APP_FUNC(0x434140,int, GetMiss,(__int64 a1));//获取miss次数
	DO_APP_FUNC(0x3B6CF0, int, GetComboMiss, (__int64 a1));//获取连击中断次数,越小越好
	DO_APP_FUNC(0x362D80,int, GetHitCount,(__int64 a1));//获取击中次数
	DO_APP_FUNC(0x1591DA0, float, GetHitPercent, (__int64 a1,  int result));//获取命中率
	DO_APP_FUNC(0x354750, int, GetComboMax, (__int64 a1));//获取最大连击数

	//SDKManager
	DO_APP_FUNC(0xB3A8B0,void, ShowDialog, (__int64 a1,const Dictionary& extra, Callback callback));//显示对话框
	DO_APP_FUNC(0x10E9A20, __int64, GetSDKManager,());


	//AchievementManager
	DO_APP_FUNC(0x17D4FC0, void, SetUserAchievement, (__int64 object, long achievementId, byte percentComplete, __int64));


	//StageBattleComponent 核心战斗管理类
	DO_APP_FUNC(0x380CC20, void, StageBattleComponent_obj, ());//StageBattleComponent类
	DO_APP_FUNC(0x12A2B50,void,End,(__int64 obj));//结束战斗(结算)
	DO_APP_FUNC(0x12A25C0,void, ActivityReward,(__int64 obj, Il2CppString* musicUid, bool isHalloweenMap));//活动奖励

	//il2cpp-api
	DO_APP_FUNC(0xAC120,Il2CppString*, il2cpp_string_new, (const char* str));//创建il2cpp字符串


	//StageManager 
	DO_APP_FUNC(0x380D130, void, StageManager_obj, ());//StageManager类
	DO_APP_FUNC(0x150AE00, void, UnlockStage,(__int64 object, bool isNew));//解锁关卡
	DO_APP_FUNC(0x150AC80, void, UnlockSpecifyStage, (__int64 object, Il2CppString* uid,bool isNew));//解锁关卡


	


	//time
	DO_UNI_FUNC(0x17F6C18, void, timeScale_base, ());//全局加速基址
	DO_APP_FUNC(0x1DC1800,float, get_deltaTime,());//获取时间间隔,


	//DBConfigALBUM
	DO_APP_FUNC(0x1445030, void, GetAllMusicUids, (__int64 object, Il2CppArray* Array, bool clear));//获取所有音乐uid


	//class_ConfigManager
	DO_APP_FUNC(0x380CF58, void, ConfigManager_obj, ());//ConfigManager类
	DO_APP_FUNC(0x1474990, __int64, GetConfigObject, (__int64 object, int albumJsonIndex, __int64 a3));//获取对象
	DO_APP_FUNC(0x380CA58, void, GetConfigObjectParameter, ());//GetConfigObject的第三个参数


	//GameAccountSystem 

	DO_APP_FUNC(0x1466EE0, void, SendRealNamePhoneCode, (__int64 object,Il2CppString* phoneNumber, __int64 successCallback, __int64 failCallback));//发送验证码
	DO_APP_FUNC(0x1468070, __int64, GameAccount_get_instance, ());//获取GameAccount实例

	//misc
	DO_APP_FUNC(0x15F2880, Il2CppString*, get_md5, (__int64 obj));
	DO_APP_FUNC(0x3805B08, void, md5_obj, ());//md5类


	//ItemManager
    DO_APP_FUNC(0x380D2D8,void, ItemManager_obj,());//ItemManager类
	DO_APP_FUNC(0x152D080, void, AddItem, (__int64 obj,Il2CppString* type, int index, int count));
	DO_APP_FUNC(0x15317A0, void, Reward, (__int64 obj, int count, bool jumpCheckAchievement));
	DO_APP_FUNC(0x1531AA0, void, SendUnlockItemMessage, (__int64 obj));//发送解锁物品消息
	DO_APP_FUNC(0x1531730,void, RewardItemsInit,(__int64 obj));//初始化奖励物品
	DO_APP_FUNC(0x152D920, void, AddSkin, (__int64 obj, Il2CppString* rarity));//添加皮肤
	DO_APP_FUNC(0x37A9D40, void, rarity, ());
	




}