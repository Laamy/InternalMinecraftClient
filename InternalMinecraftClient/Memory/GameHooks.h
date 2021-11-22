#include "VirtualFuncHook.h"

class Hooks {
public:
	std::vector<VirtualFuncHook*> hooks;

public:
	VirtualFuncHook* getHook(const char* hookName) {
		for (auto hook : hooks) {
			if (hook->hookName == hookName)
				return hook;
		}
	}

	VirtualFuncHook* createHook(const char* hookName, uintptr_t ptr, void* function) {
		hooks.push_back(new VirtualFuncHook(std::string(hookName), ptr, function));
		return getHook(hookName);
	}
};