#pragma once
class KeyInfo {
private:
	char pad_0x0000[0x50];  //0x0000
public:
	union {
		struct {
			bool leftClickDown;   //0x0050
			bool rightClickDown;  //0x0051
			bool wheelDown;
		};
		bool clickMap[3];
	};
};