export module atemc.exception.abstractexception;

import <string>;
import <print>;

import <boost/stacktrace.hpp>;

import atemc.basic;

export namespace atemc
{
	namespace bs = boost::stacktrace;
	class AbstractException : public std::exception, public AtemcObject
	{
		const std::string msg_;
		const bs::stacktrace current_stacktrace_;
	public:
		AbstractException(std::string_view msg, const bs::stacktrace& current_stacktrace = bs::stacktrace())
			: msg_(msg), current_stacktrace_(current_stacktrace)
		{}
		auto what() const noexcept -> const char* override
		{
			return this->msg_.c_str();
		}
		auto getStacktrace() const -> bs::stacktrace { return this->current_stacktrace_; }
		virtual auto printStacktrace() const noexcept -> void
		{
			std::println("Exception \"{}\" with stacktrace: ", this->msg_);
			for(auto entry : this->current_stacktrace_)
			{
				std::println
				(
					"\tat {}({}) in file {} line {}", 
					entry.name(),
					entry.address(),
					entry.source_file(), 
					entry.source_line()
				);
			}
		}
	};
}