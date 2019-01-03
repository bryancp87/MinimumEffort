//
//  main.cpp
//  Arrays_vs_Vectors
//
//  Created by Bryan Cruz on 1/2/19.
//  Copyright © 2019 Bryan Cruz. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
using namespace std;

const int MAX = 5;
vector <double> numVector;
double numArray[MAX];
double inNum;
double sumArr(double[],int);//declaration of function used to add elements in array

int main(int argc, const char * argv[]) {

    for (int i=0; i < MAX; i++)// loop to enter values and used push back to push them into the vector
    {
        cout<< "enter a decimal value: " << endl;
        cin >> inNum;
        numVector.push_back(inNum);
    }
    for (int j=0; j < MAX ; j++)// loop to move elements of vector into array
    {
        numArray[j] = numVector.at(j);
    }
    
    cout<< "the sum is:" << sumArr(numArray, MAX) << endl;
    return 0;
}


double sumArr(double arr[], int maxsize) //function created to add elements of array
    {
        double sum = 0;
    for (int i=0; i<maxsize; i++)
    {
        sum += arr[i+1];
    }
        return sum;
    }

