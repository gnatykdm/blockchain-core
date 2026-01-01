#include "CTransaction.h"

namespace blockchain::ctransaction {
    CTransaction::CTransaction(
        const std::string& id,
        const std::string& sender,
        const std::string& receiver,
        const Amount<u64>& amount,
        std::time_t timestamp
    ) : trId(id),
        tSenderAdress(sender),
        tReceiverAdress(receiver),
        tAmount(amount),
        tTimestamp(timestamp)
    {
    }
}