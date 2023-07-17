#ifndef CALLIB_H
#define CALLIB_H
#include <math.h>

namespace callib {
#define DEG2RAD 0.0174532925
#define RAD2DEG 57.2957795
	class settings {
	public:
		static double doubleError;
	};

	bool lf_equal(double a, double b);

	enum E_Direction {
		ClockWise,
		CounterClockWise,
		
		Up,
		Down,
		Left,
		Right
	};

	enum E_GraphType
	{
		POINT,
		LINE,
		ARC,
		RECT
	};
}

#endif