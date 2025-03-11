#ifndef CHARACTERS_H
#define CHARACTERS_H

#include <iostream>
#include <string>
namespace ErinGameTesting{
class Character {
        private:
            int money;
            int health;
            int mana;
            int healthPotions;
            int manaPotions;
            int score;
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
            };
            int getHealth();
            int getMoney();
            int getMana();
            int getHealthPotions();
            int getManaPotions();
            int getScore();
            std::string getName();
            void changeMoney(int change);
            void changeHealth(int damage);
            void changeMana(int cost);
            void changeHealthPotions(int stock);
            void changeManaPotions(int stock);
            void changeScore(int stock);
};
}
#endif