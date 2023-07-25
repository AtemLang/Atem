export module atemc.ast.types.projectdeclarationexprast;

import <memory>;

import atemc.ast.types.declarationexprast;
import atemc.ast.types.aggregateinitializationexprast;

export namespace atemc
{
	class ProjectDeclarationExprAST : public DeclarationExprAST
	{
	public:
		ProjectDeclarationExprAST(std::shared_ptr<AggregateInitializationExprAST> initialization)
		{
			
		}
	};
}
