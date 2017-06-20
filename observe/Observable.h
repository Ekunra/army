#ifndef OBSERVABLE_H
#define OBSERVABLE_H

#include <iostream>
#include <set>
#include "../units/Unit.h"
#include "../units/necromancer/Necromancer.h"

template <class Type> class Unit;
template <class Type> class Necromancer;

template <class Type>
class Observable {
    private:
        Unit<Type> *owner;
        std::set<Necromancer<Type>*>* observers;
        
    public:
        Observable(Unit<Type> *owner);
        virtual ~Observable();

        void attachObserver();
        void dettachObserver();
        void notifyObserver();
};

#endif // OBSERVABLE_H
