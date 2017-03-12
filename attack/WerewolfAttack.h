#ifndef WEREWOLFATTACK_H
#define WEREWOLFATTACK_H

#include <iostream>
#include "BaseAttack.h"

template <class Type>
class WerewolfAttack : public BaseAttack<Type> {
    public:
        WerewolfAttack();
        virtual ~WerewolfAttack();

        virtual void attack(Unit<Type>* attacker, Unit<Type>* enemy);
};

#endif // WEREWOLFATTACK_H
