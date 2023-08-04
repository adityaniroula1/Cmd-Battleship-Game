#include "Zergling.h"
#include <iostream>
#include <string>
using namespace std;

// Name: Zergling() - Default Constructor
// Description: Creates a new Zergling type of zerg
// Preconditions: None
// Postconditions: Can create a Zergling
Zergling::Zergling():Zerg(){

}
// Name: Zergling(string name, int hp)
// Description: Creates a new Zergling
// Preconditions: None
// Postconditions: Can create a Zergling
Zergling::Zergling(string name, int hp):Zerg(name, hp){

}
// Name: SpecialAttack
// Description: Defines the Zergling's special attack
// Preconditions: None
// Postconditions: Returns damage from special attack
int Zergling::SpecialAttack(){
    cout << GetName() << " Scratches with you ferociously!" << endl;
    cout << GetName() << " deals 1 damage!";
    return 1;
}