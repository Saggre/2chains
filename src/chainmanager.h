//
// Created by Sakri Koskimies on 12/12/20.
//

#ifndef INC_2CHAINS_CHAINMANAGER_H
#define INC_2CHAINS_CHAINMANAGER_H

#include <vector>

#include "block.h"

namespace twochains {
    class ChainManager {
    public:
        /**
         * Init the chain with a genesis block
         * @param genesis_block
         */
        explicit ChainManager(const Block &genesis_block) {
            blockchain.push_back(genesis_block);
        }

        /**
         * Generate a new block and add it to the chain
         * @param payload
         * @return
         */
        Block *GenerateNextBlock(BlockPayload payload) {
            auto previous_block = GetLatestBlock();
            auto timestamp = Block::GetCurrentTimestamp();

            blockchain.emplace_back(previous_block->GetIndex() + 1, previous_block->GetHash(), timestamp, payload);

            return &blockchain.back();
        };

        /**
         * Get reference to the latest block
         * @return
         */
        Block *GetLatestBlock() {
            return &blockchain.back();
        }

    protected:
    private:


    public:
    protected:
    private:
        std::vector<Block> blockchain;
    };
}

#endif //INC_2CHAINS_CHAINMANAGER_H
