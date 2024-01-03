#pragma once
#include <map>
#include <chrono>

namespace callib {
	class TimeWatch {
	public:
		static int Precision;
		enum Unit {
			NANO_SEC = 1000000000,
			MICRO_SEC = 1000000,
			MILLI_SEC = 1000,
			SEC = 1,
		};
		TimeWatch();
		~TimeWatch();
		void Start(std::string id = "");
		double Stop(std::string id = "");
		void Reset(std::string id = "");
		void Restart(std::string id = "");
		void Close(std::string id = "");
		double Total();
		void SetUnit(Unit unit);
		friend std::ostream& operator<< (std::ostream& os, TimeWatch& obj);
	private:
		Unit unit = SEC;
		std::map<std::string, double> timeMap;
		std::map<std::string, std::chrono::system_clock::time_point> begTimeMap;
	};
}