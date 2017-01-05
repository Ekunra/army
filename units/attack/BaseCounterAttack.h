#ifndef BASECOUNTERATTACK_H
#define BASECOUNTERATTACK_H

#include <iostream>
#include "../Unit.h"

template <class Type>
class Unit;

template <class Type>
class BaseCounterAttack {
    public:
        BaseCounterAttack();
        virtual ~BaseCounterAttack();

        virtual void counterAttack(Unit<Type>* attacker, Unit<Type>* enemy);
};

#endif // BASECOUNTERATTACK_H
