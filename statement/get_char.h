#pragma once

#include "statement.h"

namespace parser
{
    class GetChar : public Statement
    {
    public:
        std::string to_string() const override;
        std::string code() const override;

        explicit GetChar(StatementPtr&&);
    };
} // namespace parser