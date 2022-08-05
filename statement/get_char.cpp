#include "get_char.h"

#include "instructions/instructions.h"

std::string parser::GetChar::to_string() const
{
    return "get_char\n"
        + (next_ ? next_->to_string() : "");
}

std::string parser::GetChar::code() const
{
    // read one character from stdin, store in r2
    return transformation::read(2)
        + (next_ ? next_->code() : "");
}

parser::GetChar::GetChar(StatementPtr&& ptr) :
    Statement {std::move(ptr)}
{
}