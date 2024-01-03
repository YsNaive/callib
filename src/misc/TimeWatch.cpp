#include <ostream>
#include <iomanip>
#include "TimeWatch.h"

namespace callib {
	int TimeWatch::Precision = 3;

	std::ostream& operator<<(std::ostream& os, TimeWatch& obj)
	{
		os << "--- TimeWatch ";
		if (obj.unit == TimeWatch::SEC)
			os << "sec   ";
		else if (obj.unit == TimeWatch::MILLI_SEC)
			os << "milli ";
		else if (obj.unit == TimeWatch::MICRO_SEC)
			os << "micro ";
		else if (obj.unit == TimeWatch::NANO_SEC)
			os << "nano  ";
		os << "---\n";
		int maxWidth = 0;
		for (auto pair : obj.timeMap)
			if (pair.first.size() > maxWidth)maxWidth = pair.first.size();
		os << std::fixed << std::setprecision(TimeWatch::Precision);
		for (auto pair : obj.timeMap) {
			os << pair.first;
			for (int i = maxWidth - pair.first.size(); i > 0; i--)
				os << ' ';
			os << ": " << pair.second << '\n';
		}
		os << "Total: " << obj.Total();
		return os;
	}
	TimeWatch::TimeWatch()
	{
	}

	TimeWatch::~TimeWatch()
	{
	}

	void TimeWatch::Start(std::string id)
	{
		begTimeMap[id] = std::chrono::system_clock::now();
	}

	double TimeWatch::Stop(std::string id)
	{
		auto d = std::chrono::system_clock::now() - begTimeMap[id];
		if (!timeMap.count(id))
			timeMap[id] = 0;
		if (unit == SEC)
			timeMap[id] += std::chrono::duration<double, std::ratio<1, 1>>(d).count();
		else if (unit == MILLI_SEC)
			timeMap[id] += std::chrono::duration<double, std::milli>(d).count();
		else if (unit == MICRO_SEC)
			timeMap[id] += std::chrono::duration<double, std::micro>(d).count();
		else if (unit == NANO_SEC)
			timeMap[id] += std::chrono::duration<double, std::nano>(d).count();
		return timeMap[id];
	}

	void TimeWatch::Reset(std::string id)
	{
		timeMap[id] = 0;
	}

	void TimeWatch::Restart(std::string id)
	{
		Reset(id);
		Start(id);
	}

	void TimeWatch::Close(std::string id)
	{
		timeMap.erase(id);
		begTimeMap.erase(id);
	}

	double TimeWatch::Total()
	{
		double sum = 0;
		for (auto& pair : timeMap)
			sum += pair.second;
		return sum;
	}

	void TimeWatch::SetUnit(Unit unit)
	{
		double offset = unit / (double)this->unit;
		for (auto& pair : timeMap)
			pair.second *= offset;
		this->unit = unit;
	}
}