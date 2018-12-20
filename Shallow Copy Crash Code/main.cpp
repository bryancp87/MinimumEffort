//
//  main.cpp
//  ShallowVSDeepCopy
//
//  Created by Bryan Cruz on 10/28/18.
//  Copyright © 2018 Bryan Cruz. All rights reserved.
//

#include <iostream>
#include "Header.h"
using namespace std;

int main(int argc, const char * argv[])
{
    //Shallow copy test 1
    ShallowCopy obj1 = 100;
    display_shallow (obj1);
    cout << "Shallow Copy TEST OBJ2 = OBJ1" << endl;

    
    // Shallow copy test 2
    obj1.setDataValue(1000);
    ShallowCopy obj2 = obj1;
    display_shallow(obj2);
    cout << "Shallow Copy being created. OBJ2 = OBJ1" << endl;
    
    return 0;

}
