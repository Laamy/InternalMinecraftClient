#pragma once

class Packet {
private:
	virtual void Constructor(); //1
	virtual void TryroFunc1(); //2
public:
	virtual std::string getName(void); //3
};