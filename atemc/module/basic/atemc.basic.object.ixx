module;

#include <nameof.hpp>

export module atemc.basic.object;

import <string>;
import <format>;
import <concepts>;

export namespace atemc
{
	class AtemcObject;

	template<typename T>
	concept IsAtemcObject = std::derived_from<T, AtemcObject>;

	class AtemcObject 
	{
		static auto staticToString(const IsAtemcObject auto& obj) -> std::string
		{
			return std::format
			(
				"<Object {} at {}>",
				NAMEOF_TYPE(decltype(obj)),
				&obj
			);
		}
	};
}