#include <iostream>

#include "chainmanager.h"
#include "block.h"

int main() {
    char data[256] = "hey";

    twochains::Block genesis_block(0, "", twochains::Block::GetCurrentTimestamp(), twochains::BlockPayload(data));
    twochains::ChainManager chain(genesis_block);

    char lorem[256] = "Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat.";
    chain.GenerateNextBlock(twochains::BlockPayload(lorem));

    std::cout << chain.GetLatestBlock()->GetPayload().data_ << '\n';
    std::cout << chain.GetLatestBlock()->GetHash() << '\n';

    return 0;
}
