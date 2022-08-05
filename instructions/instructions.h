#include <string>

namespace transformation
{
    // std::string add(std::size_t const&, std::size_t const&, std::size_t const&);
    std::string addi(std::size_t const&, std::size_t const&, std::size_t const&);
    // std::string sub(std::size_t const&, std::size_t const&, std::size_t const&);
    std::string subi(std::size_t const&, std::size_t const&, std::size_t const&);

    std::string load(std::size_t const&, std::size_t const&, std::size_t const&);
    std::string store(std::size_t const&, std::size_t const&, std::size_t const&);

    std::string jmp(std::string const&);
    std::string jz(std::size_t const&, std::string const&);

    std::string read(std::size_t const&);
    std::string write(std::size_t const&);
} // namespace transformation