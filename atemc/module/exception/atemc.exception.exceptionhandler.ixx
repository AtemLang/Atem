export module atemc.exception.exceptionhandler;

import <print>;
import <exception>;

import <boost/stacktrace.hpp>;

import atemc.exception.abstractexception;

export namespace atemc 
{
	auto ExceptionHandler() -> void 
	{
		namespace st = boost::stacktrace;

		st::stacktrace stacktrace{};

		try {
			std::rethrow_exception(std::current_exception());
		}
		catch (const AbstractException& e) {
			std::println("Exception (Atemc Exception) : {}", e.what());
			std::println("Recognized Atemc exception instance, printing accurate stacktrace : ");
			stacktrace = e.getStacktrace();
		}
		catch (const std::exception& e) {
			std::println("Exception (Standard Library Exception) : {}", e.what());
		}
		catch (...) {
			std::println("Exception : Unknown exception");
		}
		
		for(const auto& frame : stacktrace)
		{
			if (!frame.source_file().empty())
			{
				std::println("\tat {}({}) in {} line {}", frame.name(), frame.address(), frame.source_file(), frame.source_line());
			}
			else
			{
				std::println("\tat {}({}) in unknown source", frame.name(), frame.address());
			}
		}
		exit(-1);
	}
}