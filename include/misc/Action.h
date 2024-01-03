#ifndef CALLIB_ACTION_H
#define CALLIB_ACTION_H
#include <iostream>
#include <functional>
#include <set>
namespace callib {
	template<typename... _args>
	class Action
	{
		typedef std::function<void(_args...)> FType;
	protected:
		FType* func;
		void* funcPtr = nullptr;
		void* target;
	public:
		template<typename _fun>
		Action(_fun&& lam)
			: func(new FType(lam)), funcPtr(&lam){
			target = func->target<_fun>();
		}
		~Action() {
			delete func;
		}

		void Invoke(const _args&... args) {
			(*func)(args...);
		}
		void* FuncPtr() const { return funcPtr; }
		void* Target() const { return target; }
		std::string TypeName() const { return func->target_type().name(); }

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
		cout << first.Target() << ' ' << second.Target() << '\n';
		return (first.FuncPtr() < second.FuncPtr());
	}

}
#endif
