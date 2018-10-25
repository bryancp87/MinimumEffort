//
//  main.cpp
//  Constructors project
//
//  Created by Bryan Cruz on 10/15/18.
//  Copyright © 2018 Bryan Cruz. All rights reserved.
//


//constructors have the same name as the class
// special member methods invoked during obj creation
// no return tyoe and can be overloaded .
//destructors invoked once automatically by compliler.
// one destructor per class.


#include "constructor.h"

int main()

{
    
    Player defaultEmpty;
    get_info(defaultEmpty);
    
    Player TOM ("TOM", 80, 10);
    get_info(TOM);
    
    Player HERO("HERO", 0, 1);
    get_info(HERO);
    
    Player FRANK("FRANK" , 70 , 8);
    get_info(FRANK);
    
    Player *enemy = new Player("ENEMY" , 10,1);
    get_info(*enemy);
    delete enemy;
    
    Player *levelBoss = new Player("BOSS", 100,100);
    get_info(*levelBoss);
    delete levelBoss;
    
    return 0;
}
