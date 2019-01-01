//
//  main.cpp
//  DeepCopy
//
//  Created by Bryan Cruz on 12/19/18.
//  Copyright © 2018 Bryan Cruz. All rights reserved.
//

#include <iostream>
#include "Header.h"
using namespace std;

int main(int argc, const char * argv[])
{
    DeepCopy obj1(100);
    displayValue(obj1);
    
    DeepCopy obj2 {obj1};
    obj2.setDataValue(1000);


    displayValue(obj2);
    displayValue(obj1);
    
    return 0;
}
