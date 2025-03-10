#include <iostream>
#include "time.h"
#include "characters.h"
using namespace std;

int chooseRoom(){
    int input, roomnumbers;
    cout << "You are standing in a room with ";
    srand(time(NULL));
    roomnumbers = rand() % 4 + 1;
    cout << roomnumbers << " doors." << endl;
    cout << "Choose which room to enter (ex: 1):" << endl;
    scanf("%i", input);
    return input;
}

int roomEvent(int in){
    int randomNum;
    srand(time(NULL));
    randomNum = rand() % 10;
}

void update(){
    int roomNum;
    roomNum = chooseRoom();
    

}

int main() {
    update();
    return 0;
}