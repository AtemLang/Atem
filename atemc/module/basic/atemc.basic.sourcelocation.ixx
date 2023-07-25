export module atemc.basic.sourcelocation;

import <filesystem>;
import <compare>;
import <functional>;

import <boost/container_hash/hash.hpp>;

export namespace atemc
{
	namespace fs = std::filesystem;
	struct SourceLocation
	{
		fs::path source_file_path;
		size_t column;
		size_t line;

		auto operator<=>(const SourceLocation& that) const -> std::strong_ordering
		{
			if(const auto cmp = this->source_file_path <=> that.source_file_path; not std::is_eq(cmp))
			{
				return this->source_file_path <=> that.source_file_path;
			}
			if (const auto cmp = this->line <=> that.line; not std::is_eq(cmp))
			{
				return this->line <=> that.line;
			}
			return this->column <=> that.column;
		}
	};
}

export {
	template<>
	struct std::hash<atemc::SourceLocation>
	{
		using argument_type = atemc::SourceLocation;
		using result_type = std::size_t;
	    auto operator()(const argument_type& s) const -> result_type
	    {
	        std::size_t seed = 0;
			boost::hash_combine(seed, hash<std::filesystem::path>{}(s.source_file_path));
			boost::hash_combine(seed, hash<std::size_t>{}(s.line));
			boost::hash_combine(seed, hash<std::size_t>{}(s.column));
			return seed;
	    }
	};
}
