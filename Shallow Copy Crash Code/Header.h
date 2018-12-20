//  Header.h
//  ShallowVSDeepCopy
//  Created by Bryan Cruz on 10/28/18.
//  Copyright © 2018 Bryan Cruz. All rights reserved.
//  Program Crashes on PURPOSE to show what happens if shallow copy is used with pointers to data


#ifndef Header_h
#define Header_h
#include <iostream>
#include <string>

using namespace std;
class ShallowCopy
{
private:
    int *data;  //RAW POINTER TO SINGLE INTEGER AS DATA MEMBER IS A PROBLEM
public:
    void display_shallow (ShallowCopy d);
    void setDataValue(int d){*data =d;}
    int getDataValue(){return *data;}
    ShallowCopy(int d);                         //one argument constructor generated
    ShallowCopy(const ShallowCopy &source);      //copy constructor created
    ~ShallowCopy();                              //destructor created
};

void display_shallow(ShallowCopy d)
{
    cout << "getting and displaying values copied" << endl;
    cout << d.getDataValue() << endl;// PROBLEM!!
}

ShallowCopy::ShallowCopy(int d)
{
    data = new int;    // allocation storage(int size) in heap dynamically
    *data = d;         // dereferencing pointer and storing the passed data to memory pointed at by *data
}



ShallowCopy::ShallowCopy(const ShallowCopy &source)// copy constructor = memberwise copy. In this case only the pointer is copied. This is a problem, the space is released in the destructor but pointer is still pointing to the space in memory
: data (source.data)                               // copying the value in data variable (pointer) from source to data (object) . Both will be pointing to the same location in memory
{
    cout<<"copy constructor called for "<< source.data << endl;
}

ShallowCopy::~ShallowCopy()
{
    cout << "Destructor called to free data" << endl;
    delete data;//freeing the storage which was allocated by the one argument copnstructor
    cout << "data deleted" << endl;
}

#endif /* Header_h */
