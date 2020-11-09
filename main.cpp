
#include "Library.h"
#include "MessageQueue.h"
#include "Packet.h"
#include "Producer.h"
#include "Consumer.h"

int main()
{		
	MessageQueue queue;
	std::mutex mutex;
	std::condition_variable cv;

	std::vector<Producer> producerVector;
	producerVector.reserve(PRODUCER_THREAD_COUNT);

	for (int i = 0; i < PRODUCER_THREAD_COUNT; i++)
	{		
		producerVector.emplace_back(std::ref(queue), std::ref(mutex), std::ref(cv));		
	}

	Consumer consumer(queue, mutex, cv);

	char key = getchar();
	if (key == 'q')
	{
		for (auto& producer : producerVector)
		{
			producer.Stop();
		}
		consumer.Stop();
	}
	
	std::cout << "end of program" << std::endl;
}