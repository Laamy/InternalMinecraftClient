#pragma once
#include "Packet/Packet.h"
#include <vector>

class LoopbackPacketSender {
public:
	virtual void LoopbackPacketSender();
	virtual void send(Packet&);
	virtual void sendToServer(Packet&);
	virtual void sendToClient(class UserEntityIdentifierComponent const*, Packet const&);
	virtual void sendToClient(class NetworkIdentifier const&, Packet const&, class uchar);
	virtual void sendToClients(std::vector<struct NetworkIdentifierWithSubId> const&, Packet const&);
	virtual void sendBroadcast(Packet const&);
	virtual void sendBroadcast(NetworkIdentifier const&, uchar, Packet const&);
	virtual void flush();//removed
};