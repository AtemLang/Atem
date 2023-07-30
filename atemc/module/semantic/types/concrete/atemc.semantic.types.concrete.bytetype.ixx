export module atemc.semantic.types.concrete.bytetype;

import <string>;

import atemc.semantic.types.concrete.typeexprast;

export namespace atemc
{
	class ByteType : public TypeExprAST
	{
	public:
		explicit ByteType()
		{
			
		}

		auto operator==(const TypeExprAST& that) const -> bool override
		{
			if(auto that_ptr = dynamic_cast<const ByteType*>(&that))
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
			return U"Byte";
		}
	};
}
