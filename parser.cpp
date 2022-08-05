#include "parser.h"

parser::StatementPtr parser::Parser::parse_statements()
{
    if (current_token_->key() != lexer::TokenKey::T_EOF)
    {
        return parse_statement();
    }
    return nullptr;
}

parser::Parser::Parser(std::istream& input) :
    lexer_ {std::make_unique<lexer::Lexer>(input)}
{
    next_token();
}

parser::StatementPtr parser::Parser::parse_statement()
{
    switch (current_token_->key())
    {
        case lexer::TokenKey::T_GT:         next_token(); return std::make_unique<IncrementPtr>(parse_statement());
        case lexer::TokenKey::T_LT:         next_token(); return std::make_unique<DecrementPtr>(parse_statement());
        case lexer::TokenKey::T_PLUS:       next_token(); return std::make_unique<IncrementCell>(parse_statement());
        case lexer::TokenKey::T_MINUS:      next_token(); return std::make_unique<DecrementCell>(parse_statement());
        case lexer::TokenKey::T_DOT:        next_token(); return std::make_unique<PutChar>(parse_statement());
        case lexer::TokenKey::T_COMMA:      next_token(); return std::make_unique<GetChar>(parse_statement());
        case lexer::TokenKey::T_LBRACKET:
        {
            next_token();
            StatementPtr body {parse_statement()};
            expect(lexer::TokenKey::T_RBRACKET);
            return std::make_unique<Loop>(parse_statements(), std::move(body), counter_++);
        }
        case lexer::TokenKey::T_RBRACKET:   
        case lexer::TokenKey::T_EOF:        return nullptr;
        default:                            return std::make_unique<Statement>(parse_statement());
    }
}

void parser::Parser::next_token()
{
    current_token_ = lexer_->next_token();
}

void parser::Parser::expect(lexer::TokenKey const& key)
{
    if (current_token_->key() != key)
    {
        /* 
         * todo: 
         * - switch to error mode, print error messages
         * - skip tokens until token from anchor set or key is found
         */
    }
    next_token();
    // return from error mode
}