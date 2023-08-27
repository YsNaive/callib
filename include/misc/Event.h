#ifndef CALLIB_EVENT_H
#define CALLIB_EVENT_H
#include "Action.h"
namespace callib {
	template<typename... _args>
	class Event {
	protected:
		std::set<Action<_args...>> funcSet;
	public:
		void Add(const Action<_args...>& func) {
			funcSet.insert(func);
		}
		void Remove(const Action<_args...>& func) {
			funcSet.erase(func);
		}
		void Invoke(const _args&... args) {
			for (auto f : funcSet)
				f(args...);
		}

		void operator+= (const Action<_args...>& func) {
			Add(func);
		}
		void operator-= (const Action<_args...>& func) {
			Remove(func);
		}
		void operator() (const _args&... args) {
			Invoke(args...);
		}
	};
}
#endif 
