export module atemc.semantic.types.concrete.staticarraytype;

import <string>;
import <format>;
import <memory>;

import <fmt/compile.h>;
import <fmt/xchar.h>;

import atemc.semantic.types.concrete.compositetype;

export namespace atemc
{
	class StaticArrayType : public CompositeType
	{
		size_t length_;

	public:
		StaticArrayType(std::shared_ptr<TypeExprAST> element_type, size_t length)
			: length_(length)
		{
			this->sub_type_map_.at(U"element_type") = element_type;
		}

		auto getElementType() const noexcept -> std::weak_ptr<TypeExprAST> { return this->sub_type_map_.at(U"element_type"); }
		auto setElementType(std::shared_ptr<TypeExprAST> value) noexcept -> void { this->sub_type_map_.at(U"element_type") = value; }

		auto getLength() const noexcept -> size_t { return this->length_; }
		auto setLength(size_t value) noexcept -> void { this->length_ = value; }

		auto operator==(const TypeExprAST& that) const -> bool override
		{
			if(auto that_ptr = dynamic_cast<const StaticArrayType*>(&that); 
				this->length_ == that_ptr->length_ and this->sub_type_map_.at(U"element_type") == that_ptr-> sub_type_map_.at(U"element_type"))
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
			return std::u32string{[&]
			{
				if(this->length_ > 0) return fmt::format(FMT_COMPILE(U"[{}]"), this->length_);
				else return std::u32string{U"[_]"};
			}()}.append(this->sub_type_map_.at(U"element_type")->getMangledTypeString());
		}
	};
}