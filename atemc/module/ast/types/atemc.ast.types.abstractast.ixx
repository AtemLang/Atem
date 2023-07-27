export module atemc.ast.types.abstractast;

import <vector>;
import <memory>;
import <compare>;

import atemc.basic;

export class ASTVisitor;

export namespace atemc
{
	class AbstractAST : public AtemcObject
	{
		SourceLocation source_location_{};

	public:
		AbstractAST() = default;
		AbstractAST(const AbstractAST& that) = default;
		AbstractAST(AbstractAST&& that) noexcept = default;

		auto operator=(const AbstractAST& that) -> AbstractAST& = default;
		auto operator=(AbstractAST&& that) noexcept -> AbstractAST& = default;

		virtual ~AbstractAST() = default;

		auto getSourceLocation() const noexcept -> SourceLocation { return this->source_location_; }
		auto setSourceLocation(const SourceLocation& src_loc) noexcept -> void { this->source_location_ = src_loc; }

		virtual auto accept(ASTVisitor* visitor) -> void = 0;

		virtual auto getChildren() -> std::vector<std::shared_ptr<AbstractAST>> { return {}; }

		virtual auto operator<=>(const AbstractAST& that) const -> std::strong_ordering
		{
			return this->source_location_.operator<=>(that.source_location_);
		}
	};
}