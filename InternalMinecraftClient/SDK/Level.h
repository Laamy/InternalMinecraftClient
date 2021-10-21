class Level {
private:
	char pad_0x0000[0x518]; //0x0000
public:
	std::string WorldName; //0xFB1FE9C0 
private:
	char pad_0x0548[0xA8]; //0x0548
public:
	__int32 TicksPast; //0x05F0 
private:
	char pad_0x05F4[0x3FC]; //0x05F4
public:
	Vector3 EyeHeight; //0x09F0 
	Vector3 LookingVector; //0x09FC 
private:
	char pad_0x0A08[0x4]; //0x0A08
public:
	unsigned char SelectedSide; //0x0A0C 
private:
	char pad_0x0A0D[0xF]; //0x0A0D
public:
	Vector3 LookingPosition; //0x0A1C 
private:
	char pad_0x0A28[0x48]; //0x0A28
public:
	Vector2 CameraRots2; //0x0A70 
	unsigned char LookingAtBlock; //0x0A78 
private:
	char pad_0x0A79[0x3]; //0x0A79
public:
	unsigned char SelectedSide2; //0x0A7C 
private:
	char pad_0x0A7D[0xF]; //0x0A7D
public:
	Vector3 LookingPosition2; //0x0A8C 
};