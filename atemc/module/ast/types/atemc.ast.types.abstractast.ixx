export module atemc.ast.types.abstractast;

import atemc.basic;

export namespace atemc
{
	class AbstractAST
	{
		SourceLocation source_location_{};

	public:
		virtual ~AbstractAST() = default;
	};
}
