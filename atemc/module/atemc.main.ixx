export module atemc.main;

import atemc.exception;

export int main(int argc, const char* argv[])
{
	try
	{
		throw atemc::AbstractException("awa");
	}
	catch(atemc::AbstractException& exception)
	{
		exception.printStacktrace();
	}
	return 0;
}