//
//  costumer.hpp
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
//

#ifndef costumer_hpp
#define costumer_hpp

#include <iostream>

using namespace std;

class ConsumerOrder{
private:
    string name;
    string* data1; //name
    double* data2; //prices
    int size;
    int id;
    static int how_many_people;
    int how_many_order_now;
public:
    static int getOrderCount(); //same for everybody dont call A.getOrder() call ConsumeroRDER::Getordercount
    ConsumerOrder(string);
    ConsumerOrder(const ConsumerOrder &A);
    ~ConsumerOrder();
    void setCostumer(string);
    string getCustomer();
    int getID();
    void addDish(string,double);
    void removeDish(string);
    int length();
    
    ConsumerOrder operator>(const ConsumerOrder &A);
    ConsumerOrder operator[](int);
    ConsumerOrder& operator=(const ConsumerOrder &A);//YANINDAKİ AMPERSANTI UNUTMA BU ÖNEMLİ AŞKOM
    friend ostream& operator<<(ostream &os,const ConsumerOrder &A );
    friend bool operator >(const ConsumerOrder &A,const ConsumerOrder &B);
    friend bool operator ==(const ConsumerOrder &A,const ConsumerOrder &B);


};

ostream& operator<<(ostream &os,const ConsumerOrder &A ); //& koymayı unutma
bool operator >(const ConsumerOrder &A,const ConsumerOrder &B); //CAN BE METHOD? ALSO JUST FRİEND FUNCTİON
bool operator ==(const ConsumerOrder &A,const ConsumerOrder &B);



//ConsumerOrder operator=(const ConsumerOrder &A);

#endif /* costumer_hpp */
