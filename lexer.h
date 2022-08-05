#pragma once

#include <functional>

#include "token.h"

namespace lexer
{
    class Lexer
    {
    public:
        TokenPtr next_token();

        explicit Lexer(std::istream&);

        Lexer(Lexer const&) = delete;
        Lexer(Lexer&&) = default;

        Lexer& operator=(Lexer const&) = delete;
        Lexer& operator=(Lexer&&) = default;

    private:
        std::ptrdiff_t next_char();

    private:
        using deleter = std::function<void(std::istream*)>;

        std::unique_ptr<std::istream, deleter> input_;
        char current_character_ {-1};
        std::ptrdiff_t current_position_ {-1};
    };

    using LexerPtr = std::unique_ptr<Lexer>;
} // namespace lexer