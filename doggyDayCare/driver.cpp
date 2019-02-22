//
//  driver.cpp
//  doggyDayCare
//
//  Created by Bryan Cruz on 2/18/19.
//  Copyright © 2019 Bryan Cruz. All rights reserved.
//

#include <stdio.h>
#include "doggyDayCare.h"
//prototype function to print Invoice for a pet
void printInvoice(Dog);

int main()
{
    //declaration of variables as well as default object DogCreated for Dog class
    int selection;
    ofstream outFile;
    ifstream inFile;
    string fileName;
    Dog dogCreated("","","","",0,0.0,0.0);
    
    
    //do-while loop to keep running the program until user selects 0(exit)
    do{
        cout << "would you like to " << endl;
        cout << " create a file (1) " << endl;
        cout << " read a file (2) " << endl;
        cout << " exit program (0)" << endl;
        cout << " selection: ";
        cin >> selection;
        //try block where depending on above selection , a case will be followed to either create or open a file
    try{
        
            switch (selection)
            {
                    // case 1 is for the creation of a file using ofstream constructor outFile.
                    
                case 1:
                {
                    // the open function here takes whateever file name entered and uses another builtin function c_str() to return a pointer to an array that contains a null terminated sequence of characters representing the current value of the basic string object.
                    cout << "Enter the name of the file you wish to create: ";
                    cin >> fileName;
                    outFile.open(fileName.c_str());
                    //if loop to catch a failed ofstream operation for the outFile object. This will return a runtime error
                    if(outFile.fail())
                    {
                        throw runtime_error("Unable to create file: " + fileName);
                    }
                    //Dummy test object is created with the name DASH to place something in the newly created file
                    Dog Dash("Dash", "245" , "Rich Sanchez", "552 Spooner st.", 5, 10, 50);
                    Dash.writeFile(outFile);
                    //Always close your ofstream objects created, which frees up memory.
                    outFile.close();
                    cout << "File created"<< endl;
                    break;
                }
                case 2:
                {   // this case number 2 is where opening an existing file process is. using the same open & c_str() functions to properly read the file name
                    cout << "Enter the file you wish the read: ";
                    cin >> fileName;
                    inFile.open(fileName.c_str());
                    // if loop for a fail inFile operation
                    if(inFile.fail())
                    {
                        throw runtime_error("Could not find file: " + fileName);
                    }
                    // while loop which is built to continue to read a file as long as we have not reached the end of the file.
                    while(!inFile.eof())
                    {
                        //function readFile which I built to properly read the data in the file (see doggyDayCare.cpp file for more details)
                        dogCreated.readFile(inFile);
                        if(!inFile.eof())
                        {
                            //using the print Invoice function to display the content of the file
                            printInvoice(dogCreated);
                        }
                    }
                    //closing if stream object created
                    inFile.close();
                    break;
                }
                // case 0 is for when the user wants to exit the program
                case 0:
                {system("PAUSE");}
            }
        
        }       // catch for detecting any runtime errors outside of the cases created.
                catch(runtime_error& error)
                {
                        cout << "File error: "<< error.what();
                        outFile.clear();
                        inFile.clear();
                }
    }while (selection != 0);
}

//print invoice function where we use getters to pull the data from the objects created or that exist
void printInvoice(Dog dogCopy)
{
        cout << "Name: " << dogCopy.getName() << endl;
        cout << "ID " << dogCopy.getID() << endl;
        cout << "Owner: " << dogCopy.getOwnerName() << endl;
        cout << "Address: " << dogCopy.getAddress() << endl;
        cout << "Age: " << dogCopy.getAge() << endl;
        cout << "days cared for: " << dogCopy.getDays() << endl;
        cout << "total ammount to pay: " << dogCopy.calcPay() << endl;
}
