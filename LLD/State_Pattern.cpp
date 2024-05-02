#include <bits/stdc++.h>
using namespace std;


// Interface --> state --> we have to write down all the 
// operation that we can perform in Product

class VendingMachineState{
    public :
        virtual void handleRequest() = 0;
};

// On overiding we only override those how can be performed from theat 
// state for others throw exception 

class ReadyState : public VendingMachineState{
    public:
        void handleRequest() override{
            cout<< "Ready State - Please select the item" <<endl;
        }
};

class ProductSelectedState : public VendingMachineState{
    public :
        void handleRequest() override{
            cout<< "Product selected state : Processing for payment"<<endl;
        }
};

class PaymentState : public VendingMachineState{
    public:
        void handleRequest() override {
            cout<< "Payment State : Dispensing Product"<<endl; 
        }
};

class OutOfStock : public VendingMachineState{
    public :
        void handleRequest() override{
            cout<< "Out of Stock state : Please select another  Product"<<endl;
        }
};




// Product --> Vending Machine has a rel with Interface 

class VendingMachine
{
    private :
        VendingMachineState *state;

    public :
        void setState(VendingMachineState *state){
            this->state = state;
        }

        void request(){
            state->handleRequest();
        }
};



int main(){
    VendingMachine *machine = new VendingMachine();

    machine->setState(new ReadyState());
    machine->request();

    machine->setState(new ProductSelectedState());
    machine->request();

    machine->setState(new PaymentState());
    machine->request();

    machine->setState(new OutOfStock());
    machine->request();

    return 0;
}