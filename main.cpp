#include <cstdlib>
#include <ctime>
#include <iostream>
#include "hero.h"
#include "sorcerer.h"
#include "fighter.h"


int main() {
    std::srand(time(0));

    try{
        Hero heldin("Annina", 300, 100, 10, 5);

        Sorcerer pascal("Pascal", 50, 10000, 100, 5, 15);
        pascal.addInventarItem(new Item("Diamand", 1000));
        pascal.addInventarItem(new Item ("Zauberstab", 100));
        pascal.addInventarItem(new Item ("Zauberrobe", 200));

        Fighter matthias("Matthias", 100, 1000, 10, 5, 15);
        matthias.addInventarItem(new Item("Rubin", 800));
        matthias.addInventarItem(new Item("Schwert", 100));
        matthias.addInventarItem(new Item("Ruestung", 200));

        if (heldin.fight(&pascal)) {
            heldin.fight(&matthias);
        }

        if (heldin.getHealth() > 0) {
            for (int i = 0; i < CHARACTER_INVENTORY_SIZE; i++) {
                heldin.sellItem(i);
            }
        }

    }
    catch(std::exception &e){
        std::cerr << "Exception in main caught" << e.what() << std::endl;
    }

}

