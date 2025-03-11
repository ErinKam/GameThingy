#include "characters.h"
using namespace ErinGameTesting;

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
            if (money <= 0){
                money = 0;
            }
        }
        void changeHealth(int damage){
            health += damage;
            if (health < 0){
                health = 0;
            }
        }
        void changeMana(int cost){
            mana += cost;
            if (mana < 0){
                mana = 0;
            }
        }
        void changeHealthPotions(int stock){
            healthPotions += stock;
            if (healthPotions < 0){
                healthPotions = 0;
            }
        }
        void changeManaPotions(int stock){
            manaPotions += stock;
            if (manaPotions < 0){
                manaPotions = 0;
            }
        }
        void changeScore(int stock){
            score += stock;
        }
};