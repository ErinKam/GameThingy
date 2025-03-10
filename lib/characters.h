#ifndef CHARACTERS_H
#define CHARACTERS_H

#include <iostream>

namespace gameCharacter {

    class Character {
        private:
            int money, health, mana, healthPotions, manaPotions, score;
            std::string name;
        public:
            Character(std::string nameC);
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