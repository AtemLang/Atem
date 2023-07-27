export module atemc.semantic.types.concrete.stringtype;

import <string>;

import atemc.semantic.types.concrete.compositetype;

export namespace atemc
{
	class StringType : public CompositeType
	{
	public:
		explicit StringType()
		{
			
		}

		auto operator==(const TypeExprAST& that) const -> bool override
		{
			if(auto that_ptr = dynamic_cast<const StringType*>(&that))
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
			return "String";
		}
	};
}