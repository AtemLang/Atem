export module atemc.semantic.types.concrete.compositetype;

export import atemc.semantic.types.concrete.abstracttype;

export namespace atemc
{
	class CompositeType : public AbstractType
	{
	public:
		CompositeType()
		{
			
		}

		auto operator==(const AbstractType& that) const -> bool override
		{
			if(auto that_ptr = dynamic_cast<const CompositeType*>(&that))
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
	};
}