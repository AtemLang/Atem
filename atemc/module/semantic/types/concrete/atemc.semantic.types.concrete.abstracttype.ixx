export module atemc.semantic.types.concrete.abstracttype;

import <string>;

import atemc.basic;

export namespace atemc
{
	class TypeVisitor;

	class AbstractType : public AtemcObject
	{
	public:
		virtual auto operator==(const AbstractType& that) const -> bool = 0;
		virtual auto operator!=(const AbstractType& that) const -> bool = 0;

		virtual ~AbstractType() = default;

		virtual auto accept(TypeVisitor* visitor) -> void = 0;

		virtual auto getMangledTypeString() const -> std::string = 0;
	};
}