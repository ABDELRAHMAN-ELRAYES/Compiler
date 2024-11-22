#pragma

#include <string>
#include <cstdint>

struct CodeLoc
{
    uint64_t line;
    uint64_t column;

    [[nodiscard]] std::string print() const;
};
