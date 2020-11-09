#pragma once
#include "Library.h"

class Util : public Singleton<Util>
{
public:
	int GetRandomNumber(int min, int max);
};