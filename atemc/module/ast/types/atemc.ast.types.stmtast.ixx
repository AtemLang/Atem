export module atemc.ast.types.stmtast;

export import atemc.ast.types.abstractast;	

export namespace atemc 
{
	class StmtAST: public AbstractAST
	{
	public:
		auto accept(ASTVisitor* visitor) -> void override
		{
			
		}
	};
}