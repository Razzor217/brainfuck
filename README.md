# brainfuck

This project implements a simple compiler for the brainfuck language.
The parser controls a lexer and parses a list of statements from a token stream.
All assumptions made are described [here](assumptions.md)

## Usage

First, initialize the parser with a list of brainfuck statements, provided via `std::istream`, e.g. `std::cin`.
Then, the syntax tree can be created with `parse_statements()`.
A high-level string representation can be created by calling `to_string()` on the syntax tree, whereas
assembly-like code can be created by calling `code()`.

Example (see [main](#main.cpp))
```cpp
parser::Parser p {std::cin};
parser::StatementPtr stmts {p.parse_statements()};

std::cout << stmts->to_string() << std::endl;
std::cout << stmts->code() << std::endl;
```

## Planned features

* Implementation of an error mode that based on anchor sets
* Code analysis and optimizations based on fixed-point iterations
