//
//  main.cpp
//  reverseStringDifMethod
//
//  Created by Bryan Cruz on 2/1/19.
//  Copyright © 2019 Bryan Cruz. All rights reserved.
//


// This project reverses a string without using any swap or reverse. I made the reverse string function from scratch to show how each copy of the indexes work. This program takes an input string and reverses it, afterwhich it will ask if the user wishes to try to reverse another string again. it does input verification for y or n and repeats the code if input is 'y' using a do-while loop

#include <iostream>
#include <string>
#include <iomanip>
using namespace std;
void reverseString(string word, double size);
string yesno;

int main(int argc, const char * argv[])
{
    do
    {
    string input;
    cout << "Enter the string you wish to reverse: " << endl;
    cin >> input;
    double wordSize= input.size();
    reverseString(input, wordSize);
    cout << "do you want to reverse another string?(y / n):  " << " ";
    cin >> yesno;
    yesno[0] = tolower(yesno[0]);
    while (yesno[0] != 'y' && yesno[0] != 'n')
    {
        cout << "Invalid. Enter y or n: " << " " ;
        cin >> yesno;
        yesno[0] = tolower(yesno[0]);
    }
        
        if (yesno[0] == 'n')
        {
            cout << "Thank you for participating" << endl;
            return 0;
        }

    }while (yesno[0] == 'y');

}



void reverseString(string word, double size)
{
    int end = size - 1;
    int start = 0;

// this function uses a temporary variable to store the first element of the string . the fist element of the string is then replaced with the last and the last element then is assigned the temporary value. 
      while (start <= end)
        {
            char temp = word[start];
            word[start] = word[end];
            word[end] =  temp;
            start++;
            end--;
            
            if (start >= end) {     cout << word << endl;
                break;
            }
            
        }
}
