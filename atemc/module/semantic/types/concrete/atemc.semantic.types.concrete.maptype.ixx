export module atemc.semantic.types.concrete.maptype;

import <string>;
import <format>;
import <memory>;

import atemc.semantic.types.concrete.compositetype;

export namespace atemc
{
	class MapType : public CompositeType
	{
	public:
		explicit MapType(std::shared_ptr<TypeExprAST> key_type, std::shared_ptr<TypeExprAST> value_type)
		{
			this->sub_type_map_.at("key_type") = key_type;
			this->sub_type_map_.at("value_type") = value_type;
		}

		auto getKeyType() const noexcept -> std::shared_ptr<TypeExprAST> { return this->sub_type_map_.at("key_type"); }
		auto setKeyType(std::shared_ptr<TypeExprAST> value) noexcept -> void { this->sub_type_map_.at("key_type") = value; }

		auto getValueType() const noexcept -> std::shared_ptr<TypeExprAST> { return this->sub_type_map_.at("value_type"); }
		auto setValueType(std::shared_ptr<TypeExprAST> value) noexcept -> void { this->sub_type_map_.at("value_type") = value; }

		auto operator==(const TypeExprAST& that) const -> bool override
		{
			if(auto that_ptr = dynamic_cast<const MapType*>(&that); 
				this->sub_type_map_.at("key_type") == that_ptr->sub_type_map_.at("key_type")
				and this->sub_type_map_.at("value_type") == that_ptr->sub_type_map_.at("value_type"))
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
			return std::format("[{}:{}]", this->sub_type_map_.at("key_type")->getMangledTypeString(), this->sub_type_map_.at("value_type")->getMangledTypeString());
		}
	};
}
