#include <iostream>
#include "carData.hpp"

using namespace std;

int CarData::how_much_car_rented=0;

int main()
{
    cout << CarData::getRentalsCount()<<endl; //should be 0
    cout<<"---------------------"<<endl;
    CarData c1("EL12345", "Toyota Yaris");
    cout << c1.getRegistrationNumber()<<endl; //should be  EL12345
    cout<<"---------------------"<<endl;
    c1.addRental("John Smith", 7);
    c1.addRental("Jonathan Taylor", 10);
    cout << c1.averageTime()<<endl; //should be 8.5
    c1[1] = 12; //changes the period of the first rental
    cout << c1; //should print for example:
    
}
