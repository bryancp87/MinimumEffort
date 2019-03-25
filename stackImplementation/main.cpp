//
//  main.cpp
//  stackImplementation
//
//  Created by Bryan Cruz on 3/24/19.
//  Copyright © 2019 Bryan Cruz. All rights reserved.
//

// This code is meant to help understand how a STACK works. Stack has a FILO order (First In Last Out),
//meaning that the last value added (pushed) being at the top of the Stack will be the first out(popped)


#include <iostream>
using namespace std;

int Stack[10];  // declaration of my Stack which holds 10 values
int indx = 0;   // indx will hold the value of the current index where we are located after popping and pushing
void push(int);  // declaration of push function which moves values into the stack
void pop();  // declaration of pop function which pops the value stored at the top of the Stack
int top();   // declaration of top function which checks what the value is at the top of the Stack
bool isEmpty(); // declaration of bool function isEmpty which checks if the stack is empty


int main(int argc, const char * argv[])
{
    int input;
    cout << "Enter 10 numbers to push to the stack: "<< endl;
    for (int i = 0; i < 10 ; i++)
        {
        cin >> input;
        cout << endl;
        push(input);
        }
    do{
        cout << "POP!!!!!" << endl;
        pop();
        cout << top() << " is now at the top of the stack and ready to be popped" << endl;
        }while (isEmpty() == false );
    
    cout << "stack is empty now" << endl;
}

// push function adds the value passed to the current index in the stack.
void push(int x)
{
    Stack[indx] = x;
    ++indx;
}

// pop function removes 1 from the index value and zeroes the index value
void pop()
{
    --indx;
    Stack[indx] = 0;

}
// isEmpty checks returns false if the index is greater than 1 and true if it its less or equal to 1.
bool isEmpty()
{
    if (indx >1) {return false;}
    else {return true;}
}
//top checks what the value at the top of the stack is.
int top()
{
    return Stack[indx -1];
}
