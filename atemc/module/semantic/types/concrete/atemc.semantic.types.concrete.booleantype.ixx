export module atemc.semantic.types.concrete.booleantype;

import <string>;

import atemc.semantic.types.concrete.typeexprast;

export namespace atemc
{
	class BooleanType : public TypeExprAST
	{
	public:
		explicit BooleanType()
		{
			
		}

		auto operator==(const TypeExprAST& that) const -> bool override
		{
			if(auto that_ptr = dynamic_cast<const BooleanType*>(&that))
			{
				return true;
			}
			return false;
		}

		auto accept(TypeVisitor* visitor) -> void override
		{
			
		}

		auto getMangledTypeString() const -> ::std::u32string override
		{
			return U"Bool";
		}
	};
}
