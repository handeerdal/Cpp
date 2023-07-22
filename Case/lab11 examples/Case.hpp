//
//  Case.hpp
//  lab11 examples
/*
 Define an abstract class Case with a text label, a numerical colour, a method providing the number of Cases and the pure virtual method getCapacity computing the capacity (volume) of a case.
 Define the following classes inherited from the Case:
 • BrickCasebeingacuboidwithalength,awidthandaheight,
 • TubeCasebeingacylinderwithabaseradiusandaheight,
 • PrismCasebeingaregulartriangularprismwithabasesidelengthandaheight.
 Override, for each of the above classes, the virtual method getCapacity, making it to return the volume of a case of the given class. Implement all the constructors, destructors, getters, setters and exceptions which make the functionality of the classes complete, and all the other methods and exceptions necessary to run the code provided below.
 Define the class Repository with a description, a total capacity and a dynamic list of the cases stored in the repository. Implement the following public methods of the class:
 • a one enabling to add a new case of an arbitrary type to the repository (with the control of the total capacity of the repository, CapacityError should be thrown if the total capacity could be exceeded),
 • a one enabling to remove the case (by its label) from the repository (throwing the NameError exception if it doesn't exist),
 • a one enabling to remove all the cases from the repository,
 • a method returning the summary volume of all the cases stored in the repository.
 Overload the indexing operator ([]) for the Repository to have a direct access to the item on the particular position in the list (throwing the IndexError exception if it doesn't exist). Overload the shift-left operator (<<) printing the data of the repository and the details of all the cases stored. Add all the other members which are necessary to make the functionality of the class complete or are required to run the code below.
 Write a program which tests all the class capabilities, in particular the following code should be enabled:
 */
//  Created by Hande Erdal on 7.01.2023.
//

#ifndef Case_hpp
#define Case_hpp
#include <cmath>
#include <stdio.h>
#include <iostream>
using namespace std;


//---------------------------CASE CLASSS----------------------
class Case{
private:
    static int how_many_cases;
protected:
    string text;
    string color;
public:
    Case(string a="",string b=""){
        text=a;
        color=b;
        how_many_cases++;
    }
    virtual ~Case(){
        cout<<text<<" cleaned"<<endl;
    }
    virtual float getCapacity()=0;
    static int count(){
        return how_many_cases;
    }
    string gettext(){
        return text;
    }
    string getcolor(){
        return color;
    }
    void settext(string a){
         text=a;
    }
    void setcolor(string a){
         color=a;
    }
    
};

//---------------------------BrickCase CLASSS----------------------

class BrickCase:public Case{
protected:
    int height;
    int width;
    int length;
public:
    BrickCase(string text="",string color="",int h=0,int w=0,int l=0):Case(text,color){
        height=h;
        width=w;
        length=l;
    }
    ~BrickCase(){
        cout<<"BrickCase deleted"<<endl;
    }
    int geth(){
        return height;
    }
    int getw(){
        return width;
    }
    int getl(){
        return length;
    }
    void seth(int h){
         height=h;
    }
    void setw(int h){
         width=h;
    }
    void setl(int h){
         length=h;
    }
    
    float getCapacity(){
        return height*width*length;
    }
};
//---------------------------TubeCase CLASSS----------------------


class TubeCase:public Case{
protected:
    int height;
    int radius;
public:
    TubeCase(string text="",string color="",int h=0,int r=0):Case(text,color){
        height=h;
        radius=r;
    }
    ~TubeCase(){
        cout<<"TubeCase deleted"<<endl;
        
    }
    int geth(){
        return height;
    }
    int getr(){
        return radius;
    }
    void seth(int h){
         height=h;
    }
    void setr(int r){
         radius=r;
    }

    float getCapacity(){
        return M_PI*radius*radius*height;
    }
};



//---------------------------PrismCase CLASSS----------------------

class PrismCase:public Case{
protected:
    int height;
    int length;
public:
    PrismCase(string text="",string color="",int h=0,int l=0):Case(text,color){
        height=h;
        length=l;
    }
    ~PrismCase(){
        cout<<"PrismCase deleted"<<endl;
    }
    int geth(){
        return height;
    }

    int getl(){
        return length;
    }
    void seth(int h){
         height=h;
    }

    void setl(int h){
         length=h;
    }
    
    float getCapacity(){
        return height*length*0.5;
    }
};
#endif /* Case_hpp */
