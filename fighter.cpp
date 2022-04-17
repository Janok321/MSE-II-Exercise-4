
#include "fighter.h"

void Fighter::attack(Character* enemy){ // Referenz & statt Pointer würde auch gehen
    int damage = 5 + (std::rand() % 6) + this->strength - enemy->getArmor();
    if (damage < 0){
        damage = 0;
    }
    std::cout << name << " trifft " <<enemy->getName()<< " fuer " << damage << " Lebenspunkte!" << std::endl; // this Pointer optional
    enemy->setHealth(enemy->getHealth() - damage);
}

std::ostream& operator<<(std::ostream& out, const Fighter& f){
    out << "Kaempfer " << f.getName();
    return out;
}

//_____________________Getter & Setter_________________________

int Fighter::getStrength() const {
    return strength;
}

void Fighter::setStrength(int strength) {
    if (strength >= 0){
        this->strength = strength;
    }
    else{
        throw InvalidValueException("fighter.cpp - setStrength() - ungültiger Wert");
    }
}
