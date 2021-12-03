#pragma once
#include "../TextHolder.h"
class Packet {
private:
	virtual void packetConstructor(void) {};
public:
	virtual int getId(void) { return 0x0; };
	virtual class TextHolder getTypeName(void) { return (class TextHolder)nullptr; };
	virtual void write(class BinaryStream&) {};
	virtual void read(class ReadOnlyBinaryStream&) {};
	virtual void readExtended(class ReadOnlyBinaryStream&) {};
	virtual void disallowBatching(void) {};

	// Returns packet name e.g "MovePlayerPacket"
	std::string getName()
	{
		return this->getTypeName().getText();
	}

	// Set vTable
	void setVTable(uint64_t vtable)
	{
		*(uint64_t*)(reinterpret_cast<uintptr_t>(this) + 0x0) = vtable;
	}

	// Returns vTable
	uint64_t getVTable()
	{
		return *(uint64_t*)(reinterpret_cast<uintptr_t>(this) + 0x0);
	}
};