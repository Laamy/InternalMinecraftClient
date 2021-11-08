#pragma once

class Packet {
private:
	virtual void Function0();
	virtual void Function1();
	virtual void Function2();
	virtual void Function3();
	virtual void Function4();
	virtual void Function5();
	virtual void Function6();
	virtual void Function7();
public:
	virtual void readExtended(class ReadOnlyBinaryStream&);
	virtual void disallowBatching(void);
};