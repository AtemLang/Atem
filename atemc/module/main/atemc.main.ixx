module;

#include <cxxopts.hpp>

export module atemc.main;

import <string>;
import <print>;
import <exception>;
import <memory>;

import atemc.basic;
import atemc.frontend;
import atemc.exception;

export int main(int argc, const char* argv[])
{
	using namespace atemc;
	using namespace cxxopts;

	std::set_terminate(ExceptionHandler);

	throw AbstractException("awa");

	Options option("Atem Compiler", "Experimental Compiler for Atem Programming Language\nDistributed under GPL-3.0-or-later license\nCopyright Atem Language Team, 2023");

	option.add_options()
		("h,help", "Print help message")
		("s,source", "Atem source file path", value<std::string>())
		("d,debug", "Enable debug output", value<bool>()->default_value("false"))
	;

	auto result = option.parse(argc, argv);

	if(result.count("help") > 0 or argc <= 1)
	{
		std::print("{}", option.help());
		return 0;
	}

	if(result.count("source") > 0)
	{
		try
		{
			std::shared_ptr<RawSourceFile> source_file_ptr = std::make_shared<RawSourceFile>(result["source"].as<std::string>());
		}
		catch(const std::invalid_argument& exception)
		{
			std::println("{}", exception.what());
			return 0;
		}
	}

	return 0;
}