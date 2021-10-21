#include <string>

class Dimension {
private:
	char pad_0x0000[0x18]; //0x0000
public:
	std::string DimenstionName; //0xFB1FE9C0 
private:
	char pad_0x0038[0x80]; //0x0038
public:
	char DimenstionNameLong[48]; //0xFB1FE9C0 
};