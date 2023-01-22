#include "Card.h"


Card::Card(const std::string& name): m_name(name) {}


void Card::virtualPrintAddedDetails(std::ostream& os) const {}


std::ostream& operator<<(std::ostream& os, const Card& card)
{
    printCardDetails(os, card.m_name);
    card.virtualPrintAddedDetails(os);
    printEndOfCardDetails(os);
    return os;
}



