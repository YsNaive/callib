#ifndef CALLIB_H
#define CALLIB_H
#include <math.h>

namespace callib {
#define DEG2RAD 0.0174532925
#define RAD2DEG 57.2957795
	class settings {
	public:
		// only apply when different result (ex. result of atan2)
		static int roundingDigits;
	};
	double roundTo(double val, int digits);
	double callibRound(double val);

	enum Direction {
		ClockWise,
		CounterClockWise,
		
		Up,
		Down,
		Left,
		Right
	};

	enum GraphType
	{
		POINT,
		LINE,
		ARC,
		RECT
	};
}

#endif