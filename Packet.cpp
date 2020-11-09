#include "Packet.h"

Packet::Packet(std::thread::id id, std::string str)
	: _id(id), _str(str)
{
}

void Packet::Execute()
{
	std::cout << "message : " << _str << " from thread(" << _id << ")" << std::endl;
}