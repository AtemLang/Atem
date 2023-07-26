export module atemc.semantic.types.concrete.comptimeintegertype;

import <string>;

import atemc.semantic.types.concrete.abstracttype;

export namespace atemc
{
	class ComptimeIntegerType : public AbstractType
	{
	public:
		explicit ComptimeIntegerType()
		{
			
		}

		auto operator==(const AbstractType& that) const -> bool override
		{
			if(auto that_ptr = dynamic_cast<const ComptimeIntegerType*>(&that))
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
			return "ComptimeFloat";
		}
	};
}