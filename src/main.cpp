#include <iostream>

#include "block.h"

int main() {
    std::cout << twochains::Block::CalculateHash("Testing") << '\n';
    return 0;
}
