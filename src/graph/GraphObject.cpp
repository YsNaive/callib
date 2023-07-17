#include "GraphObject.h"

namespace callib {
	std::string GraphObject::getTypeName() const
	{
		static std::map<E_GraphType, std::string> type2str = {
			{E_GraphType::POINT, "Point"},
			{E_GraphType::LINE, "Line"},
			{E_GraphType::ARC, "Arc"}
		};
		return type2str[this->getType()];
	}
} // namespace callib