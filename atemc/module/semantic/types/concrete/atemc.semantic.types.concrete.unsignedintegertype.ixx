export module atemc.semantic.types.concrete.unsignedintegertype;

import <string>;

import atemc.semantic.types.concrete.compositetype;

export namespace atemc
{
	class UnsignedIntegerType : public CompositeType
	{
		unsigned long long integer_type_width_;
	public:

		explicit UnsignedIntegerType(unsigned long long integer_type_width)
			: integer_type_width_(integer_type_width)
		{
			
		}

		auto operator==(const AbstractType& that) const -> bool override
		{
			if(auto that_ptr = dynamic_cast<const UnsignedIntegerType*>(&that); this->integer_type_width_ == that_ptr->integer_type_width_)
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

		auto getIntegerTypeWidth() const noexcept -> unsigned long long { return this->integer_type_width_; }
		auto setIntegerTypeWidth(unsigned long long new_value) noexcept -> void { this->integer_type_width_ = new_value; }

		auto getMangledTypeString() const -> ::std::string override
		{
			return std::string{"UInt"}.append(std::to_string(this->integer_type_width_));
		}
	};
}
