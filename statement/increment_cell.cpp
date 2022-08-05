#include "increment_cell.h"

#include "instructions/instructions.h"

std::string parser::IncrementCell::to_string() const
{
    return "increment_cell\n"
        + (next_ ? next_->to_string() : "");
}

std::string parser::IncrementCell::code() const
{
    /*
     * load [r1] into r2
     * add 1 to r2
     * store r2 in [r1]
     */
    return transformation::load(2, 1, 0)
        + transformation::addi(2, 2, 1)
        + transformation::store(2, 1, 0)
        + (next_ ? next_->code() : "");
}

parser::IncrementCell::IncrementCell(StatementPtr&& ptr) :
    Statement {std::move(ptr)}
{
}