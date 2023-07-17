#include "callibcore.h"
#include <iostream>
namespace callib {
	double settings::doubleError = 0.0001;

	bool lf_equal(double a, double b)
	{
		return (fabsl(a-b) < settings::doubleError);
	}
}