export module atemc.exception.parseexception;

import <string>;

import <boost/stacktrace.hpp>;

import atemc.exception.abstractexception;

export namespace atemc
{
	namespace bs = boost::stacktrace;
	class ParseException: public AbstractException
	{
	public:
		ParseException(std::string_view msg, const bs::stacktrace& current_stacktrace = bs::stacktrace()) : AbstractException(msg, current_stacktrace) {}
	};
}