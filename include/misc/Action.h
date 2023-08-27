#ifndef CALLIB_ACTION_H
#define CALLIB_ACTION_H
#include <iostream>
#include <functional>
#include <set>
namespace callib {
	template<typename... _args>
	class Action
	{
	protected:
		std::function<void(_args...)> func;
		void* funcPtr = nullptr;
	public:
		template<typename _fun>
		Action(_fun&& lam)
			: func(lam), funcPtr(&lam) {}

		void Invoke(const _args&... args) {
			func(args...);
		}
		void* FuncPtr() const { return funcPtr; }
		std::string TypeName() const { return func.target_type().name(); }

		void operator() (const _args&... args) {
			Invoke(args...);
		}

		void operator= (Action<_args...>& other) {
			func = other.func;
			funcPtr = other.funcPtr;
		}
		bool operator== (Action<_args...>& other) const {
			return (funcPtr == other.funcPtr);
		}

		friend std::ostream& operator<<(std::ostream& os, Action<_args...>& func) {
			os << func.funcPtr << "  " << func.TypeName();
			return os;
		}
	};

	template<typename... _args>
	bool operator< (const Action<_args...>& first, const Action<_args...>& second) {
		return (first.FuncPtr() < second.FuncPtr());
	}

}
#endif
