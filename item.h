//
// Created by User on 17.04.2022.
//

#ifndef EXERCISESHEET4_ITEM_H
#define EXERCISESHEET4_ITEM_H

#include <string>
#include <iostream>
#include "exception.h"

class Item {

private:
    std:: string name;
    int gold;

public:

    Item(const std::string& name, int gold);
    Item();


//_________________Getter & Setter________________

    void setName(const std::string& name){
        if (!name.empty()){
            this->name = name;
        }
        else{
            throw InvalidArgumentException("Item::setName - ungueltiger Name");
        }
    }

    const std::string& getName() const{
        return this->name;
    }


    void setGold (int gold){
        if (gold >= 0){
            this->gold = gold;
        }
        else{
            throw InvalidValueException("Item::setGold() - ungueltiger Wert");
        }
    }

    int getGold () const{
        return this->gold;
    }

};

std::ostream& operator<<(std::ostream& out, const Item& item);

#endif //EXERCISESHEET4_ITEM_H
