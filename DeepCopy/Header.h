//
//  Header.h
//  DeepCopy
//
//  Created by Bryan Cruz on 12/19/18.
//  Copyright © 2018 Bryan Cruz. All rights reserved.
//

#ifndef Header_h
#define Header_h

#include <iostream>
#include <string>
using namespace std;

class DeepCopy
{
    private:
    int *data;
    
    public:
    void setDataValue(int d){*data =d;}
    int getDataValue(){return *data;}
    DeepCopy (int d);
    DeepCopy (const DeepCopy &source);
    ~DeepCopy ();
    void displayValue (DeepCopy s);
};


DeepCopy::DeepCopy(int d)
{
    data = new int;
    *data = d;
}

DeepCopy::DeepCopy(const DeepCopy &source)
:DeepCopy{*source.data}//delegation to one arg constructor. here the integer passing is the one pointed to by data. now source and the copy made have a unique copy of the original heap storage.
{
    cout << "Copy constructor - deep copy done"<< endl;
    
}

DeepCopy::~DeepCopy()
{
    delete data;
    cout << "Destructor Called" << endl;
}


void displayValue(DeepCopy s)
{
    cout << s.getDataValue()<< endl;
}
#endif /* Header_h */
