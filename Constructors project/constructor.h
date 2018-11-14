//
//  constructor.h
//  Constructors project
//
//  Created by Bryan Cruz on 10/15/18.
//  Copyright © 2018 Bryan Cruz. All rights reserved.
//

#ifndef constructor_h
#define constructor_h
#include <string>
#include <iostream>
using namespace std;

//Player class created to move the entered objects
class Player
{
 // private variables . only accessed by members of class
private:
    string name;
    int health;
    int xp;
// declaration of public functions and constructors,deconstructor.
public:
    string get_name(){return name;}
    int get_health() {return health;}
    int get_xp() {return xp;}
    Player ( string name_val = "None", int health_val = 100, int xp_val = 1); //defaulting variables in declaration of default constructor
    Player (const Player &source);
    ~Player();
};
//default constructor
Player::Player (string name_val , int health_val, int xp_val)
: name {name_val}, health {health_val} , xp {xp_val} {cout << "three arg constructor called for " << name<< endl;}

//copy constructor . with delegation to the default constructor
Player::Player (const Player &source)
    : Player{source.name , source.health , source.xp} {cout << "copy constructor called for " << source.name<< endl;}
    
//destructor runs to destroy objects being passed.
Player::~Player() {cout << "destructor called for " << name<< endl;}

    
//Function get_info makes use of Copy constructor
void get_info (Player objectPassed)
    {
        cout << "NAME: " << objectPassed.get_name() << endl;
        cout << "HEALTH: " << objectPassed.get_health() << endl;
        if ( objectPassed.get_health() == 0 ) {cout << "DEAD"<< endl;} else {cout << "STILL ALIVE"<< endl;}
        cout << "XP: " << objectPassed.get_xp()<< endl;
    }

#endif /* constructor_h */
    
    
    
//     NOTES TO UNDERSTAND ABOUT DEFAULT and COPY CONSTRUCTORS and DESTRUCTORS:
//     1. defailt constructor can be referenced by other constructor types to clean up and simplify code
//     2. default constructor declaration lines should contain defaulting values in its argument brackets.
//     3. destructor is mainly important when using pointers, networking processes and file management or data allocation
//     4. Any function that makes use of source variables such as the get_info seen above, will need a copy made which is why we made the copy constructor
//     5. copy constructor arguments should be constant since we don't want to alter the source data , and should be a reference to the source as we need a copy of it.
//
    
     
     
