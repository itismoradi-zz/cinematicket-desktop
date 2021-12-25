#ifndef TICKET_H
#define TICKET_H

class Ticket
{
public:
    void setPrice(int);
    void setSeatNumber(int);
    void setTicketId(int);
    bool setIsReturned(bool);   // in case user wants to return an unpurchased ticket, it will return false

    int getPrice();
    int getSeatNumber();
    int getTicketId();
    bool getIsReturned();

protected:
    int price;
    int seatNumber;
    int ticketId = 0;   // if user bought a ticket, id will change else it will remain zero
    bool isReturned = false;    // if user bought a ticket and wants to return it, value of isReturned will be true
};

#endif // TICKET_H