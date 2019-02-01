//
//  main.cpp
//  NumberSortingProject
//
//  Created by Bryan Cruz on 1/31/19.
//  Copyright © 2019 Bryan Cruz. All rights reserved.
//
//Purpose: This project shows how input can be stored in an array and then this array is sent to a function to sort
//each value stored in an ascending order
//

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;
const int MAX = 10;
int NUMARRAY [MAX];
void sortFunction(int nums[], int max);


int main(int argc, const char * argv[])
{
    int input;
    // Here we are entering 10 numbers between 1 and 100 and pushing them into the array as they are inputed. this loop does all the work
    cout << "ENTER 10 numbers to sort (1 - 100): "<< endl;
    for (int i = 0 ; i < MAX ; i++)
    {
        cin >> input;
        NUMARRAY[i] = input;
    }
    
    
    // Here we are displaying the values entered
    cout << "The entered values to be sorted are: ";
    for (int i = 0 ; i < MAX ; i++)
    {
        cout << NUMARRAY[i] << "  " ;

    }
    // function is called and we are sending the array and the maximum vales to be entered, in this case is 10
    sortFunction(NUMARRAY, MAX);
    
    // after the array values are sorted in ascending order, this loop helps display the sorted numbers
    cout << endl;
    cout << "The sorted numbers are: ";
    for (int i = 0 ; i < MAX ; i++)
    {
        cout << NUMARRAY[i] << "  " ;
    }
    
    system("PAUSE");
}

// function for sorting an array
void sortFunction(int nums[], int max)
{
    int temp;
    //nested loops used to do the sorting. first element in index i enteres and is compared to the rest of the elements.
    // then i is increassed by 1, and index i+1 is then entered
    for (int i = 0 ; i < max ; i++)
    {
        for (int j = i+1; j < max ; j++)
        {
            // we have to assign the value of index i to a temporary integer (temp) which will allow to hold a value in case we will be sorting.
            // this will help with changing values between elements in different indexes of the array
            if (nums[i] > nums [j])
            {
                temp = nums[i];
                nums[i] = nums [j];
                nums[j] = temp;
                
            }
            
        }
        
    }
    
}
