export module atemc.semantic.types.concrete.typeexprast;

import <string>;

import atemc.basic;
import atemc.ast.types;

export namespace atemc
{
	class TypeVisitor;

	class TypeExprAST : public ExprAST
	{
	public:
		virtual auto operator==(const TypeExprAST& that) const -> bool = 0;
		virtual auto operator!=(const TypeExprAST& that) const -> bool
		{
			return not this->operator==(that);
		}

		virtual auto accept(TypeVisitor* visitor) -> void = 0;

		auto accept(ASTVisitor* visitor) -> void override { return ; }

		virtual auto getMangledTypeString() const -> std::u32string = 0;
	};
}