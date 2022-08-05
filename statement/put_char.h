#pragma once

#include "statement.h"

namespace parser
{
    class PutChar : public Statement
    {
    public:
        std::string to_string() const override;
        std::string code() const override;

        explicit PutChar(StatementPtr&&);
    };
} // namespace parser