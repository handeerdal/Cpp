//
//  main.cpp
//  pizzariaOrder
//
//  Created by Hande Erdal on 19.11.2022.
//
#include "pizzariaOrder.hpp"

#include <iostream>

int PizzeriaOrder:: all_dishes_ordered=0;


using namespace std;

int main(int argc, const char** argv) {
    cout << PizzeriaOrder::getDishesCount(); //should be 0
    PizzeriaOrder o1("John Smith");
    cout << o1.getCustomer()<<endl;; //should be John Smith
    o1.addDish("garlic bread", 10);
    o1.addDish("Margherita pizza", 25);
    cout << o1.totalCost()<<endl; //should be 35
    cout << o1<<endl;
    PizzeriaOrder o2(o1);
    o2.addDish("aaa", 456);
    cout<<o2;
    cout<<endl;
    PizzeriaOrder o3=o1;
    o3.removeDish("garlic bread");
    cout<<endl;
    cout<<o3;
    cout<<endl;
    cout<<"all dishes are"<<endl;
    cout << PizzeriaOrder::getDishesCount()<<endl; //should be 0
    bool whichisgreater;
    whichisgreater= o1<o3;
    if(whichisgreater==1)
        cout<<"o1 is smaller than o3"<<endl;
    else
        cout<<"o3 is smaller than o1"<<endl;
    cout<<o1[5];
    
   return 0;
}
