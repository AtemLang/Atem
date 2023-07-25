module;

#include <antlr4-runtime.h>

export module atemc.frontend;

import <memory>;
import <string>;

import atemc.grammar;

import atemc.ast;
import atemc.basic;
import atemc.exception;

export namespace atemc
{
	class LexerErrorListener : public antlr4::BaseErrorListener
	{
	public:
		LexerErrorListener() = default;

		auto syntaxError(
			antlr4::Recognizer *recognizer, 
			antlr4::Token *offendingSymbol,
			size_t line, 
			size_t charPositionInLine,
			const std::string &msg, 
			std::exception_ptr e
		) -> void override
		{
			throw ParseException(
				msg + "@" + std::to_string(line) + ":" + std::to_string(charPositionInLine)
			);
		}
	};

	class ParserErrorListener : public antlr4::BaseErrorListener
	{
	public:
		ParserErrorListener() = default;

		auto syntaxError(
			antlr4::Recognizer *recognizer, 
			antlr4::Token *offendingSymbol,
			size_t line, 
			size_t charPositionInLine,
			const std::string &msg, 
			std::exception_ptr e
		) -> void override
		{
			throw ParseException(
				msg + "@" + std::to_string(line) + ":" + std::to_string(charPositionInLine)
			);
		}
	};

	class FrontEnd : public AtemcObject
	{
	public:
		auto parseRootSourceFile(std::shared_ptr<RawSourceFile> source_file_ptr) -> std::shared_ptr<ProjectDeclarationExprAST>
		{
			using namespace antlr4;
			ANTLRInputStream input_stream(*source_file_ptr->getSourceFileStream());
			AtemLexer lexer(&input_stream);
			CommonTokenStream tokens(&lexer);
			AtemParser parser(&tokens);
			LexerErrorListener lexer_error_listener;
			ParserErrorListener parser_error_listener;

			lexer.removeErrorListeners();
			lexer.addErrorListener(&lexer_error_listener);

			parser.removeParseListeners();
			parser.removeErrorListeners();
			parser.addErrorListener(&parser_error_listener);

			AtemParser::ProgramContext* tree = parser.program();

			ASTBuilder ast_builder(&parser);
			return ast_builder.buildRootSourceFileProjectDeclaration(tree, source_file_ptr);
		}
	};
}
