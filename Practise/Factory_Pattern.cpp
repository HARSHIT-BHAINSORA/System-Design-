#include<bits/stdc++.h>
using namespace std;


// Product

class Shape{
    public :
        virtual void draw() = 0; 
};

// Product Concerte class
class Circle : public Shape{
    public :
        void draw() override{
            cout<<"Draw Circle";
        }
};

class Rectangle : public Shape{
    public:
        void draw() override{
            cout<< "Draw Rectangle";
        }
};


// Factory

class ShapeFactory{
    public:
        virtual Shape* createShape() = 0;
};

// Factory Concerte class

class CircleShapeFactory : public ShapeFactory{
    public :
        Shape* createShape(){
            return new Circle();
        }
};

class RectangleShapeFactory : public ShapeFactory{
    public :
        Shape* createShape(){
            return new Rectangle();
        }
};


class Client{
    private :
        Shape* myShape;
    public :
        Client(ShapeFactory* factory){
            myShape = factory->createShape();
        }

        Shape* getShape(){
            return myShape;
        }
};


int main(){
    CircleShapeFactory* circleShapeFactory = new CircleShapeFactory();
    Client *CircleClient = new Client(circleShapeFactory);
    Shape* ClientShape = CircleClient->getShape();
    ClientShape->draw();   
}