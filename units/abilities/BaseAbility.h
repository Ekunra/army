#ifndef BASEABILITY_H
#define BASEABILITY_H

#include <iostream>
#include "../Unit.h"

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
        // virtual void bite(Unit<Type>* enemy, Unit<Type>* rodent);
        // virtual void transform(Unit<Type>* unit);
};

#endif // BASEABILITY_H
