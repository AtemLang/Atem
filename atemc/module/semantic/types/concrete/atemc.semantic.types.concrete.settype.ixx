export module atemc.semantic.types.concrete.settype;

import <string>;
import <format>;
import <memory>;

import atemc.semantic.types.concrete.compositetype;

export namespace atemc
{
	class SetType : public CompositeType
	{
	public:
		explicit SetType(std::shared_ptr<TypeExprAST> element_type)
		{
			this->sub_type_map_.at("element_type") = element_type;
		}

		auto getElementType() const noexcept -> std::shared_ptr<TypeExprAST> { return this->sub_type_map_.at("element_type"); }
		auto setElementType(std::shared_ptr<TypeExprAST> value) noexcept -> void { this->sub_type_map_.at("element_type") = value; }

		auto operator==(const TypeExprAST& that) const -> bool override
		{
			if(auto that_ptr = dynamic_cast<const SetType*>(&that); 
				this->sub_type_map_.at("element_type") == that_ptr->sub_type_map_.at("element_type"))
			{
				return true;
			}
			return false;
		}

		auto accept(TypeVisitor* visitor) -> void override
		{
			
		}

		auto getMangledTypeString() const -> std::string override
		{
			return std::format("[{}]", this->sub_type_map_.at("element_type")->getMangledTypeString());
		}
	};
}
