#ifndef CALLIB_LOGICGATE_H
#define CALLIB_LOGICGATE_H
#include"GateBased.h"
namespace callib {
	class OR_Gate : public GateBased
	{
	public:
		OR_Gate(GateBased* in1, GateBased* in2);
		~OR_Gate();
		std::string Result();
	private:
		GateBased* in1;
		GateBased* in2;
	};
}

#endif // !CALLIB_LOGICGATE_H