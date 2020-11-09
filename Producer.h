#pragma once
#include "Library.h"
#include "MessageQueue.h"

class Producer
{
public:		
	Producer(Producer&& other);
	Producer(MessageQueue& queue, std::mutex& mutex, std::condition_variable& cv);
	~Producer();

	void Produce();
	void Stop();

private:
	MessageQueue& _queue;

	std::thread _thread;
	std::mutex& _mutex;
	std::condition_variable& _conditionVariable;

	bool _isRun;
};