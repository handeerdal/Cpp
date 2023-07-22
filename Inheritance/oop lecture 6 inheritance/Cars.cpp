//
//  Cars.cpp
//  oop lecture 6 inheritance
//
//  Created by Hande Erdal on 13.12.2022.
//

#include "Cars.hpp"
#include <iostream>
using namespace std;




Car::Car(string rejNum,int numOfWheels,string br,float c): Vehicle(rejNum,numOfWheels),brand(br){
    
    capacity=c;
    //brand(br) örneğin dışta yazan Cars da tanımlı olan asıl ismi gösteriyo br de fonksiyona gelen parametre
    
    
}

void Car::print(){
    cout<<"-----------"<<endl;
    cout<<brand<<" is brand"<<endl<<capacity<<" is capacity"<<endl<<rejNum<<" registiration number"<<endl<<numOfWheels<<" is num of wheels"<<endl;
    cout<<"-----------"<<endl;

}

Car::~Car(){
    cout<<brand<<" and wheels number is "<<numOfWheels<<" deleted"<<endl;
}

Truck::Truck(string rejNum,int numOfWheels,string brand,float capacity,string mtr): Car(rejNum,numOfWheels,brand,capacity),motor(mtr){
    
}

