//
//  vectors.hpp
//  vectors oop lab 4
/*
 1. Based on the class Point from Lab 3, define a class Vector describing a vector in two- dimensional space (https://mathinsight.org/vector_introduction), with thef fields being: two real numbers representing its coordinates, and a Point representing its tail. Implement the following public methods of the class:
 ◦ the default constructor creating the zero vector with the tail (0,0);
 ◦ the constructor with two parameters being Points (setting the tail to the first point, and
 computing vector coordinates);
 ◦ the methods getTail, setTail, getCoordinate1, getCoordinate2, setCoordinate1,
 setCoordinate2
 ◦ print method (printing the data of a vector)
 ◦ the method getMagnitude computig the magnitude of the vector
 ◦ operators + and – (addition and subtraction of vectors)
 ◦ operators * in two versions, corresponding respectively to multiplying a vector by a real
 number, and to multiplying a real number by a vector,
 ◦ a unary operator - computing the opposite vector
 ◦ == operator
 and a program which tests all the capabilities.
 */
//  Created by Hande Erdal on 13.11.2022.
//

#ifndef vectors_hpp
#define vectors_hpp

#include <stdio.h>
#include <iostream>
using namespace std;

class Point{
private:
    int x,y;
    friend class Vectors;
    /*int getTail();
    void setTail(int,int);
     bu iki metodu burda tanımladığım zaman friend yapsam bile vectors tan çağıramıyorum. nerede tanılmamam lazım?
    */
public:
    void printPoint();
    
};


class Vectors{
private:
    int coordinate1,coordinate2;
    Point tail;
public:
    Vectors();
    Vectors(int,int);
    void setTail(int,int);
    int getCoordinate1();
    int getCoordinate2();
    Point getTail();
    void setCoordinate1(int);
    void setCoordinate2(int);
    void printall();
    Vectors operator+(const Vectors &A);
    friend ostream& operator << (ostream& os, const Vectors &v);
    Vectors operator-();
    friend Vectors operator-(const Vectors &v,const Vectors &k);
};


ostream& operator << (ostream& os, const Vectors &v);
Vectors operator-(const Vectors &v,const Vectors &k);



#endif /* vectors_hpp */
