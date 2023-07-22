//
//  carData.hpp
//  carData
//
//  Created by Hande Erdal on 20.11.2022.
//

#ifndef carData_hpp
#define carData_hpp

#include <stdio.h>

#include <iostream>
 #include <string>
 using namespace std;

class CarData
{
    /*
    car registration number, car brand (strings), and
    two arrays/lists of the same size (empty by default)
    storing respectively names of customers (strings) and lengths of periods
    for which they rented this car (in hours; integer numbers). */
private:
    string registrationnumber;
    string brand;
    string *customer;
    int *period;
    int sizeofcars;
    static int how_much_car_rented;
    int total;


public:
    CarData(string,string);
    CarData(const CarData &A);
    ~CarData();
    void setRegistrationNumber(string);
    string getRegistrationNumber();
    string getBrand();
    void addRental(string,int);
    void removeRentals(string);
    double averageTime();
    static int getRentalsCount();
    friend  bool operator<(const CarData &A,const CarData&B);
    int& operator[](int);
    friend  ostream& operator<<(ostream&os,const CarData&A);
    CarData& operator=(const CarData&A);
};


 bool operator<(const CarData &A,const CarData&B);
 ostream& operator<<(ostream&os,const CarData&A);


#endif /* carData_hpp */
