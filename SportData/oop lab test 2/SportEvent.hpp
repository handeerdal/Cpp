//
//  SportEvent.hpp
//  oop lab test 2
//
//  Created by Hande Erdal on 21.12.2022.
/*
 
 Define the class SportEvent with a description, a place (i.e. a city name), a year, and a dynamic list of the results of the event. Implement the following public methods of the class:
 • a one enabling to insert a new result of an arbitrary type to the result list on the specified position (moving the results from this and the further positions towards the end of the list), or at the end of the list if the position doesn't exist. The position numbers should start from 1.
 • a one enabling to remove all the results from the list,
 • a method returning the best sportsman of this event for the given sporting discipline.
 Overload the indexing operator ([]) for the SportEvent to have a direct access to result on the particular position in the result list (throwing an exception if it doesn't exist). Overload the shift-left operator (<<) printing the data of the event and the details of all the results of this event. Add all the other members which are necessary to make the functionality of the class complete or are required to run the code below.
 Write a program which tests all the class capabilities, in particular the following code should be enabled:
 */

#ifndef SportEvent_hpp
#define SportEvent_hpp

#include <stdio.h>
#include <iostream>
#include "SportData.hpp"
using namespace std;

class SportEvent{
private:
    string place;
    string description;
    int year;
    SportData *resultList;
public:
    SportEvent(string description=" ",string place=" ",int year=0){
        this->description=description;
        this->place=place;
        this->year=year;
    }
};

#endif /* SportEvent_hpp */
