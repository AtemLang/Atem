export module atemc.semantic.types.concrete.functiontype;

import <vector>;
import <string>;
import <memory>;
import <unordered_map>;
import <ranges>;

import <fmt/xchar.h>;

import atemc.semantic.types.concrete.compositetype;

export namespace atemc
{
	class FunctionParameter : public CompositeType
	{
	public:
		std::u32string function_parameter_name;
		std::u32string function_argument_label;
		std::shared_ptr<TypeExprAST> function_parameter_type;
		std::shared_ptr<ExprAST> function_parameter_default_value;

		explicit FunctionParameter(const FunctionParameter& that) :
			function_parameter_name(that.function_parameter_name),
			function_argument_label(that.function_argument_label),
			function_parameter_type(that.function_parameter_type),
			function_parameter_default_value(that.function_parameter_default_value)
		{}
		explicit FunctionParameter(FunctionParameter&& that) noexcept :
			function_parameter_name(std::move(that.function_parameter_name)),
			function_argument_label(std::move(that.function_argument_label)),
			function_parameter_type(std::move(that.function_parameter_type)),
			function_parameter_default_value(std::move(that.function_parameter_default_value))
		{}

		auto accept(TypeVisitor* visitor) -> void override
		{
			
		}

		auto getMangledTypeString() const -> std::u32string override
		{
			return fmt::format(
				U"({} {} : {})",
				this->function_argument_label,
				this->function_parameter_name,
				this->function_parameter_type->getMangledTypeString()
			);
		}
	};
	class FunctionParameterClauseType : public CompositeType 
	{
	public:
		explicit FunctionParameterClauseType(const std::vector<FunctionParameter>& parameters)
		{
			this->sub_type_map_.insert_range(
				std::ranges::to<std::unordered_map<std::u32string, std::shared_ptr<TypeExprAST>>>(
					std::views::transform(
						parameters,
						[](const FunctionParameter& param)
						{
							return std::make_tuple(
								param.function_parameter_name, 
								std::dynamic_pointer_cast<TypeExprAST>(
									std::make_shared<FunctionParameter>(param)
								)
							);
						}
					)
				)
			);
		}

		auto getFunctionParameterList() const -> std::vector<std::shared_ptr<FunctionParameter>>
		{
			return std::ranges::to<std::vector>(
				std::views::transform(
					std::views::values(this->sub_type_map_),
					[](std::shared_ptr<TypeExprAST> param)
					{
						return std::dynamic_pointer_cast<FunctionParameter>(param);
					}
				)
			);
		}
	};

	class FunctionType : public CompositeType
	{
	public:
		explicit FunctionType(
				std::shared_ptr<FunctionParameterClauseType> function_parameter_clause,
				std::shared_ptr<TypeExprAST> function_return_type
			)
		{
			this->sub_type_map_.at(U"function_parameters") = std::dynamic_pointer_cast<TypeExprAST>(function_parameter_clause);
			this->sub_type_map_.at(U"function_return_type") = function_return_type;
		}

		auto getFunctionParameterClause() const noexcept -> std::weak_ptr<FunctionParameterClauseType>
		{ return std::dynamic_pointer_cast<FunctionParameterClauseType>(this->sub_type_map_.at(U"function_parameters")); }
		auto setFunctionParameterClause(std::shared_ptr<FunctionParameterClauseType> function_parameter_clause) noexcept
		{ this->sub_type_map_.at(U"function_parameters") = function_parameter_clause; }

		auto getFunctionReturnType() const noexcept -> std::weak_ptr<TypeExprAST>
		{ return this->sub_type_map_.at(U"function_return_type"); }
		auto setFunctionReturnType(std::shared_ptr<TypeExprAST> function_return_type) noexcept
		{ this->sub_type_map_.at(U"function_return_type") = function_return_type; }
	};
}
