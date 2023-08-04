#include "Entity.h"
#include <iostream>
#include <string>
using namespace std;

// Name: Entity() - Default Constructor
// Description: Abstract class - cannot directly instantiate this class
// Preconditions: None
// Postconditions: Populates variables used in child classes (may not be specifically used)
Entity::Entity(){
    m_health = 0;
    m_name = "name";

}
// Name: Entity(string name , int health) - Overloaded Constructor
// Description: Abstract class - cannot directly instantiate this class
// Preconditions: None
// Postconditions: Populates variables used in child classes
Entity::Entity(string name, int health){
    m_name = name;
    m_health = health;
}
// Name: virtual ~Entity - Virtual Destructor
// Description: Makes sure everything in child class is deallocated
// Preconditions: None
// Postconditions: Everything dynamically allocated is deallocated
Entity:: ~Entity(){

}
// Name: GetName()
// Description: Returns name of entity
// Preconditions: Entity has name
// Postconditions: None
string Entity::GetName(){
    return m_name;
}
// Name: GetHealth()
// Description: Returns health of entity
// Preconditions: Entity has health
// Postconditions: None
int Entity::GetHealth(){
    return m_health;
}
// Name: SetName()
// Description: Sets name of entity
// Preconditions: None
// Postconditions: Name is set
void Entity::SetName(string name){
    m_name = name;
}
// Name: SetHealth()
// Description: Sets health of entity
// Preconditions: None
// Postconditions: Health is set
void Entity::SetHealth(int health){
    m_health = health;
}

//virtual int SpecialAttack() = 0;     only on child classes
// Name: Overloaded <<
// Description: Prints the details of an entity
// Preconditions: all variables are set valid
// Postconditions: returns an ostream with output of entity

ostream& operator<<(ostream& output, Entity& myEntity){
    output << myEntity.m_name << "'s health : " << myEntity.m_health ;
    return output;
}
