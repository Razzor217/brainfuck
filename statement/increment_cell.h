#pragma once

#include "statement.h"

namespace parser
{
    class IncrementCell : public Statement
    {
    public:
        std::string to_string() const override;
        std::string code() const override;

        explicit IncrementCell(StatementPtr&&);
    };
} // namespace parser