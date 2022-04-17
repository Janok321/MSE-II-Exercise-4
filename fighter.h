

#ifndef EXERCISESHEET4_FIGHTER_H
#define EXERCISESHEET4_FIGHTER_H

#include "npc.h"
#include <iostream>

class Fighter : public NPC {

protected:
    int strength;

public:
    Fighter(const std::string &name, int health, int gold, int armor, int magicResistance, int strength)
            : NPC(name, health, gold, armor, magicResistance), strength(strength){
        if (strength < 0){
            throw InvalidValueException("Fighter::Fighter() - ungueltiger Strength Wert");
        }
    }

    //virtual ~Fighter(){}  in Jane Musterlösung vergessen? Oder brauch man keinen weil Vererbung?

    virtual void attack(Character* enemy) override;

// ________________Getter & Setter________________________

    int getStrength() const;
    void setStrength(int strength);
};

std::ostream& operator<<(std::ostream& out, const Fighter& f);


#endif //EXERCISESHEET4_FIGHTER_H
