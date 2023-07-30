export module atemc.semantic.types.concrete.nevertype;

import <string>;

import atemc.semantic.types.concrete.typeexprast;

export namespace atemc
{
	class NeverType : public TypeExprAST
	{
	public:
		explicit NeverType()
		{
			
		}

		auto operator==(const TypeExprAST& that) const -> bool override
		{
			if(auto that_ptr = dynamic_cast<const NeverType*>(&that))
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

		auto getMangledTypeString() const -> ::std::u32string override
		{
			return U"Never";
		}
	};
}
