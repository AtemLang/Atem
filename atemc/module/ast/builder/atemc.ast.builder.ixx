export module atemc.ast.builder;

import <memory>;

import atemc.grammar;

import <antlr4-runtime.h>;

import atemc.ast.types;
import atemc.basic;

export namespace atemc
{
	using namespace antlrcpp;

	class ASTBuilder : public AtemParserBaseVisitor
	{
		AtemParser* parser_ = nullptr;

	public:
		explicit ASTBuilder(AtemParser* parser) : parser_(parser) {}

		auto build(AtemParser::ProgramContext* ctx, std::shared_ptr<RawSourceFile> root_source_file_ptr) -> std::shared_ptr<SourceAST>
		{
			return nullptr;
		}
	};
}