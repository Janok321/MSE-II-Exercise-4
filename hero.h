//
// Created by User on 17.04.2022.
//

#ifndef EXERCISESHEET4_HERO_H
#define EXERCISESHEET4_HERO_H

#include <string>
#include "item.h"
#include "character.h"
#include <iostream>

#define HERO_GEAR_SIZE 2

class NPC; //Forward Declaration --> Warum?


class Hero : public Character{
protected:
    Item* gear[HERO_GEAR_SIZE];


public:
    Hero(const std:: string&name, int health, int gold, int armor, int magicResistance);
    // ? Warum nicht --> using Character::Character?; --> würde mMn auch gehen

    virtual ~Hero() {
        std::cout << *this << " verabschiedet sich und reitet in den Sonnenuntergang" <<std::endl;
        for (int i = 0; i <HERO_GEAR_SIZE; i++){
            delete gear[i];

        }
    }

    virtual void attack(Character* enemy) override;

    bool fight (NPC* enemy);

    void sellItem(int index);


    int addGearItem(Item* item);

    Item* removeGearItem(int slot);

};

std::ostream& operator<<(std::ostream& out, const Hero& hero);

#endif //EXERCISESHEET4_HERO_H
