/*
 Define the class ConsumerOrder representing a list of dishes a customer orders in a restaurant. The class should contain the following fields: a customer name, two arrays/lists of the same size (empty by default) storing respectively the names of dishes (strings) and their prices (real numbers), and a unique sequential number (ID) of the order (a positive integer). Implement the following public methods of the class :
 • the default constructor with a string parameter representing a customer name,
 • the copy-constructor and the assignment operator,
 • a destructor, which (in addition to other actions if necessary) prints the sequential number of
 the order being destroyed,
 • setCustomer, getCustomer and getID methods,
 • addDish method, with two parameters representing a dish name (a string) and its price (a
 real value), adding this dish to the order as the last position,
 • removeDish method, with a dish name as a parameter, removing from the order all the
 occurrences of this dish, together with their costs (or throwing an error if the dish is not in
 the order),
 • length – returning the number of elements in the order,
 • getOrderCount – returning the total number of customer’s orders made so far
 • the operator >, where by a “greater” order we mean a more expensive one,
 • the indexing operator ([]) – returning the price of the dish on the position given as the
 parameter (1 means the first dish, 2 – the second dish etc; an error should be thrown if the
 value given is greater than the length of the order),
 • the shift operator (<<) – printing the number of the order, the customer name, the numbered
 list of all the ordered dishes and their costs, and the total cost of the order.
 */
//  costumer.cpp
//  example1 oop
/*
 string name;
 string* data1; //name
 string* data2; //prices
 int size;
 int id;
 static int how_many_order;
 */
//  Created by Hande Erdal on 15.11.2022.
//

#include "costumer.hpp"
#include <iostream>

ConsumerOrder::ConsumerOrder(string name){
    this->name=name;
    size=0;
    how_many_order_now=0;
    id=how_many_people;   ///-------------------------------UNUTMAAAAAA
    how_many_people++;
    data1=nullptr;   ///-------------------------------UNUTMAAAAAA
    data2=nullptr;  ///-------------------------------UNUTMAAAAA
}

ConsumerOrder::ConsumerOrder(const ConsumerOrder &A){
    name=A.name;             /// NAME İN ONUNE A KOYMAYI UNUTMA
    size=A.size;
    id=A.id;
    for(int i=0;i<size;i++)
    {
        data1[i]=A.data1[i];
        data2[i]=A.data2[i];
    }
}

ConsumerOrder::~ConsumerOrder(){
    delete [] data1;
    delete [] data2;
    cout<<"ID Number is "<< id << "destroyed";
}

void ConsumerOrder:: setCostumer(string name){
    this->name=name;
    cout<<"name is changed";
    
}
string ConsumerOrder::getCustomer(){
    return name;
}

int ConsumerOrder::getID(){
    return id;
}

void ConsumerOrder::addDish(string name, double price){
    int i=0;
    string *temp1;
    double *temp2;
    temp1= new string[size+1];
    temp2= new double [size+1];
    for(i=0;i<size;i++){
        temp1[i]=data1[i];
        temp2[i]=data2[i];
    }
    
    delete [] data1;
    delete [] data2;
    
    data1=temp1;
    data2=temp2;
    data1[i]=name;
    data2[i]=price;
    how_many_order_now++;
    size=how_many_order_now;
}

int ConsumerOrder::length(){
    return how_many_order_now;
}


ostream& operator<<(ostream &os,const ConsumerOrder &A){
    
    os<<"ID,Name,Orders\n"<<A.id<<" "<<A.name<<endl;
    for(int i=0;i<A.size;i++){
        cout<<"Product: "<<A.data1[i]<<" "<<"Price: "<<A.data2[i]<<endl;
    }
  
    return os;
    
}

void ConsumerOrder:: removeDish(string name_){
    int where=0;
    int temp=0;
    string* datatemp1=0;
    double* datatemp2=0;
    datatemp1=new string [size-1];
    datatemp2=new double [size-1];
    for(int i=0;i<size;i++){
        if(data1[i]==name_)
            temp=1;
    }
    if(temp==1){
        
        for(int i=0;i<size;i++){
            if(data1[i]!=name_){
                datatemp1[where]=data1[i];
                datatemp2[where]=data2[i];
                where++;
                
            }
            
        }
        size=where;
        delete [] data1;
        delete [] data2;
        data1=datatemp1;
        data2=datatemp2;
    }
    else
        throw runtime_error("name not found\n");

   
}

ConsumerOrder& ConsumerOrder ::operator=(const ConsumerOrder &A){//YANINDAKİ AMPERSANTI UNUTMA BU ÖNEMLİ AŞKOM
    if(this!=&A){
        name=A.name;             /// NAME İN ONUNE A KOYMAYI UNUTMA
        size=A.size;
        id=A.id;
        for(int i=0;i<size;i++)
        {
            data1[i]=A.data1[i];
            data2[i]=A.data2[i];
        }
        
        
        
    }
    return *this; //* YERİ ÖNEMLİ
    
}



/*bool operator >(const ConsumerOrder &A,const ConsumerOrder &B){ //---------
 
}*/

bool operator ==(const ConsumerOrder &A,const ConsumerOrder &B){
    
    if(A.size==B.size){
        for(int i=0;i<A.size;i++){
            if(A.data1[i]!=B.data1[i] || A.data2[i]== B.data2[i]){
                return 0;
            }
        }
        return 1;
    }
    else
        return 0;
    
}




 int ConsumerOrder:: getOrderCount(){
    return how_many_people;
}



/*ConsumerOrder ConsumerOrder:: operator[](int a){
    
}
*/

/*ConsumerOrder ConsumerOrder::operator[](const ConsumerOrder &A){
}
*/
