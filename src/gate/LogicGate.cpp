#include "GateBased.h"
#include "LogicGate.h"
namespace callib {
	OR_Gate::OR_Gate(GateBased* in1, GateBased* in2)
		:in1(in1),in2(in2) {}
	OR_Gate::~OR_Gate()
	{
		delete(in1);
		delete(in2);
	}
	std::string OR_Gate::Result()
	{
		return "";
	}
}