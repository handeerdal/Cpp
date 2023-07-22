//
//  Repository.h
//  lab11 examples
//
//  Created by Hande Erdal on 7.01.2023.
/*
 Define the class Repository with a description, a total capacity and a dynamic list of the cases stored in the repository. Implement the following public methods of the class:
 • a one enabling to add a new case of an arbitrary type to the repository (with the control of the total capacity of the repository, CapacityError should be thrown if the total capacity could be exceeded),
 • a one enabling to remove the case (by its label) from the repository (throwing the NameError exception if it doesn't exist),
 • a one enabling to remove all the cases from the repository,
 • a method returning the summary volume of all the cases stored in the repository.
 Overload the indexing operator ([]) for the Repository to have a direct access to the item on the particular position in the list (throwing the IndexError exception if it doesn't exist). Overload the shift-left operator (<<) printing the data of the repository and the details of all the cases stored. Add all the other members which are necessary to make the functionality of the class complete or are required to run the code below.
 */

#ifndef Repository_h
#define Repository_h

#include <iostream>
#include "Case.hpp"
#include <cmath>
#include <stdio.h>
#include <list>
using namespace std;

class Repository{
private:
    double totalcapacity;
    string description;
    list <Case*> CL;
    double free_space;
public:
    Repository(string d="",double t=0){
        totalcapacity=t;
        description=d;
        free_space=totalcapacity;
    }
    
    
    
    class CapacityError : public runtime_error{
    public:
        CapacityError(string msg="error occured"): runtime_error(msg)
        { }
    };
    
    void add(Case* cs){
        double v=cs->getCapacity();
        if(v>free_space){
            cout<<cs->gettext()<<" too big. free space only "<<free_space<<endl;
            delete cs;   ///object cannot be added - we should make the memory free
            throw CapacityError();
        }
        else{
            CL.push_back(cs);
            free_space=free_space-v;
        }
    }
    
    void remove(){
        free_space+=CL.front()->getCapacity();
        CL.pop_front();
        
    }
    
    void removeall(){
        list<Case*>::iterator it;
                for(it = CL.begin(); it!=CL.end(); it++)
                {
                    delete *it;
                }
                CL.clear(); ///makes the store empty (and usable again)
                free_space = totalcapacity;
            }
        
        
    
    
    
    
    
    
    
    
    float summaryVolume(){
        double sum=0;
        
        for(list<Case*>::iterator i=CL.begin(); i!=CL.end(); i++)
        {
            sum+=(*i)->getCapacity();
        }
        
        return sum;
    }
    

    friend ostream& operator<<(ostream &os, Repository &e);
    
    
 //  list<Case*>::iterator& operator[](int index) {
 //
 //      list<Case*>::iterator i=CL.begin();
 //      for(int b=0;b<index;b++)
 //          i++;
 //      return i;
 //   }
    
};


ostream& operator<<(ostream &os, Repository &e)
{
    os << e.description << " " << e.free_space <<endl;
    int j=0;
    for(list<Case*>::iterator i=e.CL.begin(); i!=e.CL.end(); i++)
    {
        j++;
        os << j << ". " << (*i)->gettext() << ": " << (*i)->getcolor() <<" "<< (*i)->getCapacity()<< endl;

    }


    return os;


}



#endif /* Repository_h */
