//
//  SportData.hpp
//  oop lab test 2
//
//  Created by Hande Erdal on 21.12.2022.
/*
 Override, for each of the above classes, the virtual method getBestResult, making it to return the best results stored in the given class.
 */

#ifndef SportData_hpp
#define SportData_hpp

#include <vector>
#include <stdio.h>
#include <iostream>
using namespace std;

class SportData{
private:
    static int howmany_SportData; //static bi verimiz var bunu bi fonksyonla return etmek istersek fonksiyon static olmalı
protected:
    string description;
    string sportsmanName;
  
public:
    SportData(string description="",string sportsmanName="");
    SportData(const SportData &A);
    virtual ~SportData(); // virtual bi fonksiyon varsa destructor virtual olmalı.
    virtual string getbestresult()=0;
    static int count();
    string getdescription();
    string getsportsname();
    void setdescription(string);
    void setsportsname(string);

};

class TimeResult: public SportData{
protected:
    string time;
public:
    TimeResult(string description=" ",string sportsmanName=" ",string time="00:00:00:00"):SportData(description,sportsmanName){
        this->time=time;
    } //İÇİNDE YAZMAYINCA HATA VERDİ
    ~TimeResult();
    string gettime();
    void settime(string);
    string getbestresult(){
        return time;
    }

};

    
    
class DistanceResult : public SportData{
protected:
    double distance;
public:
    DistanceResult(string description=" ",string sportsmanName=" ",double dis=0.0):SportData(description,sportsmanName){
        
        if(dis<0){
            throw logic_error("Distant is cannot smaller than 0 ");
        }
        distance=dis;
    }
    double getdis();
    void setdis(double);
    string getbestresult();
    
};


class MultiDistanceResult : public SportData{
protected:
   vector <float> distance; //lists of results
public:
    MultiDistanceResult(string description=" ",string sportsmanName=" "):SportData(description,sportsmanName){
    }
    double getdis(int);
    void adddis(float);
    string getbestresult();
    
};

#endif /* SportData_hpp */
