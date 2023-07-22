export module atemc.ast.types.abstractast;

import std;

import atemc.basic;

export namespace atemc
{
	class ASTVisitor;

	class AbstractAST : public AtemcObject
	{
		SourceLocation source_location_{};

	public:
		virtual ~AbstractAST() = default;

		auto getSourceLocation() const noexcept -> SourceLocation { return this->source_location_; }
		auto setSourceLocation(const SourceLocation& src_loc) noexcept -> void { this->source_location_ = src_loc; }

		virtual auto accept(ASTVisitor* visitor) -> void = 0;

		virtual auto getChildren() const -> std::vector<std::shared_ptr<AbstractAST>> { return {}; }
	};
}