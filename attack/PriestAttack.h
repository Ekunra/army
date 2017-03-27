#ifndef PRIESTATTACK_H
#define PRIESTATTACK_H

#include "BaseAttack.h"

template <class Type>
class PriestAttack : public BaseAttack<Type> {
    public:
        PriestAttack();
        virtual ~PriestAttack();

        virtual void attack(Unit<Type>* attacker, Unit<Type>* enemy);
};

#endif // PRIESTATTACK_H
