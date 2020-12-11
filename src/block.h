//
// Created by Sakri Koskimies on 12/11/20.
//

#ifndef INC_2CHAINS_BLOCK_H
#define INC_2CHAINS_BLOCK_H

#include <cryptopp/sha.h>
#include <cryptopp/hex.h>

namespace twochains {
    class Block {
    public:
        static std::string CalculateHash(const std::string &input) {
            CryptoPP::SHA256 hash;

            byte digest[CryptoPP::SHA256::DIGESTSIZE];
            hash.CalculateDigest(digest, (const byte *) input.c_str(), input.length());

            std::string output;

            CryptoPP::HexEncoder encoder;
            encoder.Attach(new CryptoPP::StringSink(output));
            encoder.Put(digest, sizeof(digest));
            encoder.MessageEnd();

            return output;
        }

    protected:
    private:

    public:
    protected:
    private:
        int index_;
        std::string hash_;
        std::string previous_hash_;
        int timestamp_;
        std::string data_;
    };
}

#endif //INC_2CHAINS_BLOCK_H
