#ifndef __CTRANSACTION_H__
#define __CTRANSACTION_H__

#include <string>
#include <ctime>

#include "Types.h"
#include "Amount.h"

namespace blockchain::ctransaction {
    class CTransaction {
    private:
		const std::string trId;                 // Transaction ID
		const std::string tSenderAdress;        // Transaction Sender Address
		const std::string tReceiverAdress;      // Transaction Receiver Address
		const Amount<u64> tAmount;              // Transaction Amount
		const std::time_t tTimestamp;           // Transaction Timestamp

    public:
        explicit CTransaction(
            const std::string& id,
            const std::string& sender,
            const std::string& receiver,
            const Amount<u64>& amount,
            std::time_t timestamp
        );

        [[nodiscard]] std::string getTrId() const { return trId; }
        [[nodiscard]] std::string getTSenderAdress() const { return tSenderAdress; }
        [[nodiscard]] std::string getTReceiverAdress() const { return tReceiverAdress; }
        [[nodiscard]] Amount<u64> getTAmount() const { return tAmount; }
        [[nodiscard]] std::time_t getTTimestamp() const { return tTimestamp; }
    };
}

#endif // __CTRANSACTION_H__