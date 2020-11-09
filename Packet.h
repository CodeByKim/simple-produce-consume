#pragma once
#include "Library.h"

class Packet
{
public:
	Packet() = delete;
	Packet(std::thread::id id, std::string str);

	void Execute();

private:
	std::thread::id _id;
	std::string _str;	
};