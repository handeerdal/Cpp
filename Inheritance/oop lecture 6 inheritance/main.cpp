//
//  main.cpp
//  oop lecture 6 inheritance
//
//  Created by Hande Erdal on 12.12.2022.
//

#include <iostream>

#include "Cars.hpp"
#include "Vehicle.hpp" //gerek yok

using namespace std;


int main(int argc, const char * argv[]) {
    Vehicle A("456",2);
    A.print();
    Car B("12345",4,"Asetta Corsa",5.9);
    B.print();
    Truck C("345678",4,"Araba ismi bilmiyom",5,"cok iyi");
    C.print();
}
