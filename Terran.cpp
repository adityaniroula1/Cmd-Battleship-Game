#include "Terran.h"
#include <iostream>
#include <string>
using namespace std;


// Name: Terran() - Default Constructor
// Description: Creates a new terran
// Preconditions: None
// Postconditions: Can create a terran
Terran::Terran():Entity(){

}
// Name: Terran(string name, int hp) - Overloaded constructor
// Description: Creates a new terran
// Preconditions: None
// Postconditions: Can be used to populate terran or child classes
Terran::Terran(string name, int hp):Entity(name, hp){

}
// Name: ~Terran - Virtual Destructor
// Description: Makes sure everything in child class is deallocated
// Preconditions: None
// Postconditions: Everything dynamically allocated is deallocated
Terran::~Terran(){

}
// Name: Attack()
// Description: Describes attack statements for terran
// Preconditions: None
// Postconditions: Returns damage
int Terran::Attack(){
    srand(time(0));
    int a = (rand() % 6) + 1;
    cout << GetName() << " deals" << a << "point of damage!" << endl;
    return a;
}
// Name: SpecialAttack()
// Description: Tells player that terran does not have special attack
// may be used for child class special attacks
// Preconditions: None
// Postconditions: May be used to call child class SpecialAttack
int Terran::SpecialAttack(){
    cout << GetName() << " deals N/A point of damage!" << endl;
    return 0;
}