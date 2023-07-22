//
//  vectors.cpp
//  vectors oop lab 4
//
//  Created by Hande Erdal on 13.11.2022.
//

#include "vectors.hpp"

#include <iostream>
#include <math.h>
using namespace std;

// CONSTRUCTORS
Vectors::Vectors(){
    setTail(0, 0);
    setCoordinate1(0);
    setCoordinate2(0);
}
Vectors::Vectors(int coor1,int coor2){
    setTail(0, 0);
    setCoordinate1(coor1);
    setCoordinate2(coor2);
}


// GETTERS AND SETTERS
void Vectors::setTail(int x,int y){
    tail.x=x;
    tail.y=y;
}

int Vectors::getCoordinate1(){
    return coordinate1;
}

int Vectors::getCoordinate2(){
    return coordinate2;
}

void Vectors::setCoordinate1(int coor1){
    coordinate1=coor1;
}
void Vectors::setCoordinate2(int coor2){
    coordinate2=coor2;
}
Point Vectors::getTail(){
    return tail;
}


//PRİNT FUNCTİON
void Vectors::printall(){
    cout<<"coordinates are ("<<coordinate1<<","<<coordinate2<<")"<<endl;
    cout<<"tail is("<<tail.x<<","<<tail.y<<")"<<endl;
}


//OPERATORS

Vectors Vectors::operator+(const Vectors&A){
    Vectors sum;
    sum.setCoordinate1(A.coordinate1);
    sum.setCoordinate2(A.coordinate2);
    sum.setTail(A.tail.x+tail.x, A.tail.y+tail.y);
 // FRİEND YAPINCA BU ŞEKİL ÇALIŞMIYO   sum.setTail(A.tailgettail.+tail.x, A.tail.y+tail.y);
    return sum;

}
ostream& operator << (ostream& os, const Vectors &v)
{
    os << "("<< v.coordinate1<<","<<v.coordinate2<<")"<<endl;
   return os;
}

Vectors Vectors::operator-(){
    Vectors negative;
    negative.setCoordinate1(coordinate1*-1);
    negative.setCoordinate2(coordinate2*-1);
    return negative;
}

Vectors operator-(const Vectors &v,const Vectors &k){
    Vectors substraction;
    substraction.setCoordinate1(k.coordinate1-v.coordinate1);
    substraction.setCoordinate2(k.coordinate2-v.coordinate2);
    return substraction;
}

void Point::printPoint(){
    cout<<x<<" "<<y<<endl;
}
