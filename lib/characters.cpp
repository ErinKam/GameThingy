#include "characters.h"
using namespace gameCharacter;

class Character {
    private:
        int money, health, mana, healthPotions, manaPotions, score;
        std::string name;
    public:
        Character(std::string nameC){
            name = nameC;
            money = 0;
            health = 100;
            mana = 5;
            healthPotions = 0;
            manaPotions = 0;
            score = 0;
        }
        int getHealth(){
            return health;
        }
        int getMoney(){
            return money;
        }
        int getMana(){
            return mana;
        }
        int getHealthPotions(){
            return healthPotions;
        }
        int getManaPotions(){
            return manaPotions;
        }
        int getScore(){
            return score;
        }
        std::string getName(){
            return name;
        }
        void changeMoney(int change){
            money += change;
        }
        void changeHealth(int damage){
            health += damage;
        }
        void changeMana(int cost){
            mana += cost;
        }
        void changeHealthPotions(int stock){
            healthPotions += stock;
        }
        void changeManaPotions(int stock){
            manaPotions += stock;
        }
        void changeScore(int stock){
            score += stock;
        }
};