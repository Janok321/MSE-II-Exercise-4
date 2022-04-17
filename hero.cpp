
#include <iostream>
#include <cstdlib>
#include "hero.h"
#include "npc.h"

Hero::Hero(const std::string&name, int health, int gold, int armor, int magicResistance)
        : Character(name, health, gold, armor, magicResistance), gear(){}

//Die Heldin greift einen spezifizierten Gegner an und reduziert dessen Lebenspunkte zufällig um einen Wert
// zwischen 15 und 25
void Hero::attack(Character* enemy){ //Pointer würde auch gehen
    int damage = 15 + std::rand() % 11 - enemy-> getArmor();
    if (damage < 0){
        damage = 0;
    }
    std::cout << *this << " trifft " << *enemy<< " fuer " << damage << " Lebenspunkte!" << std::endl;
    enemy->setHealth(enemy->getHealth() - damage);
}


void Hero::sellItem(int index){
    if (index >= 0 && index < CHARACTER_INVENTORY_SIZE) {
        if (inventory[index]) {
            gold+= inventory[index]->getGold();        //this->gold+= this->inventory[index].getGold();
            std::cout << "Gegenstand " << inventory[index]->getName() << " wurde verkauft. "; // geht auch nur inventory[index]
            std::cout << *this << " besitzt nun " << gold << " Gold." << std::endl; // Warum *this und nicht name?
            inventory[index] = nullptr;
        }
    }
}


int Hero::addGearItem(Item* item){
    if (item){
        for (int i = 0; i < HERO_GEAR_SIZE; i++) {
            if(!gear[i]) {
                gear[i] = item;
                return i;
            }
        }
        throw GearFullException("Hero::addGearItem - kein Platz mehr");
    }
    else {
        throw InvalidItemException("Hero::addGearItem - ungueltiges Item");
    }
}

bool Hero:: fight(NPC* enemy){
    while(health > 0 && enemy->getHealth() > 0){
        attack(enemy);
        if (enemy->getHealth() > 0){
            enemy->attack(this);
        }
    }
    if (health > 0){
        std::cout << *enemy << "fiel in Ohnmacht!" << name <<" hat noch "<< health << " Lebenspunkte uebrig!" << std::endl;
        Item* item = enemy-> retrieveRandomLoot();
        if (addInventarItem(item) < 0){
            throw InventoryFullException("Hero::fight - Inventory ist voll");
        }
        else{
            std::cout << *item << " wurde zum Inventar von " <<*this << "hinzugefuegt." << std::endl;
        }
    }
    return health > 0;
}


Item* Hero::removeGearItem(int slot){
    if(slot >= 0 && slot < HERO_GEAR_SIZE){
        Item* retval = gear[slot];
        gear[slot] = nullptr;
        return retval;
    }
    else{
        throw InvalidIndexException("Hero::removeGearItem() - ungueltiger Slot");
    }
}


std:: ostream& operator<<(std::ostream& out, const Hero& hero){
    out << "Heldin " << hero.getName();
    return out;
}