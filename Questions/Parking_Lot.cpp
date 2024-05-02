Design a Parking lot 

-> Requirement gathering

1. Parking huge - 10K [vehicles]
2. 4 Terminals [Entrance and Exist]
3. Assign ticket at entrance
4. Parking spot should the neartest
5. system charge the fair hourly
6. Parking slots [cars , turcks , Motercycle]
7. Pay cash

Models / Actors
1. Parking lot
2. terminal --> entrance or exit
3. Parking spot
4. Ticket 

Note --> Not assuming vehicle as a model reason --> parking slot --> genrating the tickets at entrance respetively

// abstract class
1. 
class ParkingSpot
{};

class car : public ParkingSpot{}
class Motorcycle : public ParkingSpot{}

This design helped me to scale up the application --> let in future there may another kind spot we just need to inherited the 
parkingspot class

class Tuck : public ParkingSpot{}

2. 
class Terminal{
}

class Entry : public Terminal{
    void getTicket(ParkingSpot type){}
}

class Exist : public Terminal{
    void AcceptTicket(Ticket t){} 
}

3. Ticket

class Ticket{
    int id;
    int parkingspotId;
    int parkingspot type;
    int issueTime;
}


Staterg Design Pattern

class ParkingAssignment{
    void getParkingspot(Terminal t){}
    void releaseParkingspot(Parkingspot)
}

class ParkingSpotNearMe:public ParkingAssignment{
    // min heap --> shortest dis from the entrance to assign the ticket
}

4. Payment

class Payment{
    amount
}

class cash : public payment{

}

class scanner : public payment{

}

5. Trffic Calculate
 func cal (pirce , timespend)

