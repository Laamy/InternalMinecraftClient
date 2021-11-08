#pragma once

class Packet {
public:
	virtual void BlockActorDataPacket(class BlockActorDataPacket const&); //1
	virtual void LoginPacket(class LoginPacket&&); //2
private:
	virtual void TryroFunc3();
	virtual void TryroFunc4();
	virtual void TryroFunc5();
	virtual void TryroFunc6();
	virtual void TryroFunc7();
public:
	virtual void readExtended(class ReadOnlyBinaryStream&); //8
	virtual void disallowBatching(void); //9
private:
	virtual void TryroFunc10();
};