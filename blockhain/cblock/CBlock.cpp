#include "CBlock.h";

namespace blockchain::cblock
{
	CBlock::CBlock(i64 index, const std::string& previousHash)
		: bIndex(index), bPreviousHash(previousHash) {
		bTimestamp = std::time(nullptr);
		nNonce = 0;
		calculateHash();
	}
} // namespace blockchain::cblock