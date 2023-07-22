//
//  main.cpp
//  lab11 examples
//
//  Created by Hande Erdal on 7.01.2023.
//

#include <iostream>
#include "Case.hpp"
#include <cmath>
#include <stdio.h>
#include <list>
#include "Repository.h"
using namespace std;


int Case::how_many_cases=0;

int main(int argc, const char * argv[]) {
    Repository repo("Warehouse", 100);
    cout << Case::count() << endl; //0
    try {
    repo.add(new BrickCase("books", "0x000000", 5, 3.5, 4)); //5 x 3.5 x 4
    repo.add(new TubeCase("posters", "0x00ff00", 1, 3)); //radius=1, height=3
    repo.add(new PrismCase("toys", "0x800080", 3, 2)); //base=3, height=2
    repo.add(new BrickCase("jewels", "0xffff00", 2, 2, 2)); //2 x 2 x 2
    repo.add(new BrickCase("trinkets", "0x000080", 5, 1, 1)); //5 x 1 x 1
    } catch(Repository::CapacityError &e) {
        cout << e.what() << endl; //trinkets too large - only 4.8 free space
        
    }
    cout<<repo;
    cout<<repo.summaryVolume()<<endl;
    cout << Case::count() << endl; //0
    repo.remove();
    cout << Case::count() << endl; //0
    cout<<endl;
    cout<<repo;
    cout<<repo.summaryVolume()<<endl;
    //cout <<repo[1]->getCapacity()<< endl;
        return 0;
    }
