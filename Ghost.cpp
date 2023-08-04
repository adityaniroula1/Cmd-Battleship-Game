#include "Ghost.h"
#include <iostream>
#include <string>
using namespace std;

// Name: Ghost() - Default Constructor
// Description: Creates a new Ghost
// Preconditions: None
// Postconditions: Can create a Ghost
Ghost::Ghost():Terran(){

}
// Name: Ghost(string name, int hp)
// Description: Creates a new Ghost
// Preconditions: None
// Postconditions: Can create a Ghost
Ghost::Ghost(string name, int hp):Terran(name, hp){

}
// Name: ~Ghost - Virtual Destructor
// Description: Makes sure everything in child class is deallocated
// Preconditions: None
// Postconditions: Everything dynamically allocated is deallocated
Ghost::~Ghost(){

}
// Name: SpecialAttack
// Description: Defines the Ghost's special attack
// Preconditions: None
// Postconditions: Returns damage from special attack
int Ghost::SpecialAttack(){
    srand(time(0));
    int a = (rand() % 11) + 2;
    cout << GetName() << " performs a sneak attack!" << endl;
    cout << GetName() << "deals " << a << "damage" << endl;
    return a;

}