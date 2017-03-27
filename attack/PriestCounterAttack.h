#ifndef PRIESTCOUNTERATTACK_H
#define PRIESTCOUNTERATTACK_H

#include <iostream>
#include "BaseCounterAttack.h"

template <class Type>
class PriestCounterAttack : public BaseCounterAttack<Type> {
    public:
        PriestCounterAttack();
        virtual ~PriestCounterAttack();

        virtual void counterAttack(Unit<Type>* attacker, Unit<Type>* enemy);
};

#endif // PRIESTCOUNTERATTACK_H
