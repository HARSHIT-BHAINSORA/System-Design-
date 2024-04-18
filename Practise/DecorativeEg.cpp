// Problem --> Pizza baane hai different Topping ke 

#include<bits/stdc++.h>
using namespace std;

// 1. Component abstract class 

class Pizza{
    public :
        virtual string Server() = 0;
        virtual float Price () = 0;
};

// 2. Concerte Class 
class BasePizza : public Pizza{
    public :
        string Server(){
            return "Base Pizza ";
        }

        float Price(){
            return 90;
        }
};

// Decorator hold IS-A [inheritance] and HAS-A [Composition] relationship
class ToppingDecorator : public Pizza{
    protected :
        Pizza *p_Pizza;
    public :
        // constructor injection
        ToppingDecorator(Pizza *basePizza){
            p_Pizza = basePizza;
        }

        string Server(){
            return p_Pizza->Server();
        }

        float Price(){
            return p_Pizza->Price();
        }
};

// Concerte Class

class TomatoTopping : public ToppingDecorator{
    public :
        TomatoTopping(Pizza *basePizza) : ToppingDecorator(basePizza){}

        string Server(){
            return p_Pizza->Server() + "with the Topping of Toamato ";
        }

        float Price(){
            return p_Pizza->Price() + 30;
        }
};


class ExtraCheezTopping : public ToppingDecorator{
    public:
        ExtraCheezTopping(Pizza *basePizza) : ToppingDecorator(basePizza){}
        
        string Server(){
            return p_Pizza->Server() +  "with the topping of Extra cheez";
        }

        float Price(){
            return p_Pizza->Price() + 20;
        }
};


int main(){

    Pizza *basePizza = new BasePizza();
    cout<< basePizza->Server() << endl;
    cout<< basePizza->Price() << endl;

    Pizza *tomatoTopping = new TomatoTopping(basePizza);
    cout<< tomatoTopping->Server() << endl;
    cout<< tomatoTopping->Price() << endl;

    Pizza *extraCheezTopping = new ExtraCheezTopping(tomatoTopping);
    cout<< extraCheezTopping->Server() << endl;
    cout<< extraCheezTopping->Price() << endl;

    return 0;
}