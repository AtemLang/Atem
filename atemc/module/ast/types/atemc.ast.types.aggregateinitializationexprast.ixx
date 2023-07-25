export module atemc.ast.types.aggregateinitializationexprast;

import <map>;

export import atemc.ast.types.exprast;
export import atemc.ast.types.typeexprast;

export namespace atemc 
{
	class AggregateInitializationExprAST : public ExprAST 
	{
	public:
		AggregateInitializationExprAST(const TypeExprAST& type_expr_ast, const std::map<ExprAST, ExprAST, TypeExprASTHash>& members) {}

		auto accept(ASTVisitor* visitor) -> void override {}
	};
}