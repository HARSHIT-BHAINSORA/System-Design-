#include<bits/stdc++.h>
using namespace std;

unordered_map<string , unordered_set<string>>mp;

class Dish{
    public :
        string name;
        int price;
        unordered_set<string> ingredient;

        Dish(string name , int price)
        {
            this->name = name;
            this->price = price;
        }

        void AddIngredient(string i)
        {
            if(ingredient.find(i) == ingredient.end()){
                ingredient.insert(i);
                mp[i].insert(this->name);
            }
        }           
};

class Menu{
    public:
        unordered_set<Dish *> dishes;
    
        void addDish(Dish * d)
        {
            dishes.insert(d);
        }

        void removeDish(Dish *d)
        {
            if(dishes.find(d) != dishes.end()){
                dishes.erase(d);

                for(auto i : d->ingredient)
                    mp[i].erase(d->name);
            }
            else    
                cout<< "This dishes is Not in the menu!!!";
        }

        int calTotalBill(vector<Dish *>order)
        {
            int sum = 0;
            for(auto d : order)
            {
                if(dishes.find(d) != dishes.end())
                    sum += d->price;
                
            }
            return sum;
        }

        void AllDishes()
        {
            for(auto d : dishes)
                cout<< d->name << endl;
        }

        void dishWithIngredient(string i)
        {   
            if(mp.find(i) != mp.end())
            {
                for(auto d : mp[i])
                    cout<< d << endl;
            }
            else    
                cout<< "Ingredient Not in any dishes" ;
        }
};


int main(){

    Menu m;
    
    Dish *d1 = new Dish("Curry" , 120) , *d2 = new Dish("SahiPanner" , 230);
    
    d1->AddIngredient("Chilly");
    d2->AddIngredient("Salt");

    d2->AddIngredient("Panner");
    d2->AddIngredient("Chilly");

    m.addDish(d1);
    m.addDish(d2);

    m.removeDish(d1);
    m.dishWithIngredient("Chilly");
    m.AllDishes();
    
}