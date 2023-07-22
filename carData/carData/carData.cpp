//
//  carData.cpp
//  carData
//
//  Created by Hande Erdal on 20.11.2022.
//

#include "carData.hpp"
#include <iostream>
#include <string>
using namespace std;

CarData::CarData(string registirationnumber,string brand){
    this->brand=brand;
    this->registrationnumber=registirationnumber;
    customer=nullptr;
    period=nullptr;
    sizeofcars=0;
    total=0;
}

CarData::~CarData(){
    
    delete [] period;
    delete [] customer;
    cout<<registrationnumber <<"and"<< brand<< " deleted"<<endl;

}

CarData::CarData(const CarData &A){
    total=0;
    registrationnumber=A.registrationnumber;
    brand=A.brand;
    sizeofcars=A.sizeofcars;
    customer= new string [sizeofcars];
    period= new int [sizeofcars];
    for(int i=0;i<sizeofcars;i++){
        customer[i]=A.customer[i];
        period[i]=A.period[i];
    }
}


CarData &CarData::operator=(const CarData &A){
    if(this!=&A){
    registrationnumber=A.registrationnumber;
    brand=A.brand;
    sizeofcars=A.sizeofcars;
    customer= new string [sizeofcars];
    period= new int [sizeofcars];
    for(int i=0;i<sizeofcars;i++){
        customer[i]=A.customer[i];
        period[i]=A.period[i];
    }
    }
    else
        throw runtime_error("this same address with A");
    return *this;

}

void CarData::setRegistrationNumber(string number){
this->registrationnumber=number;
}

string CarData::getRegistrationNumber(){
    return registrationnumber;
}
string CarData::getBrand(){
    return brand;
}

ostream& operator<<(ostream &os,const CarData &A){
    os<<"Brand is "<<A.brand<<endl;
    os<<"Register number is "<<A.registrationnumber<<endl;
    os<<"Customers and Period "<<endl;
    for(int i=0;i<A.sizeofcars;i++)
    {
        os<<A.customer[i]<<" ";
        os<<A.period[i]<<endl;
    }
    os<<"Total time is : "<<A.total;

    return os;
}

int CarData::getRentalsCount(){
    return how_much_car_rented;
}

void CarData::addRental(string customer,int period){
    string *tempname=new string [sizeofcars+1];
    int *tempperiod=new int [sizeofcars+1];
    for(int i=0;i<sizeofcars;i++)
    {
        tempname[i]=this->customer[i];
        tempperiod[i]=this->period[i];
        total+=this->period[i];
    }
    tempname[sizeofcars]=customer;
    tempperiod[sizeofcars]=period;
    total+=period;
    
    sizeofcars++;
    how_much_car_rented++;
    delete [] this->customer;
    delete [] this->period;
    

    this->customer=tempname;
    this->period= tempperiod;

    
}


double CarData::averageTime(){
    double total1 = 0.0;
    for(int i=0;i<sizeofcars;i++){
        total1+=period[i];
    }
    return total1/sizeofcars;

}


 int&  CarData:: operator[](int numberofcustomer){
    if(numberofcustomer>sizeofcars)
        throw runtime_error("number is greater than size of cars");
    for(int i=0;i<sizeofcars;i++){
        if((i+1)==numberofcustomer)
        {
            return period[i];
        }
    }
     return period[sizeofcars];
 }

 bool operator<(const CarData &A,const CarData &B){
    if(A.sizeofcars<B.sizeofcars)
        return 1;
    else
     return 0;
 }

void CarData::removeRentals(string name){
    int where=0;
    for(int i=0;i<sizeofcars;i++)
        if(customer[i]==name)
            where=1;
    if(where==1){
        where=0;
        string *nameofcustomer=new string[sizeofcars-1];
        int *newperiod=new int [sizeofcars-1];
        for(int i=0;i<sizeofcars;i++){
            if(customer[i]!=name){
                nameofcustomer[where]=customer[i];
                newperiod[where]=period[i];
                where++;
            }
                }
        delete [] customer;
        delete [] period;
        customer=nameofcustomer;
        period=newperiod;
        sizeofcars--;
    }
    else
        throw runtime_error("name not found");
}
