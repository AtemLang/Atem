export module atemc.semantic.types.concrete.unittype;

import <string>;

import atemc.semantic.types.concrete.abstracttype;

export namespace atemc
{
	class UnitType : public AbstractType
	{
	public:
		explicit UnitType()
		{
			
		}

		auto operator==(const AbstractType& that) const -> bool override
		{
			if(auto that_ptr = dynamic_cast<const UnitType*>(&that))
			{
				return true;
			}
			return false;
		}
		auto operator!=(const AbstractType& that) const -> bool override
		{
			return not this->operator==(that);
		}

		auto accept(TypeVisitor* visitor) -> void override
		{
			
		}

		auto getMangledTypeString() const -> ::std::string override
		{
			return "Unit";
		}
	};
}
