module;

export module atemc.frontend;

import <string>;

import <antlr4-runtime.h>;
import "grammar/AtemLexer.h";
import "grammar/AtemParser.h";

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
		static auto parse(std::istream& stream) -> std::shared_ptr<ModuleAST>
		{
			using namespace antlr4;
			ANTLRInputStream input_stream(stream);
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
			return ast_builder.build(tree);
		}
	};
}
