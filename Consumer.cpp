#include "Consumer.h"

Consumer::Consumer(MessageQueue& queue, std::mutex& mutex, std::condition_variable& cv)
	: _queue(queue), _mutex(mutex), _conditionVariable(cv)
{
	_thread = std::thread(&Consumer::Consume, this);
	_isRun = true;
}

void Consumer::Consume()
{
	while (true)
	{
		if (!_isRun)
		{
			//���� ó��...
			break;
		}

		std::unique_lock<std::mutex> lock(_mutex);
		_conditionVariable.wait(lock, [&]() {		// wait���� ������ �������� ��� �ϴ¼��� unlock, true�� �Ǹ� wait�� Ż����
			if (!_queue.IsEmpty())
			{
				return true;
			}
			return false;
			});

		auto packet = _queue.Dequeue();
		lock.unlock();

		ProcessPacket(packet);
	}
}

void Consumer::ProcessPacket(std::shared_ptr<Packet> packet)
{
	packet->Execute();
}

void Consumer::Stop()
{
	_isRun = false;
	_thread.join();
}