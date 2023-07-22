//
//  main.cpp
//  example1 oop
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
//  Created by Hande Erdal on 15.11.2022.

//getOrderCount – returning the total number of customer’s orders made so far

#include <iostream>
#include "costumer.hpp"
using namespace std;

int ConsumerOrder::how_many_people=0; //GET FUNCTİON



int main(int argc, const char * argv[]) {
        
    cout<<ConsumerOrder::getOrderCount()<<endl;
    ConsumerOrder o1("John Smith");
    cout << o1.getCustomer()<<endl; //should be John Smith
    o1.addDish("vegetable soup", 20);
    o1.addDish("apple pie", 19);
    cout << o1.length()<<endl;
    cout<<o1<<endl;
    
    ConsumerOrder oo("Andrew Taylor");
    oo.addDish("tomato soup", 20);
    oo.addDish("grilled chicken", 45);
    oo.addDish("tomato soup", 20);
    oo.addDish("ice cream", 15);
    cout<<oo<<endl;
    
    oo=o1;
    cout<<oo<<endl;
    oo.removeDish("ice cream");
    cout << oo; //should print for example
    
    return 0;
}
