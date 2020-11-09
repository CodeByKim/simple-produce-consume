#include "MessageQueue.h"

MessageQueue::MessageQueue()
{	
}

MessageQueue::~MessageQueue()
{
	//something...
}

void MessageQueue::Enqueue(std::shared_ptr<Packet> packet)
{	
	_queue.push(packet);
}

std::shared_ptr<Packet> MessageQueue::Dequeue()
{	
	auto packet = _queue.front();
	_queue.pop();

	return packet;
}

std::shared_ptr<Packet> MessageQueue::Peek()
{	
	auto packet = _queue.front();	

	return packet;
}

bool MessageQueue::IsEmpty()
{	
	return _queue.size() == 0;
}

int MessageQueue::GetSize()
{	
	return _queue.size();
}