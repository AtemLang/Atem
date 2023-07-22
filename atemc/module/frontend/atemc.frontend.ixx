module;

export module atemc.frontend;

import <memory>;
import <istream>;

import atemc.ast;

export namespace atemc
{
	class FrontEnd
	{
		static auto parse(std::istream& stream) -> std::shared_ptr<ModuleAST>
		{
			
		}
	};
}
