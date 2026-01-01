#include "CBlock.h"

#include <sstream>
#include <iomanip>
#include <openssl/sha.h>
#include <stdexcept>

namespace blockchain::cblock {

CBlock::CBlock(i64 index, const std::string& previousHash)
    : bIndex(index),
      bPreviousHash(previousHash),
      bCurrentHash(""),
      bTimestamp(std::time(nullptr)),
      nNonce(0)
{
    bCurrentHash = calculateHash();
}

std::string CBlock::sha256(const std::string& input) {
    unsigned char hash[SHA256_DIGEST_LENGTH];

    SHA256(
        reinterpret_cast<const unsigned char*>(input.data()),
        input.size(),
        hash
    );

    std::stringstream ss;
    for (int i = 0; i < SHA256_DIGEST_LENGTH; ++i) {
        ss << std::hex
           << std::setw(2)
           << std::setfill('0')
           << static_cast<int>(hash[i]);
    }

    return ss.str();
}

std::string CBlock::calculateHash() const {
    std::stringstream ss;

    ss << bIndex
       << bPreviousHash
       << bTimestamp
       << nNonce;

    for (const auto& tx : bTransactions) {
        ss << tx.toString();
    }

    return sha256(ss.str());
}

void CBlock::blockMining(i32 difficulty) {
    if (difficulty < 0) {
        throw std::invalid_argument("difficulty must be >= 0");
    }

    std::string target(difficulty, '0');

    do {
        ++nNonce;
        bCurrentHash = calculateHash();
    } while (bCurrentHash.substr(0, difficulty) != target);
}

void CBlock::addTransaction(const ctransaction::CTransaction& transaction) {
    bTransactions.push_back(transaction);
}

} // namespace blockchain::cblock
