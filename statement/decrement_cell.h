#pragma once

#include "statement.h"

namespace parser
{
    class DecrementCell : public Statement
    {
    public:
        std::string to_string() const override;
        std::string code() const override;

        explicit DecrementCell(StatementPtr&&);
    };
} // namespace parser