#ifndef BASEATTACK_H
#define BASEATTACK_H

#include <iostream>
#include "../Unit.h"

class Unit;

class BaseAttack {
    public:
        BaseAttack();
        virtual ~BaseAttack();

        virtual void attack(Unit* attacker, Unit* enemy);
};

#endif // BASEATTACK_H
