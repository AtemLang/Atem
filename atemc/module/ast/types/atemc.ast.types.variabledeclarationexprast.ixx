export module atemc.ast.types.variabledeclarationexprast;

import <memory>;

import atemc.ast.types.declarationexprast;

export namespace atemc
{
	class VariableDeclarationExprAST : public DeclarationExprAST
	{
		std::shared_ptr<ExprAST> initializer_expr_;
	public:
		explicit VariableDeclarationExprAST(std::shared_ptr<ExprAST> initializer_expr)
			: initializer_expr_(initializer_expr)
		{}

		auto accept(ASTVisitor* visitor) -> void override
		{
			
		}

		auto getInitializerExpression() const noexcept -> std::shared_ptr<ExprAST> { return this->initializer_expr_; }
		auto setInitializerExpression(std::shared_ptr<ExprAST> initializer_expr) noexcept -> void { this->initializer_expr_ = initializer_expr;}
	};
}
