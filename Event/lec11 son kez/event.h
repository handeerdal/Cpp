//
//  event.h
//  lec11 son kez
//
//  Created by Hande Erdal on 9.01.2023.
/*
 Define the class SportEvent with a description, a place (i.e. a city name), a year, and a dynamic list of the results of the event. Implement the following public methods of the class:
 • a one enabling to insert a new result of an arbitrary type to the result list on the specified position (moving the results from this and the further positions towards the end of the list), or at the end of the list if the position doesn't exist. The position numbers should start from 1.
 • a one enabling to remove all the results from the list,
 • a method returning the best sportsman of this event for the given sporting discipline.
 Overload the indexing operator ([]) for the SportEvent to have a direct access to result on the particular position in the result list (throwing an exception if it doesn't exist). Overload the shift-left operator (<<) printing the data of the event and the details of all the results of this event. Add all the other members which are necessary to make the functionality of the class complete or are required to run the code below.

 */

#ifndef event_h
#define event_h
#include<string>
#include<vector>
#include<sstream>
#include <list>
#include<iostream>
#include "sport.h"
using namespace std;

class SportEvent{
private:
    
    string d;
    string p;
    int y;
    list<SportData*>SL;
public:
   ~SportEvent(){
       for(list<SportData*>::iterator i=SL.begin();i!=SL.end();i++)
            delete *i;
    }
    class SpaceError:public range_error{
    public:
        SpaceError(string msg="error occured"):range_error(msg)
        { }
    };
    void addSpecified(int pos,SportData *s){
        if(pos<0 || pos>SL.size())
            SL.push_back(s);
        else{
            list<SportData*>::iterator i=SL.begin();
            for(int k=0;k<pos;k++){
                i++;
            }
            SL.insert(i, s);
            
        }
    }
    void addFirst(SportData *s){
        SL.push_front(s);
    }
    void clearall(){
        for(list<SportData*>::iterator i=SL.begin();i!=SL.end();i++)
            delete *i;
        SL.clear();
    }
    friend ostream& operator<<(ostream &os,SportEvent &e);
    
    SportData* operator[](int a){
        list<SportData*>::iterator i=SL.begin();
        for(int k=0;k<a;k++){
            i++;
        }
        return *i;
    }
};

ostream& operator<<(ostream &os,SportEvent &e){
    for(list<SportData*>::iterator i=e.SL.begin();i!=e.SL.end();i++)
        os<<(*i)->getDiscipline();
    return os;
}






#endif /* event_h */
