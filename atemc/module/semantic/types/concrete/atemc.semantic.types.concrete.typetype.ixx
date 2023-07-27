export module atemc.semantic.types.concrete.typetype;

import <string>;

import atemc.semantic.types.concrete.typeexprast;

export namespace atemc
{
	class TypeType : public TypeExprAST
	{
	public:
		explicit TypeType()
		{
			
		}

		auto operator==(const TypeExprAST& that) const -> bool override
		{
			if(auto that_ptr = dynamic_cast<const TypeType*>(&that))
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
			return "Unit";
		}
	};
}
