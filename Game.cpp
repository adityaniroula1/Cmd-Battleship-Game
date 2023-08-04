//Title: Game.cpp
//Author : Aditya Niroula
//Date : 11/18/2022
//Desc : Game file

#include "Game.h"
#include <iostream>
#include <ctime>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;

// Name: Game() - Default Constructor
// Description: Creates a new Game
// Preconditions: None
// Postconditions: Initializes all game variables to defaults (constants)
// including rests, specials, curArea, filename, curZerg (nullptr), and starting wins
Game::Game(){
    m_curArea = START_AREA;
    m_curZerg = nullptr;
    m_filename = FILE_NAME;
    m_wins = START_WINS;
    m_numRests = NUM_RESTS;
    m_myTerran = nullptr;
    m_numSpecial = NUM_SPECIAL;
}
// Name: Game(string filename) - Overloaded Constructor
// Description: Creates a new Game
// Preconditions: None
// Postconditions: Initializes all game variables to defaults (constants)
//                 including rests, specials, curArea, filename (from passed variable),
//                 curZerg (nullptr), and starting wins
Game::Game(string filename){
    m_filename = filename;
    m_curArea = START_AREA;
    m_curZerg = nullptr;
    m_wins = START_WINS;
    m_numRests = NUM_RESTS;
    m_myTerran = nullptr;
    m_numSpecial = NUM_SPECIAL;

}
// Name: ~Game
// Description: Destructor
// Preconditions: None
// Postconditions: Deallocates anything dynamically allocated in Game (terran, zergs, and map)
Game::~Game(){
    //looping through vector and deallocating each object
    for(int i=0; i < m_myMap.size(); i++){
        delete m_myMap[i];
    }
    //deallocating terran and zerg
    delete m_myTerran;
    delete m_curZerg;

}
// Name: LoadMap()
// Description: Dynamically creates areas and inserts them into the m_myMap vector
// Note: the size of the map is not known - you should not use constants for this.
//       Also, you can use stoi to convert strings to integers
// Precondition: m_filename is populated
// Postcondition: Map is populated with area objects.
void Game::LoadMap(){
    string num;
    string name;
    string desc;
    string n, e, s, w;
    int id, north, east, south, west;
    //reading the file with delimiters
    ifstream inputFile;
    inputFile.open(FILE_NAME);
    if (inputFile.is_open()) {
        int count = 0;
        string line;
        while (getline(inputFile, num, DELIMITER) &&
            getline(inputFile, name, DELIMITER) &&
            getline(inputFile, desc, DELIMITER) &&
            getline(inputFile, n, DELIMITER) &&
            getline(inputFile, e, DELIMITER) &&
            getline(inputFile, s, DELIMITER) &&
            getline(inputFile, w, '\n')     ){  //TA
            //converting stringto int
            id = stoi(num);
            north = stoi(n);
            east = stoi(e);
            south = stoi(s);
            west = stoi(w);
            //populating vector with new areas
            Area *newArea = new Area(id, name, desc, north, east, south, west);
            m_myMap.push_back(newArea);
        }
        m_curArea = m_myMap[0]->GetID();
        inputFile.close();

    }
}
// Name: TerranCreation()
// Description: Allows user to choose a new terran (or child) to play with. May
//              be either Terran, Marine, Ghost, or Battlecruiser.
// Preconditions: None
// Postconditions: m_myTerran is populated
void Game::TerranCreation(){
    int input = 0;
    while (input < 1 or input > 4) {
        cout << "Terran Name: JD" << endl;
        cout << "Select a class" << endl;
        cout << "1. Marine" << endl;
        cout << "2. Ghost" << endl;
        cout << "3. Battlecruiser" << endl;
        cout << "4. No Class " << endl;
        cin >> input;
    }
    //creating terran according to user choice
    if (input == 1) {
        m_myTerran = new Marine("JD", MARINE_HEALTH);
    }else if (input == 2){
        m_myTerran = new Ghost("JD", GHOST_HEALTH);
    }else if(input == 3){
        m_myTerran = new Battlecruiser("JD", BATTLECRUISER_HEALTH);
    }else if(input == 4){
        m_myTerran = new Terran("JD", TERRAN_HEALTH);
    }


}
// Name: StartGame()
// Description: Welcomes the player to the game. Calls LoadMap, TerranCreation,
//              prints the current area then calls action
// Preconditions: Input file must exist
// Postconditions: Map is loaded, User has chosen a terran to play with,
//                 printed the starting area, and calls action
void Game::StartGame(){
    //main game function
    cout << "Welcome to UMBC Starcraft!" << endl;
    LoadMap();
    TerranCreation();
    m_myMap[m_curArea]->PrintArea();
    Action();

}
// Name: Action()
// Description: Menu for game. Calls RandomZerg for current location then displays menu.
//              Player can look, move, attack, rest, stats, or quit
//              If player moves, clears out the m_curZerg and sets m_curZerg = RandomZerg
//              If player looks, will NOT display zerg again (as this is a function of moving)
//              Can only attack if there is actually a zerg in this area
// Preconditions: Everything in start has been completed
// Postconditions: Game continues until quit or player dies
void Game::Action(){
    m_curZerg = RandomZerg();
    int input = 0;
    while (input != 6 and m_myTerran->GetHealth() > 0) {
        cout << "What would you like to do?" << endl;
        cout << "1. Look" << endl;
        cout << "2. Move" << endl;
        cout << "3. Attack Zerg" << endl;
        cout << "4. Rest" << endl;
        cout << "5. Check Stats" << endl;
        cout << "6. Quit" << endl;
        cin >> input;
        while (input < 1 or input > 6) {
            cout << "What would you like to do?" << endl;
            cout << "1. Look" << endl;
            cout << "2. Move" << endl;
            cout << "3. Attack Zerg" << endl;
            cout << "4. Rest" << endl;
            cout << "5. Check Stats" << endl;
            cout << "6. Quit" << endl;
            cin >> input;
        }
        //calling different funtion according touser choice
        if (input == 2){
            delete m_curZerg;
            //m_curZerg = nullptr;
            //m_curZerg = RandomZerg();
            Move();
            m_curZerg = RandomZerg();
        }else if(input == 3){
            if (m_curZerg != nullptr) {
                Attack();
            }
        }else if(input == 4){
            //if zerg is dead, makes mcurzerg a null pointer
            if (m_curZerg->GetHealth() <=0 ){
                m_curZerg = nullptr;
            }
            Rest();
        }else if(input == 5){
            Stats();
        }else if(input == 1){
            m_myMap[m_curArea]->PrintArea();
        }
    }
    cout << "Goodbye!";

}
// Name: RandomZerg()
// Description: Used to randomly create a dynamically allocated zerg
//              (25% chance of nothing, 25% chance of Zergling, Mutalisk, or Hydralisk.)
//              When chosen, displays the description
//              of the zerg or displays "It is peaceful here."
// Preconditions: Has an entity pointer to hold zerg child or nullptr
// Postconditions: Returns object of type Zergling, Mutalisk, Hydralisk, or nullptr
Entity* Game::RandomZerg(){
    Entity* newZerg;
    srand(time(0));
    int a = (rand() % 4) + 1;
    //randomly dynamically allocating zerg and returning their object
    if (a == 1){
        newZerg = new Zergling("Zergling", ZERGLING_HEALTH);
        cout << "A small terrifying zergling waits here." << endl;
        return newZerg;
    }else if(a == 2){
        newZerg = new Mutalisk("Mutalisk", MUTALISK_HEALTH);
        cout << "A large flying mutalisk hovers here." << endl;
        return newZerg;
    }else if(a == 3){
        newZerg = new Hydralisk("Hydralisk", HYDRALISK_HEALTH);
        cout << "A large flying mutalisk hovers here." << endl;
        return newZerg;
    }else if(a == 4){
        cout << "It is peaceful here." << endl;
        return nullptr;
    }
}
// Name: Rest
// Description: If no zerg in current area, allows player to rest
// Preconditions: Must be valid area with no zerg (area must exist) and have rests
// Postconditions: Reduces available rests by one and increases hp by 10
//                 using REST_HEAL (regardless of starting value)
void Game::Rest(){
    //only works if user has rest available and if there's no zerg in that area
    if (m_numRests >= 1) {
        if (m_curZerg == nullptr) {
            m_numRests--;
            int hp = m_myTerran->GetHealth();
            hp += REST_HEAL;
            m_myTerran->SetHealth(hp);
            m_numSpecial = 3;
            cout << "You rest and wake up refreshed" << endl;
        } else {
            cout << "You cannot rest with a zerg in the area." << endl;
        }
    }else{
        cout << "You don't have any rest action" << endl;
    }

}
// Name: Move
// Description: Asks a player which direction they would like to move.
//              Moves player from one area to another (updates m_curArea)
// Preconditions: Must be valid move (area must exist)
// Postconditions: Displays area information
void Game::Move(){
    //check if theres anywhere to move
    char direction;
    cout << "Which direction? (N E S W)" << endl;
    cin >> direction;
    int id = m_myMap[m_curArea]->CheckDirection(direction);

    while(id == -1){
        cout << "Which direction? (N E S W)" << endl;
        cin >> direction;
        id = m_myMap[m_curArea]->CheckDirection(direction);
    }
    m_curArea = id;
    m_myMap[m_curArea]->PrintArea();
    m_curArea = m_myMap[id]->GetID();
}
// Name: Attack
// Description: Allows player to attack an enemy entity.
// Preconditions: Must have enemy Zerg in area
// Postconditions: Indicates who wins and updates health(hp) as battle continues.
//                 Both Terran and Zerg attack every round until one or more has <= 0 health
//                 May need to deallocate enemy Zerg to prevent memory leaks.
//                 When either Zerg or Terran <= 0 health, calls ProcessBattle
void Game::Attack(){
    //cout << *m_curZerg << endl;
    while (m_curZerg->GetHealth() > 0 and m_myTerran->GetHealth() > 0) {
        if (m_curZerg != nullptr) {
            //cout << "Entered attack";
            int input = 0;
            while ((input < 1 or input > 2)) {
                cout << "1. Normal Attack\n"
                        "2. Special Attack" << endl;
                cin >> input;
            }
            bool flag = true;
            if (m_numSpecial <= 0 and input == 2){
                flag = false;
            }
            if (input == 1) {
                //deducting health accoring to kind of attack for zerg
                int damage = m_myTerran->Attack();
                m_curZerg->SetHealth(m_curZerg->GetHealth() - damage);

            } else if (input == 2 and flag){
                int damage = m_myTerran->SpecialAttack();
                m_curZerg->SetHealth(m_curZerg->GetHealth() - damage);
                m_numSpecial--;
            }
            if(flag) {
                //randomly decreasing health of user based on percentage
                srand(time(0));
                int a = (rand() % 4) + 1;
                if (a == 1 or a == 2 or a == 3) {
                    int damage = m_curZerg->Attack();
                    m_myTerran->SetHealth(m_myTerran->GetHealth() - damage);
                } else if (a == 4) {
                    int damage = m_curZerg->SpecialAttack();
                    m_myTerran->SetHealth(m_myTerran->GetHealth() - damage);
                }
            }
            //calling processbattle if either one or both dies
            if (m_curZerg->GetHealth() <= 0 and m_myTerran->GetHealth() <= 0) {
                ProcessBattle(0, 0);
            } else if (m_myTerran->GetHealth() <= 0) {
                ProcessBattle(1, 0);
            } else if (m_curZerg->GetHealth() <= 0) {
                //delete m_curZerg;     this is creating many segfaults
                ProcessBattle(0, 1);
            } else if(m_curZerg->GetHealth() > 0 and m_myTerran->GetHealth() > 0 and m_numSpecial > 0){
                //call friend functionn if no one dies
                cout << *m_curZerg << endl;
                cout << *m_myTerran << endl;
            }else{
                cout << "No special attack left." << endl;
            }
        } else {
            cout << "No zerg to attack" << endl;
        }
    }
}
// Name: Stats()
// Description: Displays the information about the player (name, hp, rests, specials, and wins)
// Preconditions: None
// Postconditions: None
void Game::Stats(){
    //printing the stats of player
    cout << "Name: JD" << endl;
    cout << "HP:"  << m_myTerran->GetHealth() << endl;
    cout << "Rests: " << m_numRests << endl;
    cout << "Special:" << m_numSpecial << endl;
    cout << "Wins: " << m_wins << endl;
}
// Name: ProcessBattle
// Description: Called when either the zerg or terran have no health left
//       Displays who won (Zerg, Terran, mutual destruction), adds wins if necessary,
//       and has a 10% chance of earning another rest action.
// Preconditions: Zerg or terran are <= 0 health
// Postconditions:
void Game::ProcessBattle(bool zergAlive, bool alive){
    if(alive){
        m_wins++;
        srand(time(0));
        int a = (rand() % 9) + 1;
        //increasing rest action according to random value
        if(a == 1){
            cout << "You earned a rest action" << endl;
            m_numRests++;
        }
        cout << "You have defeated the " << m_curZerg->GetName() << endl;
    }else if(zergAlive){
        cout << m_curZerg->GetName() << " defeated you." << endl;
    }else{
        cout << "Both died" << endl;
    }
}