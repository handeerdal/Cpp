//
//  main.cpp
//  oop lab test 2
//
//  Created by Hande Erdal on 21.12.2022.
//

#include <iostream>
#include "SportData.hpp"
#include "SportEvent.hpp"
using namespace std;

int SportData::howmany_SportData=0;


int main(int argc, const char * argv[]) {
    cout<<SportData::count()<<endl;
    MultiDistanceResult *res=new MultiDistanceResult ("swimming","Johnny"); //POINTER DIZISINE SINIFTAN NESNE YERLESİTRMEK
    res->adddis(5.12);
    string a =res->getbestresult();
    cout<<a<<endl;
    
    SportEvent olympiad("swimming","turkey");
    
    return 0;
}
