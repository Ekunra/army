#ifndef OBSERVABLE_H
#define OBSERVABLE_H

#include <iostream>
#include "../units/Unit.h"

template <class Type> class Unit;

template <class Type>
class Observable {
    private:
        Unit<Type> *owner;
        
    public:
        Observable(Unit<Type> *owner);
        virtual ~Observable();

        virtual void attachObserver();
        virtual void dettachObserver();
        virtual void notifyObserver();
};

#endif // OBSERVABLE_H
