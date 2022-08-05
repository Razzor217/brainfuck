#include "instructions.h"

std::string transformation::addi(std::size_t const& rz,
    std::size_t const& rx,
    std::size_t const& immediate)
{
    return "addi $" + std::to_string(rz)
        + ", $" + std::to_string(rx) 
        + ", " + std::to_string(immediate) + "\n";
}

std::string transformation::subi(std::size_t const& rz,
    std::size_t const& rx,
    std::size_t const& immediate)
{
    return "subi $" + std::to_string(rz)
        + ", $" + std::to_string(rx) 
        + ", " + std::to_string(immediate) + "\n";
}

std::string transformation::load(std::size_t const& rz,
    std::size_t const& rx,
    std::size_t const& offset)
{
    return "load $" + std::to_string(rz) 
        + ", " + std::to_string(offset)
        + "($" + std::to_string(rx) + ")\n";
}

std::string transformation::store(std::size_t const& rz,
    std::size_t const& rx,
    std::size_t const& offset)
{
    return "store $" + std::to_string(rz) 
        + ", " + std::to_string(offset)
        + "($" + std::to_string(rx) + ")\n";
}

std::string transformation::jmp(std::string const& label)
{
    return "jmp " + label + "\n";
}

std::string transformation::jz(std::size_t const& rx, std::string const& label)
{
    return "jz $" + std::to_string(rx)
        + ", " + label + "\n";
}

std::string transformation::read(std::size_t const& rx)
{
    return "read $" + std::to_string(rx) + "\n";
}

std::string transformation::write(std::size_t const& rx)
{
    return "write $" + std::to_string(rx) + "\n";
}