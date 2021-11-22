#pragma once

class ChestRay : public Module { //wip
public:
	ChestRay(std::string cat) : Module(cat, "ChestRay", 0x07) {
		/*uintptr_t blockRendererAddr = Mem::findSig("48 89 5C 24 ? 55 56 57 41 54 41 55 41 56 41 57 48 8D 6C 24 ? 48 81 EC ? ? ? ? 4C 89 4C");

		typedef void(__thiscall* blockRenderer)(void* rendercls, void* block);
		blockRenderer _renderBlock;

		void renderBlockCallback(void* cls, void* block) {
			if (enabled == false)
				_renderBlock(cls, block);
		};

		if (MH_CreateHook((void*)blockRendererAddr, &renderBlockCallback, reinterpret_cast<LPVOID*>(&_renderBlock)) == MH_OK) {
			MH_EnableHook((void*)blockRendererAddr);
			_logf(L"[TreroInternal]: BlockRenderer hooked!\n");
		};*/
	};

};