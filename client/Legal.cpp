#include "Legal.h"
#include "../bank/Bank.h"


void Legal::makeTransferToAnotherBank(Bank *bank_from, Bank *bank_to, Client *receiver, float sum)
{
    bank_from->makeDepositTransferForLegalEntity(bank_to, this, receiver, sum);
}
