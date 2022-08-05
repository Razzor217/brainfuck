#include "loop.h"

#include "instructions/instructions.h"

std::string parser::Loop::to_string() const
{
    
    return "loop\n[\n"
        + (body_ ? body_->to_string() : "")
        + "]\n"
        + (next_ ? next_->to_string() : "");
}

std::string parser::Loop::code() const
{
    std::string label {new_label()};
    return transformation::jz(2, label)
        + (body_ ? body_->code() : "")
        + label + ":\n"
        + (next_ ? next_->code() : "");
}

parser::Loop::Loop(StatementPtr&& ptr,
    StatementPtr&& body,
    std::size_t const& counter) :
    Statement {std::move(ptr)},
    body_ {std::move(body)},
    counter_ {counter}
{
}

std::string parser::Loop::new_label() const
{
    return "L" + std::to_string(counter_);
}