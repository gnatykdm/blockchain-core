#ifndef __CBLOCK_H__
#define __CBLOCK_H__

#include <string>
#include <ctime>
#include <vector>

#include "Types.h"
#include "blockchain/ctransaction/CTransaction.h"

namespace blockchain::cblock {

class CBlock {
private:
    const i64 bIndex;
    const std::string bPreviousHash;
    std::string bCurrentHash;
    const std::time_t bTimestamp;

    std::vector<ctransaction::CTransaction> bTransactions;
    i32 nNonce;

    std::string calculateHash() const;
    static std::string sha256(const std::string& input);

public:
    explicit CBlock(i64 index, const std::string& previousHash);

    void blockMining(i32 difficulty);
    void addTransaction(const ctransaction::CTransaction& transaction);

    i32 getNonce() const { return nNonce; }
    i64 getIndex() const { return bIndex; }
    size_t getTransactionCount() const { return bTransactions.size(); }
    std::time_t getTimestamp() const { return bTimestamp; }
};

} // namespace blockchain::cblock

#endif
