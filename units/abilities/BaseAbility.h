#ifndef BASEABILITY_H
#define BASEABILITY_H

#include <iostream>
#include "../Unit.h"

template <class Type>
class Unit;

template <class Type>
class BaseAbility {
    public:
        BaseAbility();
        virtual ~BaseAbility();

        virtual void bite(Unit<Type>* enemy, Unit<Type>* rodent);
        virtual void transform(Unit<Type>* unit);
};

#endif // BASEABILITY_H
