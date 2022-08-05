#include "decrement_ptr.h"

#include "instructions/instructions.h"

std::string parser::DecrementPtr::to_string() const
{
    return "decrement_ptr\n"
        + (next_ ? next_->to_string() : "");
}

std::string parser::DecrementPtr::code() const
{
    // add 1 to r1, store in r1
    return transformation::subi(1, 1, 1)
        + (next_ ? next_->code() : "");
}

parser::DecrementPtr::DecrementPtr(StatementPtr&& ptr) :
    Statement {std::move(ptr)}
{
}