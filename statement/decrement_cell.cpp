#include "decrement_cell.h"

#include "instructions/instructions.h"

std::string parser::DecrementCell::to_string() const
{
    return "decrement_cell\n"
        + (next_ ? next_->to_string() : "");
}

std::string parser::DecrementCell::code() const
{
    /*
     * load [r1] into r2
     * add 1 to r2
     * store r2 in [r1]
     */
    return transformation::load(2, 1, 0)
        + transformation::subi(2, 2, 1)
        + transformation::store(2, 1, 0)
        + (next_ ? next_->code() : "");
}

parser::DecrementCell::DecrementCell(StatementPtr&& ptr) :
    Statement {std::move(ptr)}
{
}