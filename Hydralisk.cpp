#include "Hydralisk.h"
#include <iostream>
#include <string>
using namespace std;

// Name: Hydralisk() - Default Constructor
// Description: Creates a new Hydralisk
// Preconditions: None
// Postconditions: Can create a Hydralisk
Hydralisk::Hydralisk():Zerg(){

}
// Name: Hydralisk(string name, int hp)
// Description: Creates a new Hydralisk
// Preconditions: None
// Postconditions: Can create a Hydralisk
Hydralisk::Hydralisk(string name, int hp):Zerg(name, hp){

}
// Name: SpecialAttack
// Description: Defines the Hydralisk's special attack
// Preconditions: None
// Postconditions: Returns damage from special attack
int Hydralisk::SpecialAttack(){
    cout << GetName() << " prays you with deadly acid!" << endl;
    cout << GetName() << " deals " << 2 << "damage" << endl;
    return 2;
}