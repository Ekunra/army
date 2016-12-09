#ifndef BASECOUNTERATTACK_H
#define BASECOUNTERATTACK_H

#include <iostream>
#include "../Unit.h"

class Unit;

class BaseCounterAttack {
    public:
        BaseCounterAttack();
        virtual ~BaseCounterAttack();

        virtual void counterAttack(Unit* attacker, Unit* enemy);
};

#endif // BASECOUNTERATTACK_H
