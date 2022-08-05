#pragma once

#include "statement.h"

namespace parser
{
    class Loop : public Statement
    {
    public:
        std::string to_string() const override;
        std::string code() const override;

        explicit Loop(StatementPtr&&, StatementPtr&&, std::size_t const&);
    
    private:
        std::string new_label() const;

    private:
        StatementPtr body_;
        std::size_t counter_;
    };
} // namespace parser