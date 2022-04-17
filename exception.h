//
// Created by User on 17.04.2022.
//

#ifndef EXERCISESHEET4_EXCEPTION_H
#define EXERCISESHEET4_EXCEPTION_H


#include <stdexcept>

class GameException : public std::runtime_error {
public:
    using std::runtime_error::runtime_error;
};

class InvalidIndexException : public GameException { // Fehlerhafter Index wird übergeben
public:
    using GameException::GameException;
};

class InventoryFullException : public GameException { // Inventar des Charakters ist voll
public:
    using GameException::GameException;
};

class GearFullException : public GameException { // Ausrüstung der Heldin ist voll
public:
    using GameException::GameException;
};

class InvalidItemException : public GameException { //Fehlerhaftes Item
public:
    using GameException::GameException;
};

class InvalidValueException : public GameException { // Fehlerhafter Wert wird übergeben
public:
    using GameException::GameException;
};

class InvalidArgumentException : public GameException { // Fehlerhaftes Argument wird übergeben
public:
    using GameException::GameException;
};


#endif //EXERCISESHEET4_EXCEPTION_H
