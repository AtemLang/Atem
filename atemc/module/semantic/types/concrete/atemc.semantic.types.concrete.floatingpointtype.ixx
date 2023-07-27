export module atemc.semantic.types.concrete.floatingpointtype;

import <string>;

import atemc.semantic.types.concrete.compositetype;

export namespace atemc
{
	class FloatingPointType : public CompositeType
	{
	public:
		enum class FloatingPointWidthKind
		{
			FPWK_16 = 16,
			FPWK_32 = 32,
			FPWK_64 = 64,
			FPWK_80 = 80,
			FPWK_128 = 128
		};

	private:
		FloatingPointWidthKind floating_point_width_kind_;

	public:
		explicit FloatingPointType(FloatingPointWidthKind floating_point_width_kind)
			: floating_point_width_kind_(floating_point_width_kind)
		{}

		auto operator==(const TypeExprAST& that) const -> bool override
		{
			if(auto that_ptr = dynamic_cast<const FloatingPointType*>(&that))
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
			return std::string{"Float"}.append(std::to_string(std::to_underlying(this->floating_point_width_kind_)));
		}
	};
}