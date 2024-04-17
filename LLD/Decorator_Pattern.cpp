#include<bits/stdc++.h>
using namespace std;

// 1. Component -> abstract class -> do nothing function -> override kar hoga

class MilkShake{
    public:
        virtual string Server() = 0;
        virtual float price() = 0;
};

// 2. Concrete Class [No do nothing function] 
// this is the base class inherited the abstract class IS-A relationship

class BaseMilkShake : public MilkShake{
    public :
        string Server(){
            return "MilkShake ";
        }

        float price(){
            return 30;
        }
};


// Decorator 
// 1. IS-A --> yai kud bhi milkshake hai [Mongo Milkshake] -> hai milkshake hi
// 2. HAS-A --> isske pass base milkshake hai decoration ke liyai tab hi ref variable hai component ka

class MilkShakeDecorator : public MilkShake
{
    protected :
        MilkShake *m_MilkShake;
    
    public :
        MilkShakeDecorator(MilkShake *baseMilkShake){
            m_MilkShake = baseMilkShake;
        }

        string Serve(){
            return m_MilkShake->Server();
        }

        float price(){
            return m_MilkShake->price();
        }
};

// Decorator Concerte class
class MangoMilkShake : public MilkShakeDecorator
{
    public :
        MangoMilkShake(MilkShake *baseMilkShake) : MilkShakeDecorator(baseMilkShake){}

    string Server(){
        return m_MilkShake->Server() + "Decorated with Mango";
    }

    float price(){
        return m_MilkShake->price() + 40;
    }
};  

class VanillaMilkShake : public MilkShakeDecorator
{
    public :
        VanillaMilkShake(MilkShake *baseMilkShake) : MilkShakeDecorator(baseMilkShake){}

    string Server(){
        return m_MilkShake->Server() + "Decorated with Vanilla";
    }

    float price(){
        return m_MilkShake->price() + 50;
    }
};

int main(){
    MilkShake *baseMilkShake = new BaseMilkShake();
    cout<< baseMilkShake->Server() << endl;
    cout<< baseMilkShake->price() << endl;
    
    
    MilkShake *decoratedMilkShake1 = new MangoMilkShake(baseMilkShake);

    cout<< "Mango Decoration" << endl;
    cout<< decoratedMilkShake1->Server() << endl;
    cout<< decoratedMilkShake1->price() << endl;

    MilkShake* decoratedMilkShake2 = new VanillaMilkShake(decoratedMilkShake1);

    cout<< "Vanilla Decoration" <<endl;
    cout<< decoratedMilkShake2->Server() << endl;
    cout<< decoratedMilkShake2->price() << endl;

    delete baseMilkShake;
    delete decoratedMilkShake1;
    delete decoratedMilkShake2;

    return 0;
}

