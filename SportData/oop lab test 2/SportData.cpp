//
//  SportData.cpp
//  oop lab test 2
//
//  Created by Hande Erdal on 21.12.2022.
//

#include "SportData.hpp"
#include <stdio.h>
#include <iostream>
#include <sstream>
using namespace std;



SportData::SportData(string description,string sportsmanName){
    this->description=description;
    this->sportsmanName=sportsmanName;
    
}

SportData::~SportData(){
    howmany_SportData--;
    cout<<description<<"and "<<sportsmanName<<" dissapeared"<<endl;
}


int SportData::count(){
    return howmany_SportData;
}


string SportData:: getdescription(){
    return description;
}

string SportData:: getsportsname(){
    return sportsmanName;
}
void SportData:: setdescription(string a){
    description=a;
    
}
void  SportData:: setsportsname(string b){
    sportsmanName=b;
}

SportData::SportData(const SportData &A){
    description= A.description;
    sportsmanName=A.sportsmanName;
    howmany_SportData++;
}


TimeResult::~TimeResult(){
    cout<<sportsmanName<<":::"<< time<<" destroyed"<<endl;
}

string TimeResult::gettime(){
    return time;
}

void TimeResult::settime(string a){
    time=a;
}


double DistanceResult:: getdis(){
    return distance;
}
void DistanceResult:: setdis(double a){
    distance=a;
}

string DistanceResult::getbestresult(){
    ostringstream os;
    os<<distance;
    return os.str();
}

double MultiDistanceResult:: getdis(int i){
    if(i<0 || i>=distance.size())
        throw logic_error("wrong ");
    return distance[i];
}
void MultiDistanceResult:: adddis(float a){
    if(a<0){
        throw logic_error("Distant is cannot smaller than 0 ");
    }
    distance.push_back(a);
}
string MultiDistanceResult::getbestresult(){
    float best=distance[0];
    for(int i=0;i<distance.size();i++)
    {
        if(distance[i]>best)
            best=distance[i];
    }
    ostringstream os;
    os<<best;
    return os.str();
}
