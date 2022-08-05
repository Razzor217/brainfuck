#include "token.h"

std::string lexer::to_string(lexer::TokenKey const& key)
{
    switch (key)
    {
        case TokenKey::T_EOF:       return "T_EOF";
        case TokenKey::T_GT:        return "T_GT";
        case TokenKey::T_LT:        return "T_LT";
        case TokenKey::T_PLUS:      return "T_PLUS";
        case TokenKey::T_MINUS:     return "T_MINUS";
        case TokenKey::T_DOT:       return "T_DOT";
        case TokenKey::T_COMMA:     return "T_COMMA";
        case TokenKey::T_LBRACKET:  return "T_LBRACKET";
        case TokenKey::T_RBRACKET:  return "T_RBRACKET";
        case TokenKey::T_INVALID:
        default:                    return "T_INVALID";
    }
}

lexer::TokenKey lexer::Token::key() const
{
    return key_;
}

std::string lexer::Token::value() const
{
    return value_;
}

std::ptrdiff_t lexer::Token::position() const
{
    return position_;
}

lexer::Token::Token(lexer::TokenKey const& key,
    std::string const& value,
    std::ptrdiff_t const& position) :
    key_ {key},
    value_ {value},
    position_ {position}
{
}

std::ostream& lexer::operator<<(std::ostream& out, lexer::Token const& token)
{
    out << lexer::to_string(token.key()) << ", "
        << token.value() << ", "
        << token.position() << std::endl;
    return out;
}