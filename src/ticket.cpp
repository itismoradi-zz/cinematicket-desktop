#include "../include/ticket.hpp"

void Ticket::setPrice(int tPrice)
{
    price = tPrice;
}
void Ticket::setSeatNumber(int seatNum)
{
    seatNumber = seatNum;
}
void Ticket::setTicketId(int ticketID)
{
    ticketId = ticketID;
}
bool Ticket::setIsReturned(bool isRet)
{
    if (ticketId == 0)
    {
        return false;
    }
    else
    {
        isReturned = isRet;
        return true;
    }
}
int Ticket::getPrice()
{
    return price;
}
int Ticket::getSeatNumber()
{
    return seatNumber;
}
int Ticket::getTicketId()
{
    return ticketId;
}
bool Ticket::getIsReturned()
{
    return isReturned;
}