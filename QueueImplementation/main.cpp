//
//  main.cpp
//  QueueImplementation
//
//  Created by Bryan Cruz on 3/25/19.
//  Copyright © 2019 Bryan Cruz. All rights reserved.
//

// Queue implementation code. Queue has a FIFO order (first in first out). What ever is at the front of the list is what will be popped.
#include <iostream>
using namespace std;

int Queue[10]; // declaration of Queue array of 10 values
int backIndx{-1}, frontIndx{0}; // declaration of the front and back index. back will be initialized to -1 and the front initialized to 0
void push(int x); // push function. pushes new element to the queue
void pop(); // pop function. pops the element at the fron
bool isEmpty(); // checks if queue is empty
int front(); // checks the front element

int main(int argc, const char * argv[])
{
    int input;
    cout << "Enter 10 numbers to push to the QUEUE: "<< endl;
    for (int i = 0; i < 10 ; i++) // for loop to enter 10 values to the array
    {
        cin >> input;
        cout << endl;
        push(input); // element entered is pushed into the array
    }
    // do while loop to pop elements at the front until the queue is empty.
    do{
        cout << "POP!!!!!" << endl;
        pop();
        cout << front() << " is now at the front of the Queue and ready to be popped" << endl;
    }while (isEmpty() == false );
    
    cout << "stack is empty now" << endl;
    return 0;
    
}
void push(int x) // push function . back index is incremented by 1 before the input element is located in the queue at the back index location
{
    ++backIndx;
    Queue[backIndx] = x;
}
void pop () // pop function. element at the front index position is cleared or popped. after this then the front index is incremented by 1
{
    Queue[frontIndx] = 0;
    frontIndx++;
}
bool isEmpty() // isEmpty function. if the back index is smaller than the front then it returns true to the queue being empty. otherwise it returns false
{
    if (backIndx < frontIndx)
    {return true;}
    else
    {return false;}
}
int front() // front function. returns the element at the current front index location.
{
    return Queue[frontIndx];
}

