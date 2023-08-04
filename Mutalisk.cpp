#include "Mutalisk.h"
#include <iostream>
#include <string>
using namespace std;
// Name: Mutalisk() - Default Constructor
// Description: Creates a new Mutalisk
// Preconditions: None
// Postconditions: Can create a Mutalisk
Mutalisk::Mutalisk():Zerg(){

}
// Name:  Mutalisk(string name, int hp)
// Description: Creates a new Mutalisk
// Preconditions: None
// Postconditions: Can create a Mutalisk
Mutalisk::Mutalisk(string name, int hp):Zerg(name, hp){

}
// Name: SpecialAttack
// Description: Defines the Mutalisk's special attack
// Preconditions: None
// Postconditions: Returns damage from special attack
int Mutalisk::SpecialAttack(){
    cout << GetName() << " blasts you with their attack!" << endl;
    cout << GetName() << "deals 4 damage!" << endl;
    return 4;

}
