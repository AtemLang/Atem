export module atemc.ast.types.typeexprast;

import <memory>;
import <functional>;
import <string>;

export import atemc.ast.types.exprast;
export import atemc.semantic.types;

export namespace atemc 
{
	class TypeExprAST : public ExprAST 
	{		
		std::shared_ptr<AbstractType> type_ptr_;
	public:
		explicit TypeExprAST(std::shared_ptr<AbstractType> type_ptr) : type_ptr_(type_ptr)
		{
			
		}

		auto accept(ASTVisitor* visitor) -> void override {}

		virtual auto getType() const -> std::shared_ptr<AbstractType> { return this->type_ptr_; }
	};

	struct TypeExprASTHash
	{
	    std::size_t operator()(const TypeExprAST& s) const 
	    {
			return std::hash<std::string>{}(s.getType()->getMangledTypeString());
	    }
	};
}