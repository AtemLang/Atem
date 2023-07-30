export module atemc.semantic.types.concrete.functiontype;

import <vector>;
import <string>;
import <memory>;
import <unordered_map>;
import <ranges>;

import atemc.semantic.types.concrete.compositetype;

export namespace atemc
{
	struct FunctionParameter
	{
		std::u32string function_parameter_name;
		std::u32string function_argument_label;
		std::shared_ptr<TypeExprAST> function_parameter_type;
	};
	class FunctionParameterClauseType : public CompositeType 
	{
	public:
		explicit FunctionParameterClauseType(const std::vector<FunctionParameter>& parameters)
		{
			
		}
	};

	class FunctionType : public CompositeType
	{
	public:
		explicit FunctionType(
				std::shared_ptr<FunctionParameterClauseType> function_parameter_clause,
				std::shared_ptr<TypeExprAST> function_return_type
			)
		{}
	};
}
