#pragma once
#include "Library.h"
#include "Packet.h"

class MessageQueue
{
public:
	MessageQueue();
	~MessageQueue();

	void Enqueue(std::shared_ptr<Packet> packet);
	std::shared_ptr<Packet> Dequeue();	
	std::shared_ptr<Packet> Peek();

	bool IsEmpty();
	int GetSize();

private:
	std::queue<std::shared_ptr<Packet>> _queue;	
};