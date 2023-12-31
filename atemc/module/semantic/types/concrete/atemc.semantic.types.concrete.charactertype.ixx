export module atemc.semantic.types.concrete.charactertype;

import <string>;

import <fmt/compile.h>;
import <fmt/xchar.h>;

import atemc.semantic.types.concrete.compositetype;

export namespace atemc
{
	class CharacterType : public CompositeType
	{
	public:
		enum class CharacterWidthKind : int
		{
			CWK_UTF8 = 8,
			CWK_UTF16 = 16,
			CWK_UTF32 = 32
		};

	private:
		CharacterWidthKind character_width_kind_;

	public:
		explicit CharacterType(CharacterWidthKind character_width_kind)
			: character_width_kind_(character_width_kind)
		{}

		auto getCharacterWidthKind() const noexcept -> CharacterWidthKind { return this->character_width_kind_; }
		auto setCharacterWidthKind(CharacterWidthKind character_width_kind) noexcept -> void { this->character_width_kind_ = character_width_kind; }

		auto operator==(const TypeExprAST& that) const -> bool override
		{
			if(auto that_ptr = dynamic_cast<const CharacterType*>(&that); this->character_width_kind_ == that_ptr->character_width_kind_)
			{
				return true;
			}
			return false;
		}

		auto accept(TypeVisitor* visitor) -> void override
		{
			
		}

		auto getMangledTypeString() const -> std::u32string override
		{
			return fmt::format(FMT_COMPILE(U"Char{}"), std::to_underlying(this->character_width_kind_));
		}
	};
}