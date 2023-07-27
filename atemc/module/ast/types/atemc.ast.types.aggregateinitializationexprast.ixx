export module atemc.ast.types.aggregateinitializationexprast;

import <map>;
import <print>;
import <memory>;

export import atemc.ast.types.exprast;

export namespace atemc 
{
	class TypeExprAST;

	class AggregateInitializationExprAST : public ExprAST 
	{
	public:
		AggregateInitializationExprAST(std::shared_ptr<TypeExprAST> type_expr_ast, const std::map<ExprAST, ExprAST>& members)
		{
			
		}

		auto accept(ASTVisitor* visitor) -> void override {}
	};
}
