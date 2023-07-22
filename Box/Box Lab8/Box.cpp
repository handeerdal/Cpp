//
//  Box.cpp
//  Box Lab8

//  Created by Hande Erdal on 18.12.2022.
//

#include "Box.hpp"
#include <iostream>
using namespace std;

Box::Box(int length,int width,int height,string contents){
    if(length==0||width==0||height==0)
        throw logic_error("wrong dimensions");
    this->length=length;
    this->width=width;
    this->height=height;
    content=contents;
}

int Box::getCapacity(){
    return width*length*height;
}

ostream& operator<<(ostream &os,const Box &A){
    cout<<"----------"<<endl;
    cout<<A.length<<"x"<<A.width<<"x"<<A.height<<endl;
    cout<<A.content<<endl;
    cout<<"----------"<<endl;
    return  os;
    
}
void Box:: setContents(int newh,int newW,int newL,string newC){
    if(newW*newL*newh>length*width*height)
        throw CapacityError();
    else{
        content=newC;
    }
    
}

string Box:: getContents(){
    if(content==" ")
        throw EmptyError();
    else
        return content;
}

ColouredBox::ColouredBox(int length,int width,int height,string contents,string colour):Box(length,width,height,contents){
    this->colour=colour;
}

string ColouredBox::getcolour(){
    return colour;
}

void ColouredBox::setcolour(string colour){
    this->colour=colour;
}

ostream& operator<<(ostream &os,const ColouredBox &A){
    cout<<"----------"<<endl;
    cout<<A.length<<"x"<<A.width<<"x"<<A.height<<endl;
    cout<<A.content<<endl;
    cout<<A.colour<<endl;
    cout<<"----------"<<endl;
    return  os;
}
