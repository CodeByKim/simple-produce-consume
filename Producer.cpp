#include "Producer.h"
#include "Util.h"
#include "Packet.h"

Producer::Producer(MessageQueue& queue, std::mutex& mutex, std::condition_variable& cv)
	: _queue(queue), _mutex(mutex), _conditionVariable(cv)
{
	_thread = std::thread(&Producer::Produce, this);
	_isRun = true;
}

Producer::Producer(Producer&& other)
	: _queue(other._queue), _mutex(other._mutex), _conditionVariable(other._conditionVariable)
{
	
}

Producer::~Producer()
{

}

void Producer::Produce()
{
	while (true)
	{		
		if (!_isRun)
		{
			//종료 처리...
			break;
		}

		int number = Util::GetInstance().GetRandomNumber(10, 20);		
		std::this_thread::sleep_for(std::chrono::milliseconds(number));		//작업시간을 임의로 슬립...

		std::string message = std::to_string(number);
		std::shared_ptr<Packet> packet = std::make_shared<Packet>(std::this_thread::get_id(), message);		
		{
			std::lock_guard<std::mutex> lock(_mutex);
			_queue.Enqueue(packet);

			_conditionVariable.notify_one();
		}
	}
}

void Producer::Stop()
{	
	_isRun = false;
	_thread.join();
}