#include "increment_ptr.h"

#include "instructions/instructions.h"

std::string parser::IncrementPtr::to_string() const
{
    return "increment_ptr\n"
        + (next_ ? next_->to_string() : "");
}

std::string parser::IncrementPtr::code() const
{
    // add 1 to r1, store in r1
    return transformation::addi(1, 1, 1)
        + (next_ ? next_->code() : "");
}

parser::IncrementPtr::IncrementPtr(StatementPtr&& ptr) :
    Statement {std::move(ptr)}
{
}