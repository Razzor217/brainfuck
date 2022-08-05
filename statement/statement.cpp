#include "statement.h"

std::string parser::Statement::to_string() const
{
    return "{invalid statement}\n" + (next_ ? next_->to_string() : "");
}

std::string parser::Statement::code() const
{
    return "{nop}"
        + (next_ ? next_->code() : "");
}

parser::Statement::Statement(StatementPtr&& ptr) :
    next_ {std::move(ptr)}
{
}