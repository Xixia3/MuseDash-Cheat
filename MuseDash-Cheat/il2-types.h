#pragma once
#include<vector>
#include <unordered_map>
#include <functional>
#include <any>
#include<string>

#define il2cpp_string_to_wchar(ptr) (((wchar_t*)((Il2CppString*)ptr)->chars))
#pragma region IL2CPPInternalTypes

typedef uint16_t Il2CppChar;
typedef uintptr_t il2cpp_array_size_t;
typedef int32_t il2cpp_array_lower_bound_t;

typedef struct Il2CppObject {
    union {
        void* klass;
        void* vtable;
    } Il2CppClass;
    void* monitor;
} Il2CppObject;

typedef struct Il2CppString {
    Il2CppObject object;
    int32_t length;
    Il2CppChar chars[32];
} Il2CppString;

typedef struct Il2CppArrayBounds {
    char pad_0x18[0x18];
    uint32_t length;
    char pad_0x4[0x4];
    Il2CppString* StartingAddress;
} Il2CppArrayBounds;


typedef struct Il2CppArray
{
    Il2CppObject obj;
    Il2CppArrayBounds* bounds;
    il2cpp_array_size_t max_length;
} Il2CppArray;
struct Vector3
{
	float x, y, z;
};
class BattleRoleAttributeComponent
{
public:
    char pad_10[0x10];
     int m_Hp; // 0x10
     int hurt; // 0x14
     int m_JudgeState; // 0x18
     int early; // 0x1C
     int late; // 0x20
     char pad_4[0x4];//0x24
     __int64 m_ZombiaCoroutine1; // 0x28
     __int64 m_ZombiaCoroutine2; // 0x30
     bool m_IsShowLateEarly; // 0x38
};


class TaskStageTarget
{
	// Fields
public:
	char pad_0x10[0x10]; //0x0000
	int m_EnergyCount; // 0x10
	int m_MusicCount; // 0x14
	int m_HitCount; // 0x18
	int m_LongPressCount; // 0x1C
	int m_MaxCombo; // 0x20
	int m_Score; // 0x24
	int m_Block; // 0x28
	int m_Blood; // 0x2C
	int m_LongPressHitCount; // 0x30
	int m_HitEnemy; // 0x34
	int m_BossNearHit; // 0x38
	int m_HurtMiss; // 0x3C
	int m_MissCombo; // 0x40
	int m_Recover; // 0x44
	int m_MaxDamage; // 0x48
	int m_Damage; // 0x4C
	int m_HideNote; // 0x50
	int m_RedPoint; // 0x54
	int m_BluePoint; // 0x58
	int m_MissResult; // 0x5C
	int m_CoolResult; // 0x60
	int m_GreatResult; // 0x64
	int m_PerfectResult; // 0x68
	int m_JumpOverResult; // 0x6C
	int m_FeverResult; // 0x70
};

