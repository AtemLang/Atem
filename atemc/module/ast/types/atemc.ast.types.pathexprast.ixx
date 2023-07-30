export module atemc.ast.types.pathexprast;

import <string>;
import <vector>;

import atemc.ast.types.exprast;

export namespace atemc
{
	class PathExprAST : public ExprAST
	{
		std::vector<std::u32string> path_expression_elements_;
	public:
		auto accept(ASTVisitor* visitor) -> void override
		{
			
		}
	};
}