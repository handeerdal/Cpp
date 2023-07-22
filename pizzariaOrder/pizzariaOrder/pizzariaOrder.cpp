//
//  pizzariaOrder.cpp
//  pizzariaOrder
//
//  Created by Hande Erdal on 19.11.2022.
//

#include "pizzariaOrder.hpp"
#include <iostream>

using namespace std;

PizzeriaOrder::PizzeriaOrder(string customerName)
{
    this->customerName=customerName;
    name_of_dishes=nullptr;
    price_of_dishes=nullptr;
    size_of_dishes=0;
}
 PizzeriaOrder::PizzeriaOrder(const PizzeriaOrder &A){
    this->customerName=A.customerName;
     this->size_of_dishes=A.size_of_dishes;
     name_of_dishes=new string[size_of_dishes];
     price_of_dishes=new double[size_of_dishes];
     
    for(int i=0;i<size_of_dishes;i++)
    {
        name_of_dishes[i]=A.name_of_dishes[i];
        price_of_dishes[i]=A.price_of_dishes[i];
            }
 }


PizzeriaOrder::~PizzeriaOrder()
{
    
    delete [] name_of_dishes ;
    delete [] price_of_dishes;
    cout<<"data cleaned"<<endl;
    cout<<size_of_dishes<<" dishes cleaned"<<endl;
}

void PizzeriaOrder::setCustomer(string name){
    customerName=name;
}

string PizzeriaOrder::getCustomer(){
    return customerName;
}

void PizzeriaOrder::addDish(string dishesname,double price){

    string *tempdishes=new string [size_of_dishes+1];
    double *pricedishes=new double [size_of_dishes+1];

    for(int i=0;i<size_of_dishes;i++){
        tempdishes[i]=name_of_dishes[i];
        pricedishes[i]=price_of_dishes[i];
            }
            tempdishes[size_of_dishes]=dishesname;
            pricedishes[size_of_dishes]=price;
            delete [] name_of_dishes;
            delete [] price_of_dishes;

            name_of_dishes=tempdishes;
            price_of_dishes=pricedishes;
            all_dishes_ordered++;
    size_of_dishes++;

}

 int PizzeriaOrder::getDishesCount(){
    return all_dishes_ordered;
}


ostream&  operator<<(ostream &os, const PizzeriaOrder &A){
    os<<"Customer Name :"<< A.customerName<< "List of dishes and prices :"<<endl;
    for(int i=0;i<A.size_of_dishes;i++){
        os<<A.name_of_dishes[i]<<" ";
        os<<A.price_of_dishes[i]<<endl;
    }
    os<<"Total cost is: "<<A.totalCost()<<endl;


    return os;
}

double PizzeriaOrder::totalCost()const{
    double total=0;
    for(int i=0;i<size_of_dishes;i++){
        total+=price_of_dishes[i];
    }
    return total;
}

PizzeriaOrder& PizzeriaOrder :: operator=(const PizzeriaOrder &A){
    if(this==&A){
        throw runtime_error("same addresses");
    }
        
        else{
        this->customerName=A.customerName;
        this->size_of_dishes=A.size_of_dishes;
        name_of_dishes=new string[size_of_dishes];
        price_of_dishes=new double[size_of_dishes];
        for(int i=0;i<size_of_dishes;i++){
            name_of_dishes[i]=A.name_of_dishes[i];
            price_of_dishes[i]=A.price_of_dishes[i];
        }
    }
    return *this;
}

void PizzeriaOrder::removeDish(string name){
   int where=0;
    for(int i=0;i<size_of_dishes;i++)
    {
        if(name_of_dishes[i]!=name)
            where++;
    }
           if(where==size_of_dishes){
            throw runtime_error("dishes not found.");

        }
        
    
    string *temp=new string [size_of_dishes-1];
    double *tempprice= new double [size_of_dishes-1];
     where=0;
    for(int i=0;i<size_of_dishes;i++)
        if(name_of_dishes[i]!=name){
            tempprice[where]=price_of_dishes[i];
            temp[where]=name_of_dishes[i];
            where++;
        }
    delete [] name_of_dishes;
    name_of_dishes=temp;
    size_of_dishes--;
    all_dishes_ordered--;
}


bool operator<(const PizzeriaOrder &A,const PizzeriaOrder &B){
    if(A.size_of_dishes<B.size_of_dishes)
        return 1;
    else
        return 0;
    
}

double& PizzeriaOrder:: operator[](int nameofdish){
    for(int i=0;i<size_of_dishes;i++)
    {
        if(name_of_dishes[i]==nameofdish)
            return name_of_dishes[i];
    }
}


