export module atemc.basic.sourcelocation;

import std;

export namespace atemc
{
	namespace fs = std::filesystem;
	struct SourceLocation
	{
		fs::path source_file_path;
		size_t column;
		size_t line;
	};
}
