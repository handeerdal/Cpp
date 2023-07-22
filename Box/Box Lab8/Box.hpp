//
//  Box.hpp
//  Box Lab8
/*
 Define the Box class with the following fields: a length, a width and a height being real values, and a string describing the contents of the box (empty by default). Define internal exception classes EmptyError and CapacityError inheriting from the logic_error class. Implement the following public methods of the class:
 • a constructor with the box dimensions as the parameters,
 • getCapacity – computing the capacity of the box,
 • setContents – setting a given string as the contents of the box (empty string makes
 the box empty), the second parameter is the volume of the contents – if it is too large
 the CapacityError should be thrown,
 • getContents – returning the contents of the box (or throwing the EmptyError
 exception if the box is empty),
 • isEmpty – checking whether the box is empty,
 • countAll – returning the number of boxes available (it should be a static method),
 • the shift operator (<<) – printing the sizes and the contents of the box.
 Define the ColouredBox and the WeightedBox classes derived from the Box class. Implement the necessary constructors with additional parameters (a color of the box and the maximal weight of the box contents respectively) and proper getters and setters. Define additional exception class WeightError for the contents weight overflowed. Override the shift operator (<<) in each derived class. Add other members which are necessary to implement the classes. Write a program which tests all the classes.
 */
//  Created by Hande Erdal on 18.12.2022.
//

#ifndef Box_hpp
#define Box_hpp

#include <iostream>
using namespace std;

class Box{
protected:
    int length;
    int width;
    int height;
    string content;
private:
    static int how_many_books;
public:
    Box(int length=0,int width=0,int height=0,string contents="");
    int getCapacity();
    friend ostream& operator<<(ostream &os,const Box &A);
    void setContents(int,int,int,string);
    string getContents();
    
    class EmptyError : public logic_error{
    public:
           EmptyError(string msg="Empty error occured"):logic_error(msg)
            { }
        };

    class CapacityError : public logic_error{
    public:
        CapacityError(string msg="Capacity error occured"): logic_error(msg)
        { }
    };
};


ostream& operator<<(ostream &os,const Box &A);



class ColouredBox : public Box{
protected:
    string colour;
public:
    ColouredBox(int length=0,int width=0,int height=0,string contents="",string colour="");
    string getcolour();
    void setcolour(string);
    friend ostream& operator<<(ostream &os,const ColouredBox &A);

};
ostream& operator<<(ostream &os,const ColouredBox &A);



#endif /* Box_hpp */
