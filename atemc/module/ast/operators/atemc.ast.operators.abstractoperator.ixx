export module atemc.ast.operators.abstractoperator;

import <string>;

import atemc.basic;

export namespace atemc
{
	class AbstractOperator : public AtemcObject
	{
	public:
		virtual ~AbstractOperator() = default;
	};
}