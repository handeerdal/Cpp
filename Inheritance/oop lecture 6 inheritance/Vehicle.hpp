//
//  Vehicle.hpp
//  oop lecture 6 inheritance
//
//  Created by Hande Erdal on 13.12.2022.
//

#ifndef Vehicle_hpp
#define Vehicle_hpp


#include <iostream>
using namespace std;

class Vehicle{
private:
    string privinfo;
protected:
    string rejNum; //vehicleID
    int numOfWheels;
public:
    Vehicle(string rej="",int numoW=0); //böyle tanımlayınca hem default constructor oluyo hem de nrmal oluyo nası istersen
    ~Vehicle();
    void setRej(string);
    void setNum(int);
    int getNum();
    string getRej();
    void print();
};




#endif /* Vehicle_hpp */
