#include<bits/stdc++.h>
using namespace std;

// 1. Product 

class Vehicle{
    public :
        virtual void printVehicle() = 0;
};

// Product Concerte class 

class TwoWheeler : public Vehicle{
    public :
        void printVehicle(){
            cout << "Here is your Two Wheeler Vehicle" <<endl;
        }
};

class FourWheeler : public Vehicle{
    public :
        void printVehicle(){
            cout<<"Here is  your Four Wheeler Vehicle" << endl;
        }
};

// 2. Factory 

class VehicleFactory{
    public :
        virtual Vehicle* createVehicle() = 0;
};

// Factory Concerte Class -> Is a with VehicleFactory and Has a with respected Product class

class TwoWheelerFactory : public VehicleFactory{
    public :
        Vehicle* createVehicle(){
            return new TwoWheeler();
        }
};

class FourWheelerFactory : public VehicleFactory{
    public :
        Vehicle* createVehicle(){
            return new FourWheeler();
        }
};


// Client 
class Client{
    private :
        Vehicle* myVehicle;

    public :
        Client(VehicleFactory *factory)
        {
            myVehicle = factory->createVehicle();
        }

        Vehicle* getVehicle(){
            return myVehicle;
        }
};


int main(){

    TwoWheelerFactory* twoWheelerFactory = new TwoWheelerFactory();
    Client * ClientTwoWheeler = new Client(twoWheelerFactory);
    Vehicle* ClientVehicle = ClientTwoWheeler->getVehicle();
    ClientVehicle->printVehicle();

    FourWheelerFactory* fourWheelerFactory = new FourWheelerFactory();
    Client * ClientFourWheeler = new Client(fourWheelerFactory);
    Vehicle* ClientVehicle1 = ClientFourWheeler->getVehicle();
    ClientVehicle1->printVehicle();

    return 0;
}