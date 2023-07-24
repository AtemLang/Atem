export module atemc.basic.rawsourcefile;

import <filesystem>;
import <fstream>;
import <exception>;
import <format>;
import <memory>;

import atemc.basic.object;

export namespace atemc 
{
	namespace fs = std::filesystem;
	class RawSourceFile : public AtemcObject
	{
		fs::path source_file_path_;
		std::shared_ptr<std::fstream> source_file_stream_{};
	public:
		RawSourceFile(const fs::path& source_file_path) : source_file_path_(source_file_path)
		{
			if (not fs::exists(this->source_file_path_))
			{
				throw std::invalid_argument(std::format("Source file \"{}\" doesn't exist!", this->source_file_path_.string()));
			}
			this->source_file_stream_->open(this->source_file_path_.string());
		}

		auto getSourceFileStream() const { return this->source_file_stream_; }
	};
}