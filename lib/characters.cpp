#include "characters.h"
#include <iostream>
#include <string>
namespace ErinGameTesting {


//Character::character(string nameC) : name(nameC){}
/*class Character {
    private:
        int money, health, mana, healthPotions, manaPotions, score;
        string name;*/
        int Character::getHealth(){
            return health;
        }
        int Character::getMoney(){
            return money;
        }
        int Character::getMana(){
            return mana;
        }
        int Character::getHealthPotions(){
            return healthPotions;
        }
        int Character::getManaPotions(){
            return manaPotions;
        }
        int Character::getScore(){
            return score;
        }
        std::string Character::getName(){
            return name;
        }
        void Character::changeMoney(int change){
            money += change;
            if (money <= 0){
                money = 0;
            }
        }
        void Character::changeHealth(int damage){
            health += damage;
            if (health < 0){
                health = 0;
            }
        }
        void Character::changeMana(int cost){
            mana += cost;
            if (mana < 0){
                mana = 0;
            }
        }
        void Character::changeHealthPotions(int stock){
            healthPotions += stock;
            if (healthPotions < 0){
                healthPotions = 0;
            }
        }
        void Character::changeManaPotions(int stock){
            manaPotions += stock;
            if (manaPotions < 0){
                manaPotions = 0;
            }
        }
        void Character::changeScore(int stock){
            score += stock;
        }
}