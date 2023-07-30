export module atemc.ast.types.declstmtast;

import <memory>;
import <string>;

import atemc.ast.types.stmtast;	

export namespace atemc 
{
	class DeclarationExprAST;
	class TypeExprAST;
	class PathExprAST;

	class DeclStmtAST: public StmtAST
	{
		std::shared_ptr<DeclarationExprAST> declaration_expr_;
		std::shared_ptr<TypeExprAST> type_expr_;
		std::shared_ptr<PathExprAST> path_expr_;

	public:
		explicit DeclStmtAST(
				std::shared_ptr<DeclarationExprAST> declaration_expr,
				std::shared_ptr<TypeExprAST> type_expr,
				std::shared_ptr<PathExprAST> path_expr
			) : declaration_expr_(declaration_expr), type_expr_(type_expr), path_expr_(path_expr)
		{}
	};
}