#include "lexer.h"

lexer::TokenPtr lexer::Lexer::next_token()
{
    switch (current_character_)
    {
        case '#':   return std::make_shared<Token>(TokenKey::T_EOF,         "#", next_char());
        case '>':   return std::make_shared<Token>(TokenKey::T_GT,          ">", next_char());
        case '<':   return std::make_shared<Token>(TokenKey::T_LT,          "<", next_char());
        case '+':   return std::make_shared<Token>(TokenKey::T_PLUS,        "+", next_char());
        case '-':   return std::make_shared<Token>(TokenKey::T_MINUS,       "-", next_char());
        case '.':   return std::make_shared<Token>(TokenKey::T_DOT,         ".", next_char());
        case ',':   return std::make_shared<Token>(TokenKey::T_COMMA,       ",", next_char());
        case '[':   return std::make_shared<Token>(TokenKey::T_LBRACKET,    "[", next_char());
        case ']':   return std::make_shared<Token>(TokenKey::T_RBRACKET,    "]", next_char());
        default:    return std::make_shared<Token>(TokenKey::T_INVALID,     "{invalid token}", next_char());
    }
}

lexer::Lexer::Lexer(std::istream& input) :
    input_ {&input, [](std::istream*){}}
{
    next_char();
}

std::ptrdiff_t lexer::Lexer::next_char()
{
    current_character_ = input_->get();
    return current_position_++;
}