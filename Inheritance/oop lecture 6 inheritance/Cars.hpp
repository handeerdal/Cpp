//
//  Cars.hpp
//  oop lecture 6 inheritance
//
//  Created by Hande Erdal on 13.12.2022.
//

#ifndef Cars_hpp
#define Cars_hpp
#include <iostream>
#include "Vehicle.hpp"
using namespace std;

class Car: public Vehicle {
protected:
    string brand;
    float capacity;
public:
    Car(string rejNum="",int numOfWheels=0,string br="",float c=0);
    ~Car();
    void print();
};

class Truck: public Car{
protected:
    string motor;
public:
    Truck(string rejNum="",int numOfWheels=0,string brand="",float capacity=0,string mtr="");
};

#endif /* Cars_hpp */

