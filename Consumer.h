#pragma once
#include "Library.h"
#include "MessageQueue.h"

class Consumer
{
public:
	Consumer(MessageQueue& queue, std::mutex& mutex, std::condition_variable& cv);
	void Consume();
	void Stop();

private:
	MessageQueue& _queue;

	std::thread _thread;
	std::mutex& _mutex;
	std::condition_variable& _conditionVariable;

	void ProcessPacket(std::shared_ptr<Packet> packet);

	bool _isRun;
};
