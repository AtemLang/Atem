export module atemc.ast.types.declstmtast;

import <memory>;
import <string>;

import atemc.ast.types.stmtast;	

export namespace atemc 
{
	class ExprAST;
	class TypeExprAST;
	class PathExprAST;

	class DeclStmtAST: public StmtAST
	{
		std::shared_ptr<ExprAST> declaration_expr_;
		std::shared_ptr<TypeExprAST> type_expr_;
		std::shared_ptr<PathExprAST> identifier_;


	};
}