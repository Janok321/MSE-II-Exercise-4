//
// Created by User on 17.04.2022.
//

#ifndef EXERCISESHEET4_CHARACTER_H
#define EXERCISESHEET4_CHARACTER_H

#include <string>
#include "item.h"
#include "exception.h"


#define CHARACTER_INVENTORY_SIZE 10


class Character {

protected:
    std::string name;
    int health;
    int gold;
    int armor;
    int magicResistance;
    Item* inventory[CHARACTER_INVENTORY_SIZE];

public:

    Character (const std::string &name, int health, int gold,
               int armor, int magicResistance);

    virtual ~Character(){
        for (int i = 0; i < CHARACTER_INVENTORY_SIZE; i++){
            delete inventory[i];
        }
    }


    virtual void attack(Character* enemy) = 0;


    int addInventarItem(Item* item);

    Item* removeInventarItem(int slot);



// ______________________________Getter & Setter_______________________________________________

    const std::string& getName() const {
        return this->name; // this Pointer optional
    }

    void setName (const std::string &_name){
        if(!_name.empty()){
            this->name = _name;
        }
        else{
            throw InvalidArgumentException("character.h - setName() - ungueltiger Name");
        }
    }

    void setHealth(int health){
        if (health < 0){
            this->health = 0;
        }
        else {
            this->health = health; // this Pointer mandatory, da sonst Überschattung
        }
    }

    int getHealth() const{
        return this->health; //this Pointer optional, da keine Überschattung
    }

    Item* getInventory(int slot){
        if (slot >= 0 && slot < CHARACTER_INVENTORY_SIZE){
            return inventory[slot];
        }
        else {
            return nullptr;
        }
    }

    int getGold() const{
        return gold;
    }

    void setGold(int gold){
        if (gold >= 0){
            this->gold = gold;
        }
        else{
            throw InvalidValueException("character.h - setGold() - ungueltiger Wert");
        }
    }

    int getArmor() const {
        return armor;
    }

    void setArmor(int armor) {
        if (armor >= 0) {
            this->armor = armor;
        }
        else{
            throw InvalidValueException("character.h - setArmor() - ungueltiger Wert");
        }
    }

    int getMagicResistance() const {
        return magicResistance;
    }

    void setMagicResistance(int _magicResistance) {
        if (magicResistance >= 0){
            this->magicResistance = _magicResistance;
        }
        else{
            throw InvalidValueException("character.h - setMagicResistance - ungueltiger Wert");
        }
    }

};

std::ostream& operator<<(std::ostream& out, const Character& ch);


#endif //EXERCISESHEET4_CHARACTER_H
