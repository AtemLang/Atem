export module atemc.semantic.types.concrete.comptimecharactertype;

import <string>;

import atemc.semantic.types.concrete.abstracttype;

export namespace atemc
{
	class ComptimeCharacterType : public AbstractType
	{
	public:
		explicit ComptimeCharacterType()
		{
			
		}

		auto operator==(const AbstractType& that) const -> bool override
		{
			if(auto that_ptr = dynamic_cast<const ComptimeCharacterType*>(&that))
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
			return "ComptimeChar";
		}
	};
}