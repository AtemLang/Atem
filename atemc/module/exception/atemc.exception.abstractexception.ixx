export module atemc.exception.abstractexception;

import <string>;
import <print>;

import <boost/stacktrace.hpp>;

import atemc.basic;

export namespace atemc
{
	class AbstractException : public std::exception, public AtemcObject
	{
		const std::string msg_;
		const boost::stacktrace::stacktrace current_stacktrace_;
	public:
		AbstractException(std::string_view msg, const boost::stacktrace::stacktrace& current_stacktrace = boost::stacktrace::stacktrace())
			: msg_(msg), current_stacktrace_(current_stacktrace)
		{}
		auto what() const noexcept -> const char* override
		{
			return this->msg_.c_str();
		}
		virtual auto printStacktrace() const noexcept -> void
		{
			std::println("Exception \"{}\" with stacktrace: ", this->msg_);
			for(const auto& entry : this->current_stacktrace_)
			{
				std::println(
					"\tat {}(0x{:x}), file {}, line {}", 
					entry.name(),
					entry.address(),
					entry.source_file(), 
					entry.source_line()
				);
			}
		}
	};
}