#include "callibcore.h"

namespace callib {
	int settings::roundingDigits = 4;

	double roundTo(double val, int digits) {
		long long int intVal = val * pow(10, digits);
		return intVal / pow(10, digits);
	}
	double callibRound(double val) {
		return roundTo(val, settings::roundingDigits);
	}
}