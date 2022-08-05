#include "put_char.h"

#include "instructions/instructions.h"

std::string parser::PutChar::to_string() const
{
    return "put_char\n"
        + (next_ ? next_->to_string() : "");
}

std::string parser::PutChar::code() const
{
    // write content of r2 to stdout
    return transformation::write(2)
        + (next_ ? next_->code() : "");
}

parser::PutChar::PutChar(StatementPtr&& ptr) :
    Statement {std::move(ptr)}
{
}