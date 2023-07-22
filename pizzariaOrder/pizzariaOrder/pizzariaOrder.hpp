/*
Define the class PizzeriaOrder representing a list of dishes a customer orders in a pizzeria. The class should contain the following fields: a customer name and two arrays/lists of the same size (empty by default) storing respectively the names of dishes (strings) and their prices (real numbers). Implement the following public methods of the class :
• the default constructor with a string parameter representing a customer name,
• the copy-constructor and the assignment operator,
• a destructor,
• setCustomer and getCustomer methods,
• addDish method, with two parameters representing a dish name (a string) and its price (a real value), adding this dish to the order as the last position,
• removeDish method, with a dish name as a parameter, removing from the order the dish together with its price (or throwing an error if the dish is not in the order),
• totalCost – returning the total cost of the dishes in the order,
• getDishesCount – returning the summary number of all the dishes in all the orders existing
currently
• the operator <, where by a “smaller” order we mean a one with a shorter list of dishes,
• the indexing operator ([]) – with a dish name as a parameter, returning the price of the dish
placed in the order (an error should be thrown if the dish is not present in the order)
• the shift operator (<<) – printing the customer name, the numbered list of all the ordered
dishes and their costs, and the total cost of the order.
Write a program which tests all the class capabilities, in particular the following code should be enabled*/

#include <iostream>

using namespace std;
class PizzeriaOrder
{
private:
    string customerName;
    string *name_of_dishes;
    double *price_of_dishes;
    int size_of_dishes;
    static int all_dishes_ordered;

public:

    PizzeriaOrder(string);
    PizzeriaOrder(const PizzeriaOrder &A);
    ~PizzeriaOrder();
    void setCustomer(string);
    string getCustomer();
    void addDish(string,double);
    void removeDish(string);
    double totalCost()const;
    static int getDishesCount();
    friend ostream& operator<<(ostream &os,const PizzeriaOrder &A);
    PizzeriaOrder& operator=(const PizzeriaOrder &A);
    friend bool operator<(const PizzeriaOrder &A,const PizzeriaOrder &B);
    PizzeriaOrder operator+(const PizzeriaOrder &A);
    double& operator[](int);

};


ostream& operator<<(ostream &os,const PizzeriaOrder &A);
bool operator<(const PizzeriaOrder &A,const PizzeriaOrder &B);

