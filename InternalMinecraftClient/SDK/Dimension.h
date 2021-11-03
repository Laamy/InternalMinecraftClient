#include <string>
#include "Weather.h"

class Dimension {
private:
	char pad_0x0000[0x18]; //0x0000
public:
	std::string DimenstionName; //0x0034 
private:
	char pad_0x0038[0xD8]; //0x0038
public:
	Weather* weather; //0x0110
};