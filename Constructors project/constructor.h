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


class Player
{
private:
    string name;
    int health;
    int xp;
    
public:
    string get_name(){return name;}
    int get_health() {return health;}
    int get_xp() {return xp;}
    Player ( string name_val = "None", int health_val = 100, int xp_val = 1); //defaulting variables in declaration
    Player (const Player &source);
    ~Player();
};

Player::Player (string name_val , int health_val, int xp_val)
: name {name_val}, health {health_val} , xp {xp_val} {cout << "three arg constructor called for " << name<< endl;}

Player::Player (const Player &source)
    : name(source.name) , health(source.health) , xp(source.xp) {cout << "copy constructor called for " << source.name<< endl;}
    
Player::~Player() {cout << "destructor called for " << name<< endl;}

void get_info (Player objectPassed)
    {
        cout << "NAME: " << objectPassed.get_name() << endl;
        cout << "HEALTH: " << objectPassed.get_health() << endl;
        if ( objectPassed.get_health() == 0 ) {cout << "DEAD"<< endl;} else {cout << "STILL ALIVE"<< endl;}
        cout << "XP: " << objectPassed.get_xp()<< endl;
    }

#endif /* constructor_h */
