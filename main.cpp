#include "parser.h"

int main()
{
    parser::Parser p {std::cin};
    parser::StatementPtr stmts {p.parse_statements()};

    std::cout << stmts->to_string() << std::endl;
    std::cout << stmts->code() << std::endl;

    return 0;
}