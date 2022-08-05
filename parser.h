#pragma once

#include "lexer.h"
#include "statement.h"

namespace parser
{
    class Parser
    {
    public:
        StatementPtr parse_statements();

        explicit Parser(std::istream&);

        Parser(Parser const&) = delete;
        Parser(Parser&&) = default;

        Parser& operator=(Parser const&) = delete;
        Parser& operator=(Parser&&) = default;

    private:
        StatementPtr parse_statement();
        void next_token();
        void expect(lexer::TokenKey const&);

    private:
        lexer::LexerPtr lexer_;
        lexer::TokenPtr current_token_ {};

        std::size_t counter_ {};
    };

    using ParserPtr = std::unique_ptr<Parser>;
} // namespace parser