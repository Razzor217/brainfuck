#pragma once

#include <memory>
#include <string>

namespace parser
{
    class Statement
    {
    public:
        using StatementPtr = std::unique_ptr<Statement>;

        virtual std::string to_string() const;
        virtual std::string code() const;

        explicit Statement() = default;
        explicit Statement(StatementPtr&&);

        Statement(Statement const&) = default;
        Statement(Statement&&) = default;

        Statement& operator=(Statement const&) = default;
        Statement& operator=(Statement&&) = default;

    protected:
        StatementPtr next_ {nullptr};
    };

    using StatementPtr = Statement::StatementPtr;
} // namespace parser