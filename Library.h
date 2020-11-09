#pragma once

#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <chrono>
#include <queue>
#include <vector>
#include <string>
#include <sstream>
#include <random>

#include "Singleton.h"
#include "Util.h"

#define PRODUCER_THREAD_COUNT 4