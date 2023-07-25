export module atemc.ast.builder;

import <memory>;
import <any>;
import <map>;

import atemc.grammar.basevisitor;
import atemc.grammar.parser;

import <antlr4-runtime.h>;

import atemc.ast.types;
import atemc.basic;
import atemc.exception;
#include <llvm/IR/Type.h>

export namespace atemc
{
	using namespace antlrcpp;

	class ASTBuilder : public AtemParserBaseVisitor
	{
		AtemParser* parser_ = nullptr;

	public:
		explicit ASTBuilder(AtemParser* parser) : parser_(parser) {}

		auto buildRootSourceFileProjectDeclaration(AtemParser::ProgramContext* ctx, std::shared_ptr<RawSourceFile> root_source_file_ptr)
			-> std::shared_ptr<ProjectDeclarationExprAST>
		{
			for(const auto& stmt : ctx->statements()->statement())
			{
				if(auto project_ctx = stmt->declaration_statement()->declaration_expression()->project_declaration())
				{
					auto project_ast_ptr = std::any_cast<std::shared_ptr<ProjectDeclarationExprAST>>
						(this->visitProject_declaration(project_ctx));
					return project_ast_ptr;
				}
			}
			throw ParseException("The root source file MUST ONLY contain one project declaration");
		}

		auto visitProject_declaration(AtemParser::Project_declarationContext* ctx)
			-> std::any override
		{
			auto aggr_init_ctx = ctx->aggregate_initialization_expression();
			auto aggr_init_ast_ptr = std::any_cast<std::shared_ptr<AggregateInitializationExprAST>>
				(this->visitAggregate_initialization_expression(aggr_init_ctx));
			return std::make_shared<ProjectDeclarationExprAST>(aggr_init_ast_ptr);
		}

		auto visitAggregate_initialization_expression_(AtemParser::Aggregate_initialization_expression_Context* ctx)
			-> std::any override
		{
			auto type = std::any_cast<TypeExprAST>(this->visit(ctx->type_expression()));
			return std::make_shared<AggregateInitializationExprAST>(
					type,
					std::any_cast<std::map<ExprAST, ExprAST>>(
						this->visitAggregate_initialization_list(ctx->aggregate_initialization_expression()->aggregate_initialization_list())
					)
				);
		}

		auto visitAggregate_initialization_list(AtemParser::Aggregate_initialization_listContext* ctx)
			-> std::any override
		{
			std::map<ExprAST, ExprAST> aggregate_members;
			for(auto aggregate_member : ctx->aggregate_initialization_member())
			{
				aggregate_members.insert(std::any_cast<std::pair<ExprAST, ExprAST>>(this->visitAggregate_initialization_member(aggregate_member)));
			}
			return aggregate_members;
		}

		auto visitAggregate_initialization_member(AtemParser::Aggregate_initialization_memberContext* ctx)
			-> std::any override
		{
			if(auto init = ctx->aggregate_initialization_list())
			{
				this->visitAggregate_initialization_list(init);
			}
			auto expr = std::any_cast<ExprAST>(this->visit(ctx->expression()));
			auto member = std::any_cast<ExprAST>(this->visit(ctx->aggregate_member()->expression()));
			return std::pair(member, expr);
		}
	};
}
