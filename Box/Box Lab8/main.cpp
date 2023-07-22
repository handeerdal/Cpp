//
//  main.cpp
//  Box Lab8
//
//  Created by Hande Erdal on 18.12.2022.
//

#include <iostream>
#include "Box.hpp"
using namespace std;

int main(int argc, const char * argv[]) {
    Box A(2,2,3,"Book");
    cout<<A;
    cout<<"A capacity is "<<A.getCapacity()<<endl;
    A.setContents(2, 2, 1, "Milk");
    //A.setContents(2, 2, 1, " ");
    cout<<A.getContents();
    cout<<endl;
    ColouredBox B(2,2,3,"Book","Blue");
    cout<<B;
}
