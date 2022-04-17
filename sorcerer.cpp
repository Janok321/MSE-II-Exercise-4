
#include "sorcerer.h"

void Sorcerer::attack(Character* enemy){ //Pointer würde auch gehen
    int damage = 5 + (std::rand() % 6) + magicPower - enemy->getMagicResistance();
    if (damage < 0){
        damage = 0;
    }
    std::cout << *this << " trifft " <<enemy->getName()<< " fuer " << damage << " Lebenspunkte!" << std::endl;
    enemy->setHealth(enemy->getHealth() - damage);
}

int Sorcerer::getMagicPower() const {
    return magicPower;
}

void Sorcerer::setMagicPower(int magicPower) {
    if(magicPower > 0){
        this->magicPower = magicPower;
    }
    else{
        throw InvalidValueException("Sorcerer::setMagicPower() ungueltiger Wert");
    }
}

std::ostream& operator<<(std::ostream& out, const Sorcerer& s){
    out << "Zauberer " << s.getName();
    return out;
}
