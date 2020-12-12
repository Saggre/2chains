//
// Created by Sakri Koskimies on 12/11/20.
//

#ifndef INC_2CHAINS_BLOCK_H
#define INC_2CHAINS_BLOCK_H

#define BLOCK_PAYLOAD_BYTES 256

#include <cryptopp/sha.h>
#include <cryptopp/hex.h>
#include <bitset>
#include <utility>

namespace twochains {
    struct BlockPayload {
        char data_[BLOCK_PAYLOAD_BYTES] = {0};

        explicit BlockPayload(char data[BLOCK_PAYLOAD_BYTES]) {
            strcpy(data_, data);
        }
    };

    class Block {
    public:
        Block(uint64_t index,
              std::string previous_hash,
              uint64_t timestamp,
              BlockPayload payload) :
                index_(index),
                previous_hash_(std::move(previous_hash)),
                timestamp_(GetCurrentTimestamp()),
                payload_(payload),
                hash_(CalculateHash(index, previous_hash, timestamp, payload)) {}

        /**
         * Calculate hash for a block's content
         * @param index
         * @param previous_hash
         * @param timestamp
         * @param payload
         * @return
         */
        static std::string
        CalculateHash(uint64_t index, const std::string &previous_hash, uint64_t timestamp, BlockPayload payload) {
            CryptoPP::SHA256 hash;

            std::string str = std::to_string(index) + previous_hash + std::to_string(timestamp) + payload.data_;

            byte digest[CryptoPP::SHA256::DIGESTSIZE];
            hash.CalculateDigest(digest, reinterpret_cast<const byte *> (str.c_str()), str.length());

            std::string output;

            CryptoPP::HexEncoder encoder;
            encoder.Attach(new CryptoPP::StringSink(output));
            encoder.Put(digest, sizeof(digest));
            encoder.MessageEnd();

            return output;
        }

        /**
         * Gets current time in millis
         * @return
         */
        static uint64_t GetCurrentTimestamp() {
            return std::chrono::duration_cast<std::chrono::milliseconds>(
                    std::chrono::system_clock::now().time_since_epoch()
            ).count();
        }

        const uint64_t &GetIndex() const {
            return index_;
        }

        const std::string &GetHash() const {
            return hash_;
        }

        const std::string &GetPreviousHash() const {
            return previous_hash_;
        }

        const uint64_t &GetTimestamp() const {
            return timestamp_;
        }

        const BlockPayload &GetPayload() const {
            return payload_;
        }

    protected:
    private:

    public:
    protected:
    private:
        const std::uint64_t index_;
        const std::string hash_;
        const std::string previous_hash_;
        const std::uint64_t timestamp_;
        const BlockPayload payload_;
    };
}

#endif //INC_2CHAINS_BLOCK_H
