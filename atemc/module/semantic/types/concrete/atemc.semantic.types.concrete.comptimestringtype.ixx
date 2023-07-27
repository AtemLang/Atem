export module atemc.semantic.types.concrete.comptimestringtype;

import <string>;

import atemc.semantic.types.concrete.typeexprast;

export namespace atemc
{
	class ComptimeStringType : public TypeExprAST
	{
	public:
		explicit ComptimeStringType()
		{
			
		}

		auto operator==(const TypeExprAST& that) const -> bool override
		{
			if(auto that_ptr = dynamic_cast<const ComptimeStringType*>(&that))
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
			return "ComptimeString";
		}
	};
}