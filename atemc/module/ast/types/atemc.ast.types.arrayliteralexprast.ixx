export module atemc.ast.types.arrayliteralexprast;

import <vector>;
import <memory>;
import <ranges>;

import atemc.ast.types.literalexprast;

export namespace atemc
{
	class ArrayLiteralExprAST : public LiteralExprAST
	{
		std::vector<std::shared_ptr<ExprAST>> array_literal_expr_list_;

	public:
		explicit ArrayLiteralExprAST(const std::vector<std::shared_ptr<ExprAST>>& array_literal_expr_list)
			: array_literal_expr_list_(array_literal_expr_list)
		{}
		explicit ArrayLiteralExprAST(std::vector<std::shared_ptr<ExprAST>>&& array_literal_expr_list) noexcept
			: array_literal_expr_list_(std::move(array_literal_expr_list))
		{}

		auto operator=(const std::vector<std::shared_ptr<ExprAST>>& array_literal_expr_list) -> ArrayLiteralExprAST&
		{
			this->array_literal_expr_list_.operator=(array_literal_expr_list);
			return *this;
		}
		auto operator=(std::vector<std::shared_ptr<ExprAST>>&& array_literal_expr_list) noexcept -> ArrayLiteralExprAST&
		{
			this->array_literal_expr_list_.operator=(std::move(array_literal_expr_list));
			return *this;
		}

		auto getArrayLiteralLength() const noexcept -> size_t { return this->array_literal_expr_list_.size(); }

		auto getChildren() -> std::vector<std::shared_ptr<AbstractAST>> override
		{
			return std::ranges::to<std::vector>(
				std::views::transform(this->array_literal_expr_list_, 
					[](std::shared_ptr<ExprAST> ptr)
					{
						return std::dynamic_pointer_cast<AbstractAST>(ptr);
					}
				)
			);
		}
	};
}
