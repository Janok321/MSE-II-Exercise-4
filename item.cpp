
#include "item.h"

Item::Item(const std::string& name, int gold)
        : name(name), gold(gold){
    if (name.length() <= 0){
        throw InvalidArgumentException("Item::Item() - ungültiger Name");
    }
    if (gold < 0){
        throw InvalidValueException("Item::Item - ungueltiger Wert");
    }
}

Item::Item()
        : gold(0){}

std:: ostream& operator<<(std::ostream& out, const Item& item){
    out << "Gegenstand " << item.getName();
    return out;
}