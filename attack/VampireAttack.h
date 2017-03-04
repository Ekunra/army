#ifndef VAMPIREATTACK_H
#define VAMPIREATTACK_H

#include <iostream>
#include "BaseAttack.h"

template <class Type>
class VampireAttack : public BaseAttack<Type> {
    public:
        VampireAttack();
        virtual ~VampireAttack();

        virtual void attack(Unit<Type>* attacker, Unit<Type>* enemy);
};

#endif // VAMPIREATTACK_H
