export module atemc.ast.types.contractexprast;

import <memory>;

import atemc.ast.types.exprast;

export namespace atemc 
{
	class ReturnValueCapture
	{
		
	};

	class ContractExprAST : public ExprAST 
	{
	public:
		enum class ContractType : int
		{
			CT_ASSERT,
			CT_ASSUME,
			CT_EXPECT,
			CT_ENSURE,
		};

	private:
		ContractType contract_type_;
		std::shared_ptr<ExprAST> boolean_expr_;

	public:
		explicit ContractExprAST(ContractType contract_type, std::shared_ptr<ExprAST> boolean_expr)
			: contract_type_(contract_type), boolean_expr_(boolean_expr)
		{}

		auto getContractType() const noexcept -> ContractType { return this->contract_type_; }
		auto setContractType(ContractType contract_type) noexcept { this->contract_type_ = contract_type; }

		auto getBooleanExpr() const noexcept -> std::weak_ptr<ExprAST> { return this->boolean_expr_; }
		auto setBooleanExpr(std::shared_ptr<ExprAST> boolean_expr) noexcept { this->boolean_expr_ = boolean_expr; }
	};
}