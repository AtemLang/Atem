export module atemc.semantic.types.concrete.comptimefloatingpointtype;

import <string>;

import atemc.semantic.types.concrete.typeexprast;

export namespace atemc
{
	class ComptimeFloatingPointType : public TypeExprAST
	{
	public:
		explicit ComptimeFloatingPointType()
		{
			
		}

		auto operator==(const TypeExprAST& that) const -> bool override
		{
			if(auto that_ptr = dynamic_cast<const ComptimeFloatingPointType*>(&that))
			{
				return true;
			}
			return false;
		}
		auto operator!=(const TypeExprAST& that) const -> bool override
		{
			return not this->operator==(that);
		}

		auto accept(TypeVisitor* visitor) -> void override
		{
			
		}

		auto getMangledTypeString() const -> ::std::string override
		{
			return "ComptimeFloat";
		}
	};
}