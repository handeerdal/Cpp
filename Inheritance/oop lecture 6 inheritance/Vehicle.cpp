//
//  Vehicle.cpp
//  oop lecture 6 inheritance
//
//  Created by Hande Erdal on 13.12.2022.
//
#include "Vehicle.hpp"
#include <iostream>
using namespace std;


Vehicle::Vehicle(string rej,int numoW){
    rejNum=rej;
    numOfWheels=numoW;
}

Vehicle::~Vehicle(){
    cout<<rejNum<<"number is deleted"<<endl;
}

void Vehicle:: setRej(string rejNum ){
    
    this->rejNum= rejNum;
}
void Vehicle::setNum(int num){
    
    numOfWheels=num;
    
}

int Vehicle::getNum(){
    return numOfWheels;
}

string Vehicle:: getRej(){
    return rejNum;
}

void Vehicle::print(){
    cout<<rejNum<<" registration number of "<<numOfWheels<< " wheel created"<<endl;

}
