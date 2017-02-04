#ifndef BASEABILITY_H
#define BASEABILITY_H

#include <iostream>
#include "../units/Unit.h"

template <class Type>
class Unit;

template <class Type>
class BaseAbility {
    protected:
        Unit<Type>* owner;
    public:
        BaseAbility(Unit<Type>* owner);
        virtual ~BaseAbility();

        virtual void action(Unit<Type>* enemy);
};

#endif // BASEABILITY_H
