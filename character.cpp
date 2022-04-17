
#include "character.h"
#include <iostream>

Character::Character(const std::string& name, int health, int gold, int armor,
                     int magicResistance)
        : name(name), health (health), gold(gold), armor(armor), magicResistance(magicResistance), inventory(){
    if (name.length() < 0){
        throw InvalidArgumentException("Character::Character() - ungueltiger Name");
    }
    if (health < 0 || gold < 0 || armor < 0 || magicResistance < 0){
        throw InvalidValueException("Character::Character() - ungueltiger Wert");
    }
}



int Character::addInventarItem(Item* item){     //Funktion fügt Gegenstand hinzu, wenn an der Indexstelle noch keiner vorhanden
    if (item){
        for (int i = 0; i < CHARACTER_INVENTORY_SIZE; i++) {
            if(!inventory[i]){
                inventory[i] = item;
                return i;
            }
        }
        throw InventoryFullException("Character::addInventarItem - Inventar voll");
    }
    throw InvalidItemException("character.cpp - addInventarItem - fehlerhaftes Item");
}

Item* Character::removeInventarItem(int slot){
    if( slot >= 0 && slot < CHARACTER_INVENTORY_SIZE){
        Item *retval = inventory[slot];
        return retval;
    }
    else {
        throw InvalidIndexException("character.cpp - removeInventarItem - fehlerhafter Slot");
    }
}

std::ostream& operator<<(std::ostream& out, const Character& ch) {
    out << ch.getName();
    return out;
}
