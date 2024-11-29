#pragma once

#include"detours\detours.h"
#include"detours\detver.h"
#include<map>
#pragma comment(lib, "detours-x64.lib")
#define CALL_ORIGIN(function, ...) \
	HookManager::call(function, __func__, __VA_ARGS__)

class HookManager {
public:
	template <typename Fn>
	static void install(Fn func, Fn handler) {
		hookList.insert(std::pair<void*, void*>((void*)handler, (void*)func));
		enable(func, handler);
		holderMap[reinterpret_cast<void*>(handler)] = reinterpret_cast<void*>(func);
	}

	template <typename Fn>
	[[nodiscard]] static Fn getOrigin(Fn handler, const char* callerName = nullptr) noexcept {
		for (size_t i = 0; i <= 5; i++) {
			if (holderMap.count(reinterpret_cast<void*>(handler)) == 0) {
				if (i < 5) {
					Sleep(1000);
					continue;
				}
				printf("Origin not found for handler: %s. Maybe racing bug.", callerName == nullptr ? "<Unknown>" : callerName);
				/*
				PVOID Stacks[32] = { 0 };
				RtlCaptureStackBackTrace(1, 32, Stacks, 0);
				for (PVOID Stack : Stacks)
				{
					if (!Stack) continue;
					printf("- %p\n", Stack);
				}
				MessageBox(0, 0, 0, 0);
				*/
				ExitProcess(2);
				return nullptr;
			}
			else
			{
				break;
			}
		}
		return reinterpret_cast<Fn>(holderMap[reinterpret_cast<void*>(handler)]);
	}

	template <typename Fn>
	[[nodiscard]] static void detach(Fn handler) noexcept {
		disable(handler);
		holderMap.erase(reinterpret_cast<void*>(handler));
		hookList.erase(reinterpret_cast<void*>(handler));
	}

	template <typename RType, typename... Params>
	[[nodiscard]] static RType call(RType(*handler)(Params...), const char* callerName = nullptr, Params... params) {
		auto origin = getOrigin(handler, callerName);
		if (origin != nullptr)
			return origin(params...);

		return RType();
	}

	static void detachAll() noexcept {
		for (const auto& [key, value] : holderMap) {
			disable(key);
		}
		holderMap.clear();
		hookList.clear();
	}

	static std::map<void*, void*> getHookList() {
		return hookList;
	}

private:
	inline static std::map<void*, void*> hookList{};
	inline static std::map<void*, void*> holderMap{};

	template <typename Fn>
	static void disable(Fn handler) {
		Fn origin = getOrigin(handler);
		DetourTransactionBegin();
		DetourUpdateThread(GetCurrentThread());
		DetourDetach(&(PVOID&)origin, handler);
		DetourTransactionCommit();
	}

	template <typename Fn>
	static void enable(Fn& func, Fn handler) {
		DetourTransactionBegin();
		DetourUpdateThread(GetCurrentThread());
		DetourAttach(&(PVOID&)func, handler);
		DetourTransactionCommit();
	}
};
