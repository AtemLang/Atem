export module atemc.ast.types.exprast;

import <memory>;

export import atemc.ast.types.stmtast;

export namespace atemc 
{
	class TypeExprAST;

	class ExprAST: public StmtAST
	{
	protected:
		std::shared_ptr<TypeExprAST> expr_type_;

	public:
		auto accept(ASTVisitor* visitor) -> void override
		{
			
		}
	};
}