export module atemc.ast.types.constantdeclarationexprast;

import <memory>;

import atemc.ast.types.declarationexprast;

export namespace atemc
{
	class ConstantDeclarationExprAST : public DeclarationExprAST
	{
		std::shared_ptr<ExprAST> initializer_expr_;
	public:
		explicit ConstantDeclarationExprAST(std::shared_ptr<ExprAST> initializer_expr)
			: initializer_expr_(initializer_expr)
		{}

		auto accept(ASTVisitor* visitor) -> void override
		{
			
		}

		auto getInitializerExpression() const noexcept -> std::weak_ptr<ExprAST> { return this->initializer_expr_; }
		auto setInitializerExpression(std::shared_ptr<ExprAST> initializer_expr) noexcept -> void { this->initializer_expr_ = initializer_expr;}
	};
}
