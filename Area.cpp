#include "Area.h"
#include <iostream>
#include <string>
using namespace std;

//Name: Area (Overloaded Constructor)
//Precondition: Must have valid input for each part of a area
// First int is the unique identifier for this particular area.
// The first string is the name of the area
// The second string is the description of the area
// The last four ints are the unique identifier for adjacent areas (-1 = no path)
// North, East, South, and West
//Postcondition: Creates a new area
Area::Area(int id, string name, string desc, int n, int e, int s, int w){
    m_desc = desc;
    m_name = name;
    m_ID = id;
    m_direction[0] = n;
    m_direction[1] = e;
    m_direction[2] = s;
    m_direction[3] = w;

}
//Name: GetName
//Precondition: Must have valid area
//Postcondition: Returns area name as string
string Area::GetName(){
    return m_name;
}
//Name: GetID
//Precondition: Must have valid area
//Postcondition: Returns area id as int
int Area::GetID(){
    return m_ID;
}
//Name: GetDesc
//Precondition: Must have valid area
//Postcondition: Returns area desc as string
string Area::GetDesc(){
    return m_desc;
}
//Name: CheckDirection
//Precondition: Must have valid area
//You pass it a char (N/n, E/e, S/s, or W/w) and if that is a valid exit it
//returns the ID of the area in that direction
//Postcondition: Returns id of area in that direction if the exit exists
//If there is no exit in that direction, returns -1
int Area::CheckDirection(char myDirection){
    //validating if exit exits in that direction
    if (myDirection == 'n' or myDirection == 'N'){
        if (m_direction[0] != -1){
            return m_direction[0];
        }else{
            return -1;
        }
    }else if (myDirection == 'e' or myDirection == 'E'){
        if (m_direction[1] != -1){
            return m_direction[1];
        }else{
            return -1;
        }
    }else if (myDirection == 's' or myDirection == 'S'){
        if (m_direction[2] != -1){
            return m_direction[2];
        }else{
            return -1;
        }
    }else if (myDirection == 'w' or myDirection == 'W'){
        if (m_direction[3] != -1){
            return m_direction[3];
        }else{
            return -1;
        }
    }else{
        return -1;
    }
}
//Name: PrintArea
//Precondition: Area must be complete
//Postcondition: Outputs the area name, area desc, then possible exits
void Area::PrintArea(){
    cout << m_name << endl;
    cout << m_desc << endl;
    //prints the possible exits
    for(int i = 0; i < 4; i++){
        if (m_direction[i] != -1){
            if(i == 0){
                cout << "Possible Exit: N " << endl;
            }else if(i == 1){
                cout << "Possible Exit: E " << endl;
            }else if(i == 2){
                cout << "Possible Exit: S " << endl;
            } else if(i == 3){
                cout << "Possible Exit: W " << endl;
            }
        }
    }

}