export module atemc.semantic.types.concrete.compositetype;

import <unordered_map>;
import <string>;
import <memory>;
import <format>;

export import atemc.semantic.types.concrete.typeexprast;

export namespace atemc
{
	class CompositeType : public TypeExprAST
	{
	public:
		CompositeType() = default;

		auto operator==(const TypeExprAST& that) const -> bool override
		{
			if(auto that_ptr = dynamic_cast<const CompositeType*>(&that))
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

	protected:
		std::unordered_map<std::u32string, std::shared_ptr<TypeExprAST>> sub_type_map_;
		using SubTypeMapT = std::unordered_map<std::u32string, std::shared_ptr<TypeExprAST>>;

	public:
		explicit CompositeType(const SubTypeMapT& sub_type_map)
			: sub_type_map_(sub_type_map)
		{}
		explicit CompositeType(SubTypeMapT&& sub_type_map) noexcept
			: sub_type_map_(std::move(sub_type_map))
		{}

		auto operator=(const CompositeType& that) -> CompositeType&
		{
			this->sub_type_map_.operator=(that.sub_type_map_);
			return *this;
		}
		auto operator=(CompositeType&& that) noexcept -> CompositeType&
		{
			this->sub_type_map_.operator=(std::move(that.sub_type_map_));
			return *this;
		}

		auto getSubTypeMap() const -> const SubTypeMapT& { return this->sub_type_map_; }
		auto setSubTypeMap(const SubTypeMapT& value) -> void { this->sub_type_map_ = value; }
		auto setSubTypeMap(SubTypeMapT&& value) -> void { this->sub_type_map_ = std::move(value); }
		auto setSubTypeMap(SubTypeMapT value) -> void { this->sub_type_map_ = std::move(value); }
		auto subTypeMap() -> SubTypeMapT& { return this->sub_type_map_; }

		auto getArity() const -> size_t { return this->sub_type_map_.size(); }
	};
}
