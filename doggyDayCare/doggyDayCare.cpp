//
//  main.cpp
//  doggyDayCare
//
//  Created by Bryan Cruz on 2/18/19.
//  Copyright © 2019 Bryan Cruz. All rights reserved.
//


#include "doggyDayCare.h"

//

//     Dog() = default; our default constructor was created in the header file and has no need to be declared here as we have selected the default setting for each type of variable.

// this is our Parameterized constructor
Dog::Dog(string dogName,string dogID,string dogOwner,string dogAddress,int dogAge,double days,double dayRate)
: name(dogName), tagID(dogID) , ownerName(dogOwner) , address(dogAddress) , age(dogAge), daysCaredFor(days), dailyRate(dayRate)
{
    cout << "information processed for: " << name << endl;
}

// deconstructor
Dog::~Dog()
{
    cout << endl;
}
// getters for the variables in the constructor
string Dog::getName()
{
    return name;
}
string Dog::getID()
{
    return tagID;
}
string Dog::getOwnerName()
{
    return ownerName;
}

string Dog::getAddress()
{
    return address;
}

int Dog::getAge()
{
    return age;
}

double Dog::getDays()
{
    return daysCaredFor;
}

double Dog::getRate()
{
    return dailyRate;
}

//calcPay operation which calculates the total ammount for the cared pet. This already adds a 15 % tax to the ammount
double Dog::calcPay()
{
    double tax = (daysCaredFor * dailyRate) * .15;
    double totalAmmount = (daysCaredFor * dailyRate) + tax;
    return totalAmmount;
}

//readFile function
// here is where reading the file is happening. in C++ there is a file pointer and we read each line until there is a space or end of line
//which is why the first string read is a name, the second an ID, the third an address and so fort.
// please note that for strings we use the getline operation and for the rest we simply output the content to the screen using the operand  >>
void Dog:: readFile(ifstream& inFile)
{
    getline(inFile, name);
    if(!inFile.eof())
    {
        if(inFile.fail())
        {
            throw runtime_error("Could not read Pet Name: " + name);
        }
        getline(inFile, tagID);
        if(inFile.fail())
        {
            throw runtime_error("Could not read Pet ID: " + name);
        }
        getline(inFile, ownerName);
        if(inFile.fail())
        {
            throw runtime_error("Could not read Owner name for : " + name);
        }
        getline(inFile, address);
        if(inFile.fail())
        {
            throw runtime_error("Could not read address for : " + name);
        }
        inFile >> age;
        if(inFile.fail())
        {
            throw runtime_error("Could not read age for: " + name);
        }
        inFile >> daysCaredFor;
        if (inFile.fail())
        {
            throw runtime_error("Could not read days Cared for information for: " + name);
        }
        inFile >> dailyRate;
        if(inFile.fail())
        {
            throw runtime_error("Could not read rate for : " + name);
        }
    }
}
//writeFle function.
//here is the same but there is no need to use getLine as we are simply inputing the values passed to the file using <<
void Dog:: writeFile(ofstream& outFile)
{
    outFile << name << endl;
    if(outFile.fail())
    {
        throw runtime_error("Could not write Pet Name: " + name);
    }
    outFile << tagID << endl;
    if (outFile.fail())
    {
        throw runtime_error("Could not write ID for: " + name);
    }
    outFile << ownerName << endl;
    if (outFile.fail())
    {
        throw runtime_error("Could not write Owner Name for: " + name);
    }
    outFile << address << endl;
    if (outFile.fail())
    {
        throw runtime_error("Could not write Address for: " + name);
    }
    outFile << age << endl;
    if (outFile.fail())
    {
        throw runtime_error("Could not write Age for: " + name);
    }
    outFile << daysCaredFor << endl;
    if (outFile.fail())
    {
        throw runtime_error("Could not write days Cared for information for: " + name);
    }
    outFile << dailyRate << endl;
    if(outFile.fail())
    {
        throw runtime_error("Could not write daily rate for: " + name);
    }
}


