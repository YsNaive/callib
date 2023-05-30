#include "GraphObject.h"

namespace callib {
	std::string GraphObject::getTypeName() const
	{
		static std::map<GraphType, std::string> type2str = {
			{GraphType::POINT, "Point"},
			{GraphType::LINE, "Line"},
			{GraphType::ARC, "Arc"}
		};
		return type2str[this->getType()];
	}
} // namespace callib