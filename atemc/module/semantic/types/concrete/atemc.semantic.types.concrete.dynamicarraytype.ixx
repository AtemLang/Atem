export module atemc.semantic.types.concrete.dynamicarraytype;

import <string>;
import <format>;
import <memory>;

import <fmt/compile.h>;
import <fmt/xchar.h>;

import atemc.semantic.types.concrete.compositetype;

export namespace atemc
{
	class DynamicArrayType : public CompositeType
	{
	public:
		explicit DynamicArrayType(std::shared_ptr<TypeExprAST> element_type)
		{
			this->sub_type_map_.at(U"element_type") = element_type;
		}

		auto getElementType() const noexcept -> std::weak_ptr<TypeExprAST> { return this->sub_type_map_.at(U"element_type"); }
		auto setElementType(std::shared_ptr<TypeExprAST> value) noexcept -> void { this->sub_type_map_.at(U"element_type") = value; }

		auto operator==(const TypeExprAST& that) const -> bool override
		{
			if(auto that_ptr = dynamic_cast<const DynamicArrayType*>(&that); 
				this->sub_type_map_.at(U"element_type") == that_ptr->sub_type_map_.at(U"element_type"))
			{
				return true;
			}
			return false;
		}

		auto accept(TypeVisitor* visitor) -> void override
		{
			
		}

		auto getMangledTypeString() const -> std::u32string override
		{
			return fmt::format(FMT_COMPILE(U"[]{}"), this->sub_type_map_.at(U"element_type")->getMangledTypeString());
		}
	};
}