#ifndef VAMPIRECOUNTERATTACK_H
#define VAMPIRECOUNTERATTACK_H

#include <iostream>
#include "BaseCounterAttack.h"

// template <class Type>
// class Unit;

template <class Type>
class VampireCounterAttack : public BaseCounterAttack<Type> {
    public:
        VampireCounterAttack();
        virtual ~VampireCounterAttack();

        virtual void counterAttack(Unit<Type>* attacker, Unit<Type>* enemy);
};

#endif // VAMPIRECOUNTERATTACK_H
