#pragma once

#include "statement.h"

namespace parser
{
    class IncrementPtr : public Statement
    {
    public:
        std::string to_string() const override;
        std::string code() const override;

        explicit IncrementPtr(StatementPtr&&);
    };
} // namespace parser