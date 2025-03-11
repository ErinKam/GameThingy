#include <iostream>
#include "time.h"
#include "characters.h"
using namespace std;
using namespace ErinGameTesting;

void chooseRoom(){
    int input = -1, roomnumbers;
    cout << "You are standing in a room with ";
    srand(time(NULL));
    roomnumbers = rand() % 4 + 1;
    cout << roomnumbers << " doors." << endl;
    while (input >= 0 && input <= roomnumbers){
        cout << "Choose which room to enter (ex: 1):" << endl;
        cin >> input;
        if (input <= 0 || input >= roomnumbers){
            cout << "You made an invalid choice." << endl;
        }
    }
};

void monsterRoom(Character* p){
    int option = 5;
    srand(time(NULL));
    int damage = rand() % 10;
    cout << "You find yourself in a room with monsters. With " << p->getHealth() << " health";
    while (option <= 2){
        int hPotion = p->getHealthPotions();
        int mPotion = p->getManaPotions(); 
        cout << "You have 4 options:" << endl;
        cout << "1. Use mana to destroy the monsters (you wont take damage, but will lose 1 mana) You have " << p->getMana() << "left." << endl;
        cout << "2. Fight the monsters and risk loosing health (the damage will be between 0-25)" << endl;
        cout << "3. Drink a Health Potion (this heals 25 damage) and you get another choice of option. (You have" << hPotion << ")" << endl;
        cout << "4. Drink a Mana Potion (this heals 2 mana) and you get another choice of option. (You have "<< mPotion << ")" << endl;
        cin >> option;
        if (option >= 5 || option <=0){
            cout << "You made an invalid choice" << endl;
            option = 5;
        }
        else if (option == 3){
            cout << "you drink a health potion!"<< endl;
            p->changeHealth(25);
            cout << "you now have " << p->getHealth() << " health" << endl; 
            p->changeHealthPotions(-1);
        }
        else if (option == 4){
            cout << "you drink a health potion!"<< endl;
            p->changeMana(25);
            cout << "you now have " << p->getMana() << " mana" << endl; 
            p->changeManaPotions(-1);
        }
    }
    if (option == 2){
        p->changeHealth(damage);
        cout << "You have taken " << damage << " damage." << endl;
    }
    int income = rand() % 10 + 1;
    p->changeMoney(income);
    cout << "You gained " << income << " coins" <<endl;
};

void chestRoom(Character* p){
    int income = rand() % 10;
    if (income == 10){
        income = 25;
    }

    char yn;
    cout << "You found a room with a chest!" << endl;
    cout << "Do you open it? [y|n]" << endl;
    cin >> yn;
    if (yn == 'y' && income == 0){
        cout << "You find:"<< endl;
        cout << "..." << endl << "nothing?";
    }
    else if (yn == 'y'){
        cout << "you find:" << endl;
        cout << "..." << endl << income << " coins!";
        p->changeMoney(income);
    }
    else {
        cout << "You dont open the chest... wierd..." << endl;
    }
};

void merchent(Character* p){
    srand(time(NULL));
    int healthPrice = rand() % 25 + 15;
    int manaPrice = rand() % 25 + 15;
    int input = 0;
    int coins = p->getMoney();
    cout << "You walk into a room with a mouse on what looks like a bar." << endl;
    cout << "He has a sign saying:" << endl;
    cout << "Health Potion Price: " << healthPrice << " coins" << endl;
    cout << "Mana Potions Price: " << manaPrice << " coins" << endl;
    if (coins < manaPrice && coins < healthPrice){
        cout << "too bad you are broke (" << coins << " coins)..." << endl;
        return;
    }
    while (input != 3){
        coins = p->getMoney();
        cout << "You have " << coins << " coins." << endl;
        cout << "What would you like: 1. health potion , 2. mana potion, 3. nothing." << endl;
        cin >> input;
        if (input <= 0 || input >= 4){
            cout << "invalid input." << endl;
            input = 0;
        }
        else if (input == 1 && coins >= healthPrice){
            cout << "You buy a health potion!" << endl;
            p->changeHealthPotions(1);
            p->changeMoney(-healthPrice);
        }
        else if (input == 1){
            cout << "you are too poor for this (the mouse looks sad)." << endl;
        }
        else if (input == 2 && coins >= manaPrice){
            cout << "You buy a mana potion!" << endl;
            p->changeManaPotions(1);
            p->changeMoney(-manaPrice);
        }
        else if (input == 2){
            cout << "you are too poor for this (the mouse looks sad)." << endl;
        }
    }
    cout << "The mouse scurries away." << endl;
};

bool lossManager(Character* p){
    if (p->getHealth() == 0){
        cout << "You died! After " << p->getScore() << " rooms." << endl;
        return true;
    }
    return false;
};

int roomEvent(Character* p){
    int randomNum;
    srand(time(NULL));
    randomNum = rand() % 10;
    if (randomNum <= 5){
        monsterRoom(p);
    }
    else if (randomNum == 6){
        cout << "The room is empty..." << endl;
    }
    else if (randomNum == 7 || randomNum == 8){
        chestRoom(p);
    }
    else {
        merchent(p);
    }
    bool chose;
    chose = lossManager(p);
    p->changeScore(1);
    if (chose){
        return -1;
    }
    cout << "You have now gone through " << p->getScore() << " rooms!" << endl;
    char c;
    cout << "Do you want to continue and risk loosing? [y|n]" << endl;
    cin >> c;
    if (c == 'y'){
        return 1;
    }
    else {
        return 2;
    }
};

void update(Character* p){
    int con;
    chooseRoom();
    con = roomEvent(p);
    if (con == 1){
        update(p);
    }
    else{
        cout << "Thank You for playing!!!" << endl;
    }
};

int main() {
    string pname;
    cout << "You are about to wake up." << '\n' << "What is your name?" << endl;
    cin >> pname;
    Character Player(pname);
    Character* p = &Player;
    update(p);
    return 0;
}