struct MusicUidDefine // TypeDefIndex: 15404
{
    // Fields
    const std::string random = "?";
    const std::string blackest_luxury_car = "0-18";
    const std::string i_dont_care_about_christmas_though = "0-47";
    const std::string mujinku_vacuum_track_add8e6 = "0-28";
    const std::string heart_pounding_flight = "0-5";
    const std::string snooze = "43-19";
    const std::string kuishinbo_hacker = "43-20";
    const std::string inu_no_outa = "43-21";
    const std::string gospel = "43-23";
    const std::string the_day_we_become_family = "43-30";
    const std::string yume_ou_mono_yo_default = "0-54";
    const std::string lights_of_muse = "0-11";
    const std::string umpopoff = "0-41";
    const std::string mopemope = "0-45";
    const std::string goodtek = "4-5";
    const std::string conflict = "5-1";
    const std::string xing = "5-3";
    const std::string stargazer = "6-4";
    const std::string lyrith = "7-4";
    const std::string trippers_feeling = "8-4";
    const std::string sweet_witch_girl = "8-3";
    const std::string infinite_enerzy_overdoze = "20-2";
    const std::string freedom_dive = "22-1";
    const std::string ginevra = "28-1";
    const std::string fujin_rumble = "29-1";
    const std::string hg_makaizou_polyvinyl_shounen = "29-3";
    const std::string ouroboros_twin_stroke_of_the_end = "29-5";
    const std::string medusa = "31-1";
    const std::string square_lake = "31-5";
    const std::string happiness_breeze = "33-2";
    const std::string chrome_vox = "33-3";
    const std::string chaos_glitch = "33-12";
    const std::string battle_no1 = "34-1";
    const std::string cthugha = "34-2";
    const std::string twinkle_magic = "34-3";
    const std::string comet_coaster = "34-4";
    const std::string xodus = "34-5";
    const std::string marenol = "35-1";
    const std::string dataerr0r = "35-4";
    const std::string igallta = "38-2";
    const std::string qu_jianhai_de_rizi = "39-0";
    const std::string fm_17314_sugar_radio_music = "39-8";
    const std::string super_battleworn_insomniac = "41-0";
    const std::string heracles = "41-5";
    const std::string amatsumikaboshi = "43-1";
    const std::string can_you_feel_it = "43-5";
    const std::string with_u = "45-1";
    const std::string isouten = "46-5";
    const std::string cyaegha = "47-3";
    const std::string neko_jarashi = "46-3";
    const std::string uad = "48-6";
    const std::string bamboo = "36-2";
    const std::string doppelganger = "50-4";
    const std::string kui = "51-5";
    const std::string sand_maze = "43-13";
    const std::string on_and_on = "53-0";
    const std::string plucky_race = "53-3";
    const std::string people_people = "58-0";
    const std::string hana_to_yuki_to_drumn_bass = "60-4";
    const std::string buttoba_supernova = "61-2";
    const std::string rush_hour = "61-3";
    const std::string tanuki_step = "64-1";
    const std::string kawaiku_kareini_utyuukaitou = "64-4";
    const std::string mew_mew_magical_summer = "64-7";
    const std::string world_invader = "61-5";
    const std::string satellite = "62-4";
    const std::string otoge_boss_kyoku = "43-33";
    const std::string syzygy = "43-35";
    const std::string rainy_angel = "67-0";
    const std::string fuzzy_navel = "68-2";
    const std::string twisted_escape = "68-4";
    const std::string hatsune_tenchi_kaibyaku_shinwa = "66-5";
    const std::string niki_tousen = "43-53";
    const std::string alter_luna = "43-52";
    const std::string how_to_make_otoge_kyoku = "72-2";
    const std::string re_re = "72-3";
    const std::string world_vanquisher = "74-1";
    const std::string the_wheel_to_the_right = "74-3";
    const std::string climax = "74-4";
    const std::string spiders_thread = "74-5";
    const std::string echo_over_you_default = "0-56";
    const std::string the_whole_rest = "77-1";
    const std::string imaginary_world = "0-21";
    const std::string altale = "8-0";
    const std::string abatement = "78-4";
    const std::string melusia = "78-2";
    const std::string collapsar = "78-8";
    const std::string achromic_riddle = "79-3";
    const std::string bad_apple = "42-0";
    const std::string iro_wa_nioedo_chirinuru_wo = "42-1";
    const std::string cirnos_perfect_math_class = "42-2";
    const std::string hiiro_gekka_kyoushou_no_zetsu = "42-3";
    const std::string flowery_moonlit_night = "42-4";
    const std::string unconscious_requiem = "42-5";
    const std::string night_of_knights = "43-3";
    const std::string tsuki_ni_murakumo_hana_ni_kaze = "55-0";
    const std::string pachurizu_best_hit_gsk = "55-1";
    const std::string koishi_ga_monosugoi_uta = "55-2";
    const std::string kakoinakiyo_ha_ichigo_no_tsukikage = "55-3";
    const std::string psychedelic_kizakura_domei = "55-4";
    const std::string itazura_sensation = "55-5";
    const std::string furanchan_ga_monosugoi_uta = "43-18";
    const std::string samayoyino_mei_amatsu = "69-0";
    const std::string internet_survivor = "69-1";
    const std::string shuki_rairai = "69-2";
    const std::string hello_hell = "69-3";
    const std::string calamity_fortune = "69-4";
    const std::string tsuru_pettan = "69-5";
    const std::string san_you_sei_say_ya = "43-42";
    const std::string yukemuri_tamaonsen_ii = "43-43";
    const std::string saishuu_kichiku_imouto_flandre_s = "80-0";
    const std::string kachoufuugetsu = "80-1";
    const std::string maid_heart_is_a_puppet = "80-2";
    const std::string trance_dance_anarcky = "80-3";
    const std::string fairy_stage = "80-4";
    const std::string scarlet_keisatu_no_ghetto_patro_24_zi = "80-5";
    const std::string necromantic = "43-60";
    const std::string strawberry_godzilla = "25-3";
    const std::string milk = "0-36";
    const std::string say_fanfare = "0-44";
    const std::string girly_cupid = "30-0";
    const std::string sheep_in_the_light = "30-1";
    const std::string breaker_city = "30-2";
    const std::string mezame_eurythmics = "0-50";
    const std::string shenri_kuaira_repeat = "0-51";
    const std::string internet_overdose = "0-52";
    const std::string irreplaceable = "21-2";
    const std::string danshi_in_virtualand = "51-4";
    const std::string yume_ou_mono_yo = "0-53";
    const std::string echo_over_you = "0-55";
    const std::string queen_aluett = "43-16";
    const std::string mushdash_have_error = "61-0";
    const std::string unknown_mother_goose = "66-8";
    const std::string retto_joto = "70-0";
    const std::string telecaster_b_boy = "70-1";
    const std::string iya_iya_iya = "70-2";
    const std::string nenene = "70-3";
    const std::string peropero_aniki_ranbu = "72-0";
};
class BattleEnemyManager
{
public:
    char pad_10[0x10];
     int m_CurrentGenIdx; // 0x10
     //int[] m_Hp; // 0x18
     //byte[] m_Evaluates; // 0x20
     //bool[] m_LeftRight; // 0x28
     char pad_24[0x24];
     float damageRatio; // 0x38
};
using Dictionary = std::unordered_map<std::string, std::any>;
using Callback = std::function<void(int, std::any)>;