//
//  doggyDayCare.h
//  doggyDayCare
//
//  Created by Bryan Cruz on 2/18/19.
//  Copyright © 2019 Bryan Cruz. All rights reserved.
//

#ifndef doggyDayCare_h
#define doggyDayCare_h

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;

class Dog
{
private:
    string name;
    string tagID;
    string ownerName;
    string address;
    int age;
    double daysCaredFor;
    double dailyRate;
    
public:
    string getName();
    string getID();
    string getOwnerName();
    string getAddress();
    int getAge();
    double getDays();
    double getRate();
    double calcPay() ;
    void readFile(ifstream&);
    void writeFile(ofstream&);
    Dog() = default;
    Dog(string,string,string,string,int,double,double);
    ~Dog();
};
#endif /* doggyDayCare_h */
