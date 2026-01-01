#ifndef __CBLOCK_H__
#define __CBLOCK_H__

#include <string>
#include <ctime>
#include <vector>

#include "Types.h"
#include "CTransaction.h"

namespace blockchain::cblock {
	class CBlock {
	private:
		const i32 bIndex;										// Position of the block in the blockchain
		const std::string bPreviousHash;						// Hash of the previous block
		const std::string bCurrentHash;							// Hash of the current block
		const std::time_t bTimestamp;							// Time when the block was created

		std::vector<ctransaction::CTransaction> bTransactions;	// List of transactions in the block
		i32 nNonce;											    // Nonce used for mining

		void calculateHash();									// Method to calculate the block's hash
	public:
		explicit CBlock(i64 index, const std::string& previousHash, const std::string& currentHash, std::time_t timestamp);

		void blockMining(i32 difficulty);
		void addTransaction(const ctransaction::CTransaction& transaction);

		std::string getBlockInfo() const;

		i32 getNonce() const { return nNonde; };
		i32 getIndex() const { return bIndex; };

		i32 getTransactionCount() const { return bTransactions.size(); };
		std::time_t getTimestamp() const { return bTimestamp; };
	};
}

#endif // __CBLOCK_H__