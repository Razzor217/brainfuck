#pragma once

#include <iostream>
#include <memory>
#include <string>

namespace lexer
{
    enum class TokenKey
    {
        T_EOF,
        T_GT,
        T_LT,
        T_PLUS,
        T_MINUS,
        T_DOT,
        T_COMMA,
        T_LBRACKET,
        T_RBRACKET,
        T_INVALID
    };

    std::string to_string(TokenKey const&);

    class Token
    {
    public:
        TokenKey key() const;
        std::string value() const;
        std::ptrdiff_t position() const;

        explicit Token() = default;
        explicit Token(TokenKey const&, std::string const&, std::ptrdiff_t const&);

        Token(Token const&) = default;
        Token(Token&&) = default;

        Token& operator=(Token const&) = default;
        Token& operator=(Token&&) = default;

    private:
        TokenKey key_ {TokenKey::T_INVALID};
        std::string value_ {};
        std::ptrdiff_t position_ {};
    };

    using TokenPtr = std::shared_ptr<Token>;

    std::ostream& operator<<(std::ostream&, Token const&);
} // namespace lexer