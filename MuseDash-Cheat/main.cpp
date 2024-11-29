#include "includes.h"
#include"Font.h"
#include"il2-functions.h"
#include"gui.h"
#include"HookManager.h"
#include"il2-types.h"
#include"il2-HookFunction.h"
extern LRESULT ImGui_ImplWin32_WndProcHandler(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);
void ChangeOptions();

Present oPresent;
HWND window = NULL;
WNDPROC oWndProc;
ID3D11Device* pDevice = NULL;
ID3D11DeviceContext* pContext = NULL;
ID3D11RenderTargetView* mainRenderTargetView;



extern Il2CppArray* example;
ImFont* Font;
ImFont* Font_Big;

menu_t menu;
 bool sethp = false;
 bool GameFinish = false;
 bool ModifyToPerfectScore = false;

void InitImGui()
{
	ImGui::CreateContext();
	ImGuiIO& io = ImGui::GetIO();
	io.ConfigFlags = ImGuiConfigFlags_NoMouseCursorChange;
	ImGui_ImplWin32_Init(window);
	ImGui_ImplDX11_Init(pDevice, pContext);
}

LRESULT __stdcall WndProc(const HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {

	if (true && ImGui_ImplWin32_WndProcHandler(hWnd, uMsg, wParam, lParam))
		return true;

	return CallWindowProc(oWndProc, hWnd, uMsg, wParam, lParam);
}

bool init = false;
int Tab = 0;
enum Tab
{
	Player,

};
HRESULT __stdcall hkPresent(IDXGISwapChain* pSwapChain, UINT SyncInterval, UINT Flags)
{
	if (!init)
	{
		if (SUCCEEDED(pSwapChain->GetDevice(__uuidof(ID3D11Device), (void**)&pDevice)))
		{
			pDevice->GetImmediateContext(&pContext);
			DXGI_SWAP_CHAIN_DESC sd;
			pSwapChain->GetDesc(&sd);
			window = sd.OutputWindow;
			ID3D11Texture2D* pBackBuffer;
			pSwapChain->GetBuffer(0, __uuidof(ID3D11Texture2D), (LPVOID*)&pBackBuffer);
			pDevice->CreateRenderTargetView(pBackBuffer, NULL, &mainRenderTargetView);
			pBackBuffer->Release();
			oWndProc = (WNDPROC)SetWindowLongPtr(window, GWLP_WNDPROC, (LONG_PTR)WndProc);
			InitImGui();
			//字体
			ImGuiIO& io = ImGui::GetIO(); (void)io;
			ImFontConfig Font_cfg;
			Font_cfg.FontDataOwnedByAtlas = false;
			Font = io.Fonts->AddFontFromMemoryTTF((void*)Font_data, Font_size, 18.0f, &Font_cfg, io.Fonts->GetGlyphRangesChineseFull());
			Font_Big = io.Fonts->AddFontFromMemoryTTF((void*)Font_data, Font_size, 24.0f, &Font_cfg, io.Fonts->GetGlyphRangesChineseFull());


			//颜色
			ImGuiStyle& Style = ImGui::GetStyle();
			auto Color = Style.Colors;
			Style.ChildRounding = 8.0f;
			Style.FrameRounding = 5.0f;

			Style.FramePadding = ImVec2(4.0f, 4.0f);
			Style.ItemSpacing = ImVec2(10.0f, 8.0f); 


			Color[ImGuiCol_Button] = ImColor(192, 51, 74, 255);
			Color[ImGuiCol_ButtonHovered] = ImColor(212, 71, 94, 255);
			Color[ImGuiCol_ButtonActive] = ImColor(172, 31, 54, 255);

			Color[ImGuiCol_FrameBg] = ImColor(54, 54, 54, 150);
			Color[ImGuiCol_FrameBgActive] = ImColor(42, 42, 42, 150);
			Color[ImGuiCol_FrameBgHovered] = ImColor(100, 100, 100, 150);

			Color[ImGuiCol_CheckMark] = ImColor(192, 51, 74, 255);

			Color[ImGuiCol_SliderGrab] = ImColor(192, 51, 74, 255);
			Color[ImGuiCol_SliderGrabActive] = ImColor(172, 31, 54, 255);

			Color[ImGuiCol_Header] = ImColor(192, 51, 74, 255);
			Color[ImGuiCol_HeaderHovered] = ImColor(212, 71, 94, 255);
			Color[ImGuiCol_HeaderActive] = ImColor(172, 31, 54, 255);

			

			init = true;


		}

		else
			return oPresent(pSwapChain, SyncInterval, Flags);
	}

	ImGui_ImplDX11_NewFrame();
	ImGui_ImplWin32_NewFrame();
	ImGui::NewFrame();
	if (GetAsyncKeyState(VK_INSERT) & 1)
	{
		menu.showgui = !menu.showgui;
		Sleep(100);
	}
	ChangeOptions();
	if (menu.showgui)
	{
		ImGuiStyle& Style = ImGui::GetStyle();
		auto Color = Style.Colors;


		ImGui::PushStyleVar(ImGuiStyleVar_WindowPadding, ImVec2(0, 0));
		ImGui::PushStyleVar(ImGuiStyleVar_WindowBorderSize, 0.0f); 
		ImGui::Begin(u8"Ciallo Cheat", NULL, ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoSavedSettings);//开始绘制窗口
		ImVec2 WindowSize = { 1200.0f,900.0f };
		ImGui::SetWindowSize(WindowSize);//设置窗口大小
		ImGui::PopStyleVar(2);

		{
			ImGui::GetWindowDrawList()->AddLine({ ImGui::GetWindowPos().x + 1020.0f,ImGui::GetWindowPos().y + 10.0f }, { ImGui::GetWindowPos().x + 1020.0f,ImGui::GetWindowPos().y + 880.0f }, ImColor(100, 100, 100, 255));

			ImGui::SetCursorPos({ WindowSize.x - 170,20.0f });
			ImGui::PushFont(Font_Big);
			ImGui::TextColored(Color[ImGuiCol_Button], u8"Ciallo Cheat \u9B08");
			ImGui::PopFont();
			ImGui::SetCursorPos({ WindowSize.x - 170,65.0f });

			ImGui::PushStyleColor(ImGuiCol_Button, Tab == Tab::Player ? Color[ImGuiCol_Button] : ImVec4(0.0f, 0.0f, 0.0f, 0.0f));
			if (ImGui::Button(u8"人物", { 150.0f,40.0f }))
			{
				Tab = Tab::Player;
			}
			ImGui::PopStyleColor();

			ImGui::PushStyleColor(ImGuiCol_Button, ImVec4(0.0f, 0.0f, 0.0f, 0.0f));
			ImGui::SetCursorPos({ WindowSize.x - 170,365.0f });
			if (ImGui::Button(u8"退出", { 150.0f,40.0f }))
			{
				ExitProcess(0);
			}
			ImGui::PopStyleColor();

		}


		ImGui::SetCursorPos({ 10.0f,10.0f });
		ImGui::BeginChild(u8"Fucking", { 1000.0f , 870.0f }, true);
		switch (Tab)
		{
		case Tab::Player:

			ImGui::PushFont(Font_Big);
			ImGui::BulletText(u8"人物");
			ImGui::PopFont();
			ImGui::Separator();
			ImGui::Checkbox(u8"无敌", &menu.GodMode);
			ImGui::Checkbox(u8"解锁全部DLC", &menu.UnlockDLC);
			if (ImGui::Checkbox(u8"全局加速", &menu.GlobalSpeed))
			{
				if (!menu.GlobalSpeed) *(float*)(*(__int64*)(app::timeScale_base)+0xFC) = 1.0f;
			}
			ImGui::SameLine();
			ImGui::SliderFloat(u8"速度", &menu.GlobalSpeed_value,1.0f,100.0f);
			ImGui::Checkbox(u8"攻击结果始终为Perfect", &menu.PerfectAttack);
			ImGui::NewLine();
			ImGui::NewLine();
			ImGui::Text(u8"关卡数据");
			if (ImGui::Button(u8"立刻结算本局游戏"))
			{
				GameFinish = true;
			}
			ImGui::SameLine();
			if (ImGui::Button(u8"修改成绩"))
			{
				ModifyToPerfectScore = true;
			}
			ImGui::SameLine();
			ImGui::Checkbox(u8"阻止上传成绩", &menu.PreventUploadScore);

			static const float item_width = 200.0f; // 每个输入框宽度
			static const int items_per_row = 3;     // 每行 3 个输入框

			// 显示输入框
			int index = 0; // 当前控件索引，用于计算行布局

			ImGui::SetNextItemWidth(item_width);
			ImGui::InputInt("Energy Count", &menu.m_EnergyCount, 0, 0);
			if (++index % items_per_row != 0) ImGui::SameLine();

			ImGui::SetNextItemWidth(item_width);
			ImGui::InputInt("Music Count", &menu.m_MusicCount, 0, 0);
			if (++index % items_per_row != 0) ImGui::SameLine();

			ImGui::SetNextItemWidth(item_width);
			ImGui::InputInt("Hit Count", &menu.m_HitCount, 0, 0);
			if (++index % items_per_row != 0) ImGui::SameLine();

			// ------------------------------------

			ImGui::SetNextItemWidth(item_width);
			ImGui::InputInt("Long Press Count", &menu.m_LongPressCount, 0, 0);
			if (++index % items_per_row != 0) ImGui::SameLine();

			ImGui::SetNextItemWidth(item_width);
			ImGui::InputInt("Max Combo", &menu.m_MaxCombo, 0, 0);
			if (++index % items_per_row != 0) ImGui::SameLine();

			ImGui::SetNextItemWidth(item_width);
			ImGui::InputInt("Score", &menu.m_Score, 0, 0);
			if (++index % items_per_row != 0) ImGui::SameLine();

			// ------------------------------------

			ImGui::SetNextItemWidth(item_width);
			ImGui::InputInt("Block", &menu.m_Block, 0, 0);
			if (++index % items_per_row != 0) ImGui::SameLine();

			ImGui::SetNextItemWidth(item_width);
			ImGui::InputInt("Blood", &menu.m_Blood, 0, 0);
			if (++index % items_per_row != 0) ImGui::SameLine();

			ImGui::SetNextItemWidth(item_width);
			ImGui::InputInt("Long Press Hit Count", &menu.m_LongPressHitCount, 0, 0);
			if (++index % items_per_row != 0) ImGui::SameLine();

			// ------------------------------------

			ImGui::SetNextItemWidth(item_width);
			ImGui::InputInt("Hit Enemy", &menu.m_HitEnemy, 0, 0);
			if (++index % items_per_row != 0) ImGui::SameLine();

			ImGui::SetNextItemWidth(item_width);
			ImGui::InputInt("Boss Near Hit", &menu.m_BossNearHit, 0, 0);
			if (++index % items_per_row != 0) ImGui::SameLine();

			ImGui::SetNextItemWidth(item_width);
			ImGui::InputInt("Hurt Miss", &menu.m_HurtMiss, 0, 0);
			if (++index % items_per_row != 0) ImGui::SameLine();

			// ------------------------------------

			ImGui::SetNextItemWidth(item_width);
			ImGui::InputInt("Miss Combo", &menu.m_MissCombo, 0, 0);
			if (++index % items_per_row != 0) ImGui::SameLine();

			ImGui::SetNextItemWidth(item_width);
			ImGui::InputInt("Recover", &menu.m_Recover, 0, 0);
			if (++index % items_per_row != 0) ImGui::SameLine();

			ImGui::SetNextItemWidth(item_width);
			ImGui::InputInt("Max Damage", &menu.m_MaxDamage, 0, 0);
			if (++index % items_per_row != 0) ImGui::SameLine();

			// ------------------------------------

			ImGui::SetNextItemWidth(item_width);
			ImGui::InputInt("Damage", &menu.m_Damage, 0, 0);
			if (++index % items_per_row != 0) ImGui::SameLine();

			ImGui::SetNextItemWidth(item_width);
			ImGui::InputInt("Hide Note", &menu.m_HideNote, 0, 0);
			if (++index % items_per_row != 0) ImGui::SameLine();

			ImGui::SetNextItemWidth(item_width);
			ImGui::InputInt("Red Point", &menu.m_RedPoint, 0, 0);
			if (++index % items_per_row != 0) ImGui::SameLine();

			// ------------------------------------

			ImGui::SetNextItemWidth(item_width);
			ImGui::InputInt("Blue Point", &menu.m_BluePoint, 0, 0);
			if (++index % items_per_row != 0) ImGui::SameLine();

			ImGui::SetNextItemWidth(item_width);
			ImGui::InputInt("Miss Result", &menu.m_MissResult, 0, 0);
			if (++index % items_per_row != 0) ImGui::SameLine();

			ImGui::SetNextItemWidth(item_width);
			ImGui::InputInt("Cool Result", &menu.m_CoolResult, 0, 0);
			if (++index % items_per_row != 0) ImGui::SameLine();

			// ------------------------------------

			ImGui::SetNextItemWidth(item_width);
			ImGui::InputInt("Great Result", &menu.m_GreatResult, 0, 0);
			if (++index % items_per_row != 0) ImGui::SameLine();

			ImGui::SetNextItemWidth(item_width);
			ImGui::InputInt("Perfect Result", &menu.m_PerfectResult, 0, 0);
			if (++index % items_per_row != 0) ImGui::SameLine();

			ImGui::SetNextItemWidth(item_width);
			ImGui::InputInt("Jump Over Result", &menu.m_JumpOverResult, 0, 0);
			if (++index % items_per_row != 0) ImGui::SameLine();

			// ------------------------------------

			ImGui::SetNextItemWidth(item_width);
			ImGui::InputInt("Fever Result", &menu.m_FeverResult, 0, 0);


			ImGui::NewLine();
			ImGui::Text(u8"结算时数据");
			ImGui::Checkbox(u8"100%准确率", &menu.HundredPercentAccuracy);
			if (ImGui::Button(u8"test"))
			{
				std::hex;
				std::cout << "StageBattleComponent" << app::get_instance(*(void**)app::StageBattleComponent_obj) << std::endl;
				std::cout << "BattleRoleAttributeComponent" << app::BattleRoleAttributeComponent_get_instance() << std::endl;
			}
			break;
		}
		ImGui::EndChild();
		ImGui::End();
	}
	ImGui::Render();
	pContext->OMSetRenderTargets(1, &mainRenderTargetView, NULL);
	ImGui_ImplDX11_RenderDrawData(ImGui::GetDrawData());
	return oPresent(pSwapChain, SyncInterval, Flags);
}

DWORD WINAPI MainThread(LPVOID lpReserved)
{
	if(!bAddr)
	{
		MessageBox(0, "GameAssembly.dll not found", "Error", MB_ICONERROR);
		ExitProcess(0);
	}
	bool init_hook = false;
	do
	{
		if (kiero::init(kiero::RenderType::D3D11) == kiero::Status::Success)
		{
			kiero::bind(8, (void**)&oPresent, hkPresent);
			init_hook = true;
		}
	} while (!init_hook);
	AllocConsole();
	freopen_s((FILE**)stdout, "CONOUT$", "w", stdout);
	HookManager::install(app::Update, GameUpdate::LevelUpdate);
	HookManager::install(app::get_deltaTime, GameUpdate::FPSUpdate);
	HookManager::install(app::UnlockDLC,Hook::UnlockAllDLC);
	HookManager::install(app::GetAccuracy,Hook::GetAccuracy);
	HookManager::install(app::GetAllMusicUids, Hook::GetAllMusicUids);
	HookManager::install(app::AttackScore, Hook::AttackScore);
	/*HookManager::install(app::UploadScore, Hook::UploadScore);*/
	return TRUE;
}

BOOL WINAPI DllMain(HMODULE hMod, DWORD dwReason, LPVOID lpReserved)
{
	switch (dwReason)
	{
	case DLL_PROCESS_ATTACH:
		DisableThreadLibraryCalls(hMod);
		CreateThread(nullptr, 0, MainThread, hMod, 0, nullptr);
		break;
	case DLL_PROCESS_DETACH:
		kiero::shutdown();
		break;
	}
	return TRUE;
}
void ChangeOptions()
{
	static bool disableGodMode = false;
	if (menu.GodMode)
	{
		if (!disableGodMode)
		{
			HookManager::install((PVOID)app::IsHurt, (PVOID)((PCHAR)app::IsHurt + 11));
			disableGodMode = true;
		}

	}
	else
	{
		if (disableGodMode)
		{
			HookManager::detach((PVOID)((PCHAR)app::IsHurt + 11));
			disableGodMode = false;
		}

	}
}