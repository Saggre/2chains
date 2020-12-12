#include <iostream>

#include "chainmanager.h"
#include "block.h"

int main() {
    char data[256] = "hey";

    twochains::Block genesis_block(0, "", twochains::Block::GetCurrentTimestamp(), twochains::BlockPayload(data));
    twochains::ChainManager chain(genesis_block);

    std::cout << chain.GetLatestBlock()->GetPayload().data_ << '\n';
    std::cout << chain.GetLatestBlock()->GetHash() << '\n';

    return 0;
}
