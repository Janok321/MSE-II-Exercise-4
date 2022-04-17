
#ifndef EXERCISESHEET4_SORCERER_H
#define EXERCISESHEET4_SORCERER_H

#include "npc.h"
#include <iostream>

class Sorcerer : public NPC{

protected:
    int magicPower;

public:

    Sorcerer(const std::string &name, int health, int gold, int armor, int magicResistance, int magicPower)
            : NPC(name, health, gold, armor, magicResistance), magicPower(magicPower){}


    //virtual ~Sorcerer(){} Brauch man nicht, da der Destruktor vererbt wird

    virtual void attack(Character* enemy) override;

//_____________Getter & Setter________________
    int getMagicPower() const;

    void setMagicPower(int magicPower);

};

std::ostream& operator<<(std::ostream& out, const Sorcerer& s);



#endif //EXERCISESHEET4_SORCERER_H
