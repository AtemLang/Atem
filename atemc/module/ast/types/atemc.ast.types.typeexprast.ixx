export module atemc.ast.types.typeexprast;

export import atemc.ast.types.exprast;

export namespace atemc 
{
	class TypeExprAST : public ExprAST 
	{
	public:
		auto accept(ASTVisitor* visitor) -> void override {}
	};
}