#ifndef BASEATTACK_H
#define BASEATTACK_H

#include <iostream>
#include "../units/Unit.h"

template <class Type>
class Unit;

template <class Type>
class BaseAttack {
    public:
        BaseAttack();
        virtual ~BaseAttack();

        virtual void attack(Unit<Type>* attacker, Unit<Type>* enemy);
};

#endif // BASEATTACK_H
