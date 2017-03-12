#ifndef WEREWOLFCOUNTERATTACK_H
#define WEREWOLFCOUNTERATTACK_H

#include <iostream>
#include "BaseCounterAttack.h"

// template <class Type>
// class Unit;

template <class Type>
class WerewolfCounterAttack : public BaseCounterAttack<Type> {
    public:
        WerewolfCounterAttack();
        virtual ~WerewolfCounterAttack();

        virtual void counterAttack(Unit<Type>* attacker, Unit<Type>* enemy);
};

#endif // WEREWOLFCOUNTERATTACK_H
