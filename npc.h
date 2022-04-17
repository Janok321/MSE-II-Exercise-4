
#ifndef EXERCISESHEET4_NPC_H
#define EXERCISESHEET4_NPC_H

#include "character.h"
#include "item.h"

class NPC : public Character{

public:
    using Character::Character;

    virtual ~NPC() {
        std::cout << "Der Boesewicht " << *this <<  " fluechtet zurueck zum Schicksalsberg" <<std::endl;
    }

    Item* retrieveRandomLoot();

};


#endif //EXERCISESHEET4_NPC_H
