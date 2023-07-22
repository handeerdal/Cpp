//
//  main.cpp
//  vectors oop lab 4
//
//  Created by Hande Erdal on 13.11.2022.
//

#include <iostream>
#include "vectors.hpp"
using namespace std;

int main(int argc, const char * argv[]) {
    Vectors A;
    Vectors B(5,6);
    
    A.printall();
    B.printall();
    Vectors summary;
    Vectors substraction;
    B.setTail(3, 3);
    Point t=B.getTail();
    t.printPoint();
    A.setCoordinate1(3);
    A.setCoordinate2(5);
    //summary=A+B;
    summary=A.operator+(B);
    summary.printall();
    cout<<"yaptık galiba"<<endl;
    cout<<"A-B"<<endl;
    substraction=B-A;
    cout<<substraction;
    cout<<summary;
    Vectors negativeA;
    negativeA=B.operator-();
    cout<<negativeA;
    return 0;
}
