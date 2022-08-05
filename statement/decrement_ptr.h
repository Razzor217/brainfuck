#pragma once

#include "statement.h"

namespace parser
{
    class DecrementPtr : public Statement
    {
    public:
        std::string to_string() const override;
        std::string code() const override;

        explicit DecrementPtr(StatementPtr&&);
    };
} // namespace parser