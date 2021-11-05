#pragma once

class Weather {
private:
	char pad_0x0000[0x38]; //0x0000
public:
	bool isRaining; //0x0038
private:
	char pad_0x0039[0xB]; //0x0039
public:
	bool isLightning; //0x0044
private:
	char pad_0x0045[0x3]; //0x0045
public:
	float lightningLevel; //0x0048
};