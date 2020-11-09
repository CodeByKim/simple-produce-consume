#include "Library.h"
#include "Util.h"

int Util::GetRandomNumber(int min, int max)
{
	static std::random_device seed;
	static std::mt19937 random_engine(seed());

	std::uniform_int_distribution<int> dis(min, max);
	return dis(random_engine);
}