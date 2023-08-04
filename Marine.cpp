#include "Marine.h"
#include <iostream>
#include <string>
using namespace std;

// Name: Marine() - Default Constructor
// Description: Creates a new marine
// Preconditions: None
// Postconditions: Can create a marine
Marine::Marine():Terran(){

}
// Name: Marine(string name, int hp)
// Description: Creates a new Marine
// Preconditions: None
// Postconditions: Can create a Marine
Marine::Marine(string name, int hp):Terran(name, hp){

}
// Name: ~Marine - Virtual Destructor
// Description: Makes sure everything in child class is deallocated
// Preconditions: None
// Postconditions: Everything dynamically allocated is deallocated
Marine::~Marine(){

}
// Name: SpecialAttack
// Description: Defines the Marine's special attack
// Preconditions: None
// Postconditions: Returns damage from special attack
int Marine::SpecialAttack(){
    srand(time(0));
    int a = (rand() % 8) + 1;
    cout << GetName() << " spins up doing GATLING DAMAGE!" << endl;
    cout << GetName() << " deals a damage!" << endl;
    return a;

}